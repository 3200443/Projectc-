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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cnbpays->setValidator(new QIntValidator(2,20,this));
    ui->cnbpays->setText("2");
    ui->cnomj->setText("Joueur");
}

MainWindow::~MainWindow()
{
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
    _nbpays = ui->cnbpays->text().toInt();
    assert(_nbpays>0);
    assert(_nbpays <21);

    while(_monde.size() < (unsigned)_nbpays){
            switch(rand()%2)
            {
                case(0):
                    _monde.insert(Federation());//std::cout << 0 <<std::endl;	// Sa bloque ici :/
                    break;
                case(1):
                    _monde.insert(NFederation());//std::cout << 1 <<std::endl;
                    break;
                default:
                    QMessageBox::information(0,"ERREUR","Erreur création dans le _monde");
                    //std::cout<<"Erreur création dans le _monde"<<std::endl;
            }
        }
    if(ui->rfacile->isChecked())
    {
        popularite[0] = 45;
        for(int i = 1; i < 5; i++)
            popularite[i] = 1.2;
    }else if(ui->rnormal->isChecked())
    {
        popularite[0] = 30;
        for(int i = 1; i < 5; i++)
            popularite[i] = 1;
    }else
    {
        popularite[0] = 10;
        for(int i = 1; i < 5; i++)
            popularite[i] = 0.8;
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
    short sondages = 2;

    std::ostringstream notes;
    notes.str("");


    std::cout<<"Debut de la partie"<<std::endl;

    std::cout << "Entrer votre nom"<<std::endl;
    std::cin >> nom_user;
    std::cout << std::endl<<std::endl;
    // nb_tours = nb_pays
    for(auto& iter : monde)
    {

        // Vérifications
        for(int i = 1; i < MAX_P; i++) {
            if(popularite[i] > 1 ) popularite[i] = 1;
            if(popularite[i] < 0 ) popularite[i] = 0;

        }

        // Affichage popularité
        std::cout << "Ta popularité est de : " << popularite[0] << " % " << std::endl;

/* // POURQUOI GETNOM_P SA GALERE SERIEUX
        for(int i = 0; i < MAX_P; i++){
            std::cout << " Ta popularité dans le partie " <<  get_nom_p[i]  << " est de : " << popularite[i+1] *100 << " % " << std::endl;
        }
*/
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
