#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cassert>

#define NB_PAYS_MAX 20


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->cnbpays->setValidator(new QIntValidator(2,20,this));
    ui->spinBox->setRange(2,NB_PAYS_MAX);
    ui->spinBox->setValue(2);
    ui->cnomj->setText("Joueur");
    ui->stackedWidget->setCurrentIndex(0);
    ui->cResultat->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    for(auto iter : _monde)
        delete iter;
    delete ui;
}

void MainWindow::on_boption_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_bretour_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::inipop()
{
    if(ui->rfacile->isChecked())
    {
        _popularite[0] = 45;
        for(int i = 1; i < 5; i++)
            _popularite[i] = 1.2;
    }else if(ui->rnormal->isChecked())
    {
        _popularite[0] = 30;
        for(int i = 1; i < 5; i++)
            _popularite[i] = 1;
    }else
    {
        _popularite[0] = 10;
        for(int i = 1; i < 5; i++)
            _popularite[i] = 0.8;
    }
}

void MainWindow::on_bjouer_clicked()
{
    std::set<Pays> temp;
    Pays* p;
    _nbpays = ui->spinBox->text().toInt();
    assert(_nbpays>1);
    assert(_nbpays <21);
    do
    {
        switch(rand()%2)
        {
            case(0):
                p = new Federation;
                break;
            case(1):
                p = new NFederation;
                break;
            default:
                QMessageBox::information(0,"ERREUR","Erreur création dans le _monde");
        }
        if( !temp.insert(*p).second )
        {
            delete p;
        }else
        {
            _monde.push_back(p);
        }
    }while(_monde.size()<(unsigned)_nbpays);

    inipop();

    _nomj = ui->cnomj->text().toStdString();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_bretour2_clicked()
{
    _monde.clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::mode1(){
    _sondages = 2;
    _tour = 0;
    _nomj = ui->cnomj->text().toStdString();

    ui->tabWidget->setCurrentIndex(0);
    ui->lsondage->setText(QString::number(_sondages));
    ui->progressBar->reset();


    // nb_tours = nb_pays
    for(auto& iter : _monde)
    {
        ui->listWidget->addItem(QString::fromStdString((*iter).get_nom()));
    }

   // Vérifications
   for(int i = 1; i < MAX_P; i++) {
       if(_popularite[i] > 1 ) _popularite[i] = 1;
       if(_popularite[i] < 0 ) _popularite[i] = 0;
    }
    ui->progressBar_2->setValue(_popularite[0]);
    ui->ljeunbj->setText(QString::fromStdString(_nomj));
    int temp = 0;
    for(auto& iter : _monde)
    {
        temp += iter->get_nbhab();
    }
    ui->ljpopmond->setText(QString::number(temp));
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_btabnoteafficher_clicked()
{
    ui->ctnote->setText(_notes);
}

void MainWindow::on_btnotemodifier_clicked()
{
    _notes = ui->ctnote->toPlainText();
}

void MainWindow::on_babandonner_clicked()
{
    _notes ="";
    for(auto iter : _monde)
        delete iter;
    ui->listWidget->clear();
    _monde.clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    ui->bVoyager->setEnabled(false);
    ui->bsonder->setEnabled(false);
    mode1();
}

void MainWindow::on_listWidget_itemSelectionChanged()
{
    if(_nbpays > _tour)
    {
        for(auto& iter : _monde)
        {

            if(!(*iter).get_nom().compare(ui->listWidget->currentItem()->text().toStdString()))
            {
                ui->tjeu_2->setText(QString::fromStdString((*iter).get_basic()));
                return;
            }
        }
    }
}

void MainWindow::on_bVoyager_clicked()
{
    Pays* temp;
    ui->bVoyager->setEnabled(false);
    ui->bsonder->setEnabled(false);
    ui->progressBar->setValue((_tour+1)*100.0/_nbpays);
    if(_nbpays > _tour)
    {
        for(auto& iter : _monde)
        {

            if(!(*iter).get_nom().compare(ui->listWidget->currentItem()->text().toStdString()))
            {
                temp = iter;
                if(_nbpays-_tour > 1)
                    delete ui->listWidget->takeItem(ui->listWidget->currentRow());
                else
                    ui->listWidget->reset();
                break;
            }
        }
        _tour ++ ;
        //fin();
    }
}

void MainWindow::fin()
{
    QPalette *palette = new QPalette();
    if(_nbpays - _tour > 0)
    {
        ui->stackedWidget_2->setCurrentIndex(0);
    }
    else
    {
        if(resultat())
        {
            ui->cResultat->setText("VICTOIRE");
            ui->cResultat->setFont(QFont( "lucida", 20, QFont::Bold, true ));
            palette->setColor(QPalette::Text,Qt::green);
            palette->setColor(QPalette::Base,Qt::blue);
        }else
        {
            ui->cResultat->setText("PERDU");
            ui->cResultat->setFont(QFont( "lucida", 20, QFont::Bold, true ));
            palette->setColor(QPalette::Text,Qt::red);
            palette->setColor(QPalette::Base,Qt::black);
        }
        ui->cResultat->setAlignment(Qt::AlignHCenter);
        ui->cResultat->setPalette(*palette);
        ui->stackedWidget_2->setCurrentIndex(1);
    }
}

void MainWindow::on_bfin_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

bool MainWindow::resultat()
{
    return 0; //TODO:PLACEHOLDER;
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if(_sondages > 0 && ! ui->bVoyager->isEnabled())
        ui->bsonder->setEnabled(true);
    ui->bVoyager->setEnabled(true);
}

void MainWindow::on_bsonder_clicked()
{
    ui->bsonder->setDisabled(true);
    if(_sondages > 0)
    {
        for(auto& iter : _monde)
        {

            if(!(*iter).get_nom().compare(ui->listWidget->currentItem()->text().toStdString()))
            {
                ui->tjeu_2->setText(QString::fromStdString((*iter).display()));
                break;
            }
        }
        _sondages --;
        ui->lsondage->setText(QString::number(_sondages));
    }
}
