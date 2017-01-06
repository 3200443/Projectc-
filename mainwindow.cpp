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

//#include "Labyrinthe.hh"

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
    ui->cfinminijeu->setReadOnly(true);
    ui->cfinminijeu->setAlignment(Qt::AlignHCenter);
    ui->cResultat->setAlignment(Qt::AlignHCenter);
    ui->Enonce_3->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    //for(auto iter : _monde)
        //delete iter;
    //delete _l;
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

void MainWindow::creer_lab()
{
    do
    {
        _l= new Labyrinthe(_difficulte);
        if(gerer_lab(-1) == 4)
        {
            delete _l;
        }
        else
            break;
        //std::cout << "essai"<<std::endl;
    }while(1);

}

void MainWindow::inipop()
{
    if(ui->rfacile->isChecked())
    {
        _difficulte = 0;
        for(int i = 0; i < 4; i++)
            _popularite[i] = 40;
    }else if(ui->rnormal->isChecked())
    {
        _difficulte = 1;
        for(int i = 0; i < 4; i++)
            _popularite[i] = 30;
    }else
    {
        _difficulte = 2;
        _popularite[0] = 10;
        for(int i = 0; i < 4; i++)
            _popularite[i] = 20;
    }
    creer_lab();
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
   // init logicos

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
    ui->listWidget->clear(); //TODO: clear() devrait suffir mais valgrind ne semble aps etre satisfait, a revoir
    for(auto iter : _monde)
        delete iter;
    _monde.clear();
    delete _l;
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
    ui->bVoyager->setEnabled(false);
    ui->bsonder->setEnabled(false);
    ui->progressBar->setValue((_tour+1)*100.0/_nbpays);
    if(_nbpays > _tour)
    {
        for(auto& iter : _monde)
        {

            if(!(*iter).get_nom().compare(ui->listWidget->currentItem()->text().toStdString()))
            {
                if(_nbpays-_tour > 1)
                    delete ui->listWidget->takeItem(ui->listWidget->currentRow());
                else
                    ui->listWidget->reset();
                break;
            }
        }
        _tour ++ ;
        event();
        //fin();
    }
}

void MainWindow::fin()
{
    QPalette *palette = new QPalette();
    if(_nbpays - _tour > 0)
    {
        ui->stackedWidget->setCurrentIndex(3);
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
        ui->cResultat->setPalette(*palette);
        ui->stackedWidget_2->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(3);
    }
    delete palette;
}

void MainWindow::on_bfin_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

bool MainWindow::resultat()
{
    int temp[4] = {0};
    float moy = 0;
    const std::string nom_p[MAX_P] = {"curieux","guerre","logicos","matheux"};
    for(auto & iterm : _monde)
    {
        for(auto & iterp : iterm->get_partis())
        {
            for(int i = 0; i < 4 ; i++)
            {
                if(iterp.first.get_nom().compare(nom_p[i]))
                    temp[i] += iterp.second;
            }
        }
    }
    for(int i = 0; i < 4; i++)
    {
        moy += temp[i]*_popularite[i];
    }
    if(moy/_)
    return 0; //TODO:PLACEHOLDER;
}

void MainWindow::on_listWidget_itemClicked()
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

int MainWindow::gerer_lab(int i)
{
    char temp;
    switch(i)
    {
        case -1:
            temp = _l->get_suivant(-1);
            break;
        case 0:
            temp = _l->get_suivant(0);
            break;
        case 1:
            temp = _l->get_suivant(1);
            break;
        case 2:
            temp = _l->get_suivant(2);
            break;
        case 3:
            temp = _l->get_precedent();
            break;
    }
    if(temp >= 10)
    {
        ui->blabarriere->setEnabled(false);
        if(temp == 14)
            return 4;
        temp -=10;
    }else
    {
        ui->blabarriere->setEnabled(true);
    }
    switch(temp)
    {
        case 0:
            ui->bporte1->setEnabled(false);
            ui->bporte2->setEnabled(false);
            ui->bporte3->setEnabled(false);
            return temp;
        case 1:
            ui->bporte1->setEnabled(true);
            ui->bporte2->setEnabled(false);
            ui->bporte3->setEnabled(false);
            return temp;
        case 2:
            ui->bporte1->setEnabled(true);
            ui->bporte2->setEnabled(true);
            ui->bporte3->setEnabled(false);
            return temp;
        case 3:
            ui->bporte1->setEnabled(true);
            ui->bporte2->setEnabled(true);
            ui->bporte3->setEnabled(true);
            return temp;
        case 4:
            //TODO: AJOUTER LA POPULARITE
            delete _l;
            creer_lab();
            fin_minijeu(true);
            return temp;
    }
    return temp;
}
void MainWindow::fin_minijeu(bool r)
{
    if(r)
        ui->cfinminijeu->setText("REUSSITE");
    else
        ui->cfinminijeu->setText("ECHEC");
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_bfinminijeu_clicked()
{
    fin();
}

void MainWindow::on_bporte1_clicked()
{
    gerer_lab(0);
}

void MainWindow::on_bporte2_clicked()
{
    gerer_lab(1);
}

void MainWindow::on_bporte3_clicked()
{
    gerer_lab(2);
}

void MainWindow::on_blabarriere_clicked()
{
    gerer_lab(3);
}

void MainWindow::event()
{
    int r = rand()%5;
    switch(r)
    {
        case 0:
            ui->stackedWidget->setCurrentIndex(4);
            break;
        case 1:
            ui->stackedWidget->setCurrentIndex(5);
            break;
        case 2:
            ui->stackedWidget->setCurrentIndex(6);
            break;
        case 3:
            ui->stackedWidget->setCurrentIndex(7);
            break;
        case 4:
            ui->stackedWidget->setCurrentIndex(8);
            break;
    }
}

void MainWindow::on_bquit3_clicked()
{
    for(auto iter : _monde)
        delete iter;
    delete _l;
}



void MainWindow::on_blababa_clicked()
{
    //TODO: POPULARITE
    delete _l;
    creer_lab();
    fin_minijeu(false);
}
