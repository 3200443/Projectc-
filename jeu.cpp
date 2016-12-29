#include "jeu.h"
#include "ui_jeu.h"

#include <QMessageBox>
// QMessageBox::information(0,"=====","Valider");

Jeu::Jeu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Jeu)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
}

Jeu::~Jeu()
{
    delete ui;
}


void Jeu::on_bvalider_jeu1_clicked()
{
    //QMessageBox::information(0,"=====","Valider");

    if(ui->radioButton_5->isChecked()){
        _popularite[0] = _popularite[0] + 5;
        ui->Resultat_affichage->setText("C'est bien le bon résultat ! +5 % dans la popularité générale ! ");
    }else{
        ui->Resultat_affichage->setText("Raté ! La réponse était le pommeau de douche ! C'est le seul objet que tu ne trouveras pas au collège ! ");
    }

    ui->bvalider_jeu1->setEnabled(false);

}


void Jeu::on_next_jeu2_clicked()
{
    // A remplacer en conséquence !!!!
    ui->stackedWidget->setCurrentIndex(2);
}

void Jeu::on_Jeu_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Jeu::on_bvalider_jeu2_clicked()
{

    srand(time(NULL));
    _cmt_jeu2 = 0;
    _val_rand = rand()%100;
    //ui->coups_restants->isReadOnly();

    if(ui->radioButton_8->isChecked()){
        _cmt_jeu2 = 10;
        _score_jeu2 = 5;

    }else if(ui->radioButton_9->isChecked()){
        _cmt_jeu2 = 7;
        _score_jeu2 = 7;

    }else if(ui->radioButton_10->isChecked()){
        _cmt_jeu2 = 5;
        _score_jeu2 = 10;

    }
    ui->radioButton_8->setEnabled(false);
    ui->radioButton_9->setEnabled(false);
    ui->radioButton_10->setEnabled(false);
    ui->bvalider_jeu2->setEnabled(false);

    QString coup = QString("%1").arg(_cmt_jeu2);
    ui->coups_restants->setText(coup);

   /* QString status = QString("val =  %1").arg(_val_rand);
    QMessageBox::information(0,"=====",status); */
}


void Jeu::on_bvalider_jeu2_valeur_clicked()
{

    if(_cmt_jeu2 > 0){
        int reponse =  ui->spin_reponse->value();

        if(reponse < _val_rand){
             ui->conseil->setText("Il faut un nombre plus grand !");
        }else if(reponse > _val_rand){
             ui->conseil->setText("Il faut un nombre plus petit !");
        }else{
             ui->conseil->setText("Nombre trouvé !");
             _cmt_jeu2 =1;
             _res = true;
        }
        _cmt_jeu2--;
        QString coup = QString("%1").arg(_cmt_jeu2);
         ui->coups_restants->setText(coup);
     }
    if(_cmt_jeu2 == 0){
         QString reponse = QString("%1").arg(_val_rand);
         ui->reponse->setText(reponse);

         ui->bvalider_jeu2_valeur->setEnabled(false);
    }
    if(_res == true)
     _popularite[5] += _score_jeu2;
    // Si on met cette ligne directement dans le "else" gagnant <=> beug d'affichage du resultat -> plsueiurs valeurs chelous

}


void Jeu::on_Jeu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Jeu::on_Jeu_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Jeu::on_next_jeu3_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}
