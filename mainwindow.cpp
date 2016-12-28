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


void MainWindow::on_bjouer_clicked()
{
    std::set<Pays> temp;
    Pays* p;
    _nbpays = ui->spinBox->text().toInt();
    assert(_nbpays>0);
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
                //std::cout<<"Erreur création dans le _monde"<<std::endl;
        }
        if( !temp.insert(*p).second )
        {
            delete p;
        }else
        {
            _monde.push_back(p);
        }
    }while(_monde.size()<(unsigned)_nbpays);


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



    ui->stackedWidget->setCurrentIndex(3);
}
/*


        // Affichage info pays      // Partie | nb_habitants | ?
        std::cout << iter.display() << std::endl;

        // Event
        int x = rand()%2;
        if (x) event(popularite, iter, monde);


        // Action
        while(!verrou)
        {
            switch(action(sondages))
            {
                case 1:
                    sondages--;
                    //iter.sondage(monde);	// Pays = virtual TODO: redefibir la fonction sondage en consequence
                    break;

                case 2:
                    note(notes);
                    break;

                case 3:
                    afficherNote(notes);
                    break;
                default: std::cout << " Aucune action" << std::endl;
                    verrou = true;
                    break;
            }
        }
    }
    //TODO: FIN DE PARTIE ICI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!       <---------------------
}
*/

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
    mode1();
}

void MainWindow::on_listWidget_itemSelectionChanged()
{
    ui->bVoyager->setEnabled(true);
    //std::cout << ui->listWidget->row(ui->listWidget->currentItem()) <<std::endl;
    //std::cout << ui->listWidget->currentItem()->text().toStdString() << std::endl;
    for(auto& iter : _monde)
    {

        if(!(*iter).get_nom().compare(ui->listWidget->currentItem()->text().toStdString()))
        {
            //std::cout << (*iter).get_nom() << (*iter).get_basic()<<std::endl;
            ui->tjeu_2->setText(QString::fromStdString((*iter).get_basic()));
            return;
        }
    }
    //std::cout<<"fail"<<std::endl;
}

void MainWindow::on_bVoyager_clicked()
{
    Pays* temp;
    ui->progressBar->setValue(ui->progressBar->value()+1.0/(_nbpays/100.0));
    if(ui->listWidget->count() > 0)
    {
        for(auto& iter : _monde)
        {

            if(!(*iter).get_nom().compare(ui->listWidget->currentItem()->text().toStdString()))
            {
                temp = iter;
                if(ui->listWidget->count() > 1)
                    delete ui->listWidget->takeItem(ui->listWidget->currentRow());
                else
                    ui->listWidget->clear();
                //std::cout << "hey" << std::endl;
                break;
            }

        }
    }
}
