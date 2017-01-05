#include "jeu.h"
#include "ui_jeu.h"
#include "matheux.h"

#include <QTimer>
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
    static bool res = false;
    if(_cmt_jeu2 > 0){
        int reponse =  ui->spin_reponse->value();

        if(reponse < _val_rand){
             ui->conseil->setText("Il faut un nombre plus grand !");
        }else if(reponse > _val_rand){
             ui->conseil->setText("Il faut un nombre plus petit !");
        }else{
             ui->conseil->setText("Nombre trouvé !");
             _cmt_jeu2 =1;
             res = true;
        }
        _cmt_jeu2--;
        QString coup = QString("%1").arg(_cmt_jeu2);
         ui->coups_restants->setText(coup);
     }
    if(_cmt_jeu2 == 0){
         QString reponse = QString("%1").arg(_val_rand);
         ui->reponse->setText(reponse);

         ui->bvalider_jeu2_valeur->setEnabled(false);
         if(res == true){
             ui->resul_pop_2->setText(" Vous avez gagnez, +5 points dans la popularite du parti Matheu ");
          _popularite[5] += _score_jeu2;//################################################################################################################
         // Si on met cette ligne directement dans le "else" gagnant <=> beug d'affichage du resultat -> plsueiurs valeurs chelous
         }else{
              ui->resul_pop_2->setText(" Vous avez perdu, pas de points dans la popularite du parti Matheu ");
         }
    }

}


void Jeu::on_Jeu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Jeu::on_Jeu_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Jeu::on_next_jeu3_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void Jeu::Jeu_button(){

    ui->nb_clic->setText("0");

    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    ui->pushButton_13->setEnabled(false);




    int  x = rand()%5;

    QString val_x = QString("x = %1 et _cmt = %2").arg(x).arg(_cmt_jeu3);
    ui->Resultat_3->setText(val_x);

    QString nb_clic = QString("%1").arg(_cmt_jeu3);
    ui->nb_clic->setText(nb_clic);

    switch(x) {

    case 0 : ui->pushButton_5->setEnabled(true);
        break;
    case 1 : ui->pushButton_6->setEnabled(true);
        break;
    case 2 : ui->pushButton_7->setEnabled(true);
        break;
    case 3 : ui->pushButton_8->setEnabled(true);
        break;
    case 4 : ui->pushButton_9->setEnabled(true);
        break;
    case 5 : ui->pushButton_10->setEnabled(true);
        break;
    case 6 : ui->pushButton_11->setEnabled(true);
        break;
    case 7 : ui->pushButton_12->setEnabled(true);
        break;
    case 8 : ui->pushButton_13->setEnabled(true);
        break;
     default : ui->Resultat_3->setText("defaut");
        break;
    }
}

void Jeu::chronometre(){
    _cmt_chrono+=0.5;
    ui->lcdNumber->display(_cmt_chrono);
}



void Jeu::on_go_timer_clicked()
{

   ui->go_timer->setEnabled(false);
    _cmt_jeu3 = 0;
   _cmt_chrono = 0;
   _ch_timer = new QTimer(this);    // chronometre
   _m_timer = new QTimer(this);     // clic_bouttons
    connect(_m_timer, SIGNAL(timeout()), this, SLOT(Jeu_button()));
    connect(_m_timer, SIGNAL(timeout()), this, SLOT(chronometre()));
    _m_timer->start(500);
    _ch_timer->start(500);

}

void Jeu::Calcul_pop_jeu3(){
    int result_temps = ui->lcdNumber->value();

    if(result_temps <= 15 ){
        ui->Resultat_3->setText("Temps inferieur a 15 s : popularite parti agressif + 10 points");
        _popularite[1] += 10;//################################################################################################################
    }else if(15 < result_temps && result_temps < 30){
        ui->Resultat_3->setText("Temps compris entre 15 et 30 s :popularite parti agressif + 5 points");
        _popularite[1] += 5;//################################################################################################################
    }else{
        ui->Resultat_3->setText("Temps supérieur a 30 s : pas de points gagnes pour le parti agressif");
    }

}

void Jeu::Action_jeu_clic(){
    _cmt_jeu3++;
    if(_cmt_jeu3 == 10){
        _m_timer->stop();
        _ch_timer->stop();
        Calcul_pop_jeu3();
    }

}

void Jeu::on_pushButton_8_clicked()
{
    Action_jeu_clic();
     ui->pushButton_8->setEnabled(false);
}

void Jeu::on_pushButton_5_clicked()
{
    Action_jeu_clic();
    ui->pushButton_5->setEnabled(false);
}

void Jeu::on_pushButton_7_clicked()
{
    Action_jeu_clic();
    ui->pushButton_7->setEnabled(false);
}

void Jeu::on_pushButton_6_clicked()
{
    Action_jeu_clic();
     ui->pushButton_6->setEnabled(false);
}

void Jeu::on_pushButton_9_clicked()
{
    Action_jeu_clic();
     ui->pushButton_9->setEnabled(false);
}

void Jeu::on_pushButton_10_clicked()
{
    Action_jeu_clic();
    ui->pushButton_10->setEnabled(false);
}

void Jeu::on_pushButton_11_clicked()
{
    Action_jeu_clic();
    ui->pushButton_11->setEnabled(false);
}

void Jeu::on_pushButton_12_clicked()
{
    Action_jeu_clic();
    ui->pushButton_12->setEnabled(false);
}

void Jeu::on_pushButton_13_clicked()
{
   Action_jeu_clic();
   ui->pushButton_13->setEnabled(false);
}

void Jeu::on_next_jeu3_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Jeu::on_Jeu_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

// ============== Jeu calcul =============

void Jeu::on_go_jeu_calcul_clicked()
{
    ui->go_jeu_calcul->setEnabled(false);
    _cmt_pts = 0;
    _cmt = 0;

    ui->res_calcul1->setMaximum(1000);
    ui->res_calcul2->setMaximum(1000);
    ui->res_calcul3->setMaximum(1000);
    ui->res_calcul4->setMaximum(1000);
    ui->res_calcul5->setMaximum(1000);

    int  val1_equa1 = rand()%15+5;  // 5 - 20
    int  val2_equa1 = rand()%15+5;  // 5 - 20
    _resultat_equa1 = val1_equa1 * val2_equa1;

    QString calc1 = QString (" %1 x %2 ").arg(val1_equa1).arg(val2_equa1);
    ui->calcul1->setText(calc1);


    int  val1_equa2 = rand()%20+10; // 10 - 30
    int  val2_equa2 = rand()%20+10; // 10 - 30
    _resultat_equa2 = val1_equa2 * val2_equa2;

    QString calc2 = QString (" %1 x %2 ").arg(val1_equa2).arg(val2_equa2);
    ui->calcul2->setText(calc2);


    int  val1_equa3 = rand()%10+10; // 10 - 20
    int  val2_equa3 = rand()%30+10; // 10 - 40
    _resultat_equa3 = val1_equa3 * val2_equa3;

    QString calc3 = QString (" %1 x %2 ").arg(val1_equa3).arg(val2_equa3);
    ui->calcul3->setText(calc3);

    int  val1_equa4 = rand()%20;    // 0 - 20
    int  val2_equa4 = rand()%50;    // 0 - 50
    _resultat_equa4 = val1_equa4 * val2_equa4;

    QString calc4 = QString (" %1 x %2 ").arg(val1_equa4).arg(val2_equa4);
    ui->calcul4->setText(calc4);

    int  val1_equa5 = rand()%10;   // 0 - 10
    int  val2_equa5 = rand()%100;   // 0 - 100
    _resultat_equa5 = val1_equa5 * val2_equa5;

    QString calc5 = QString (" %1 x %2 = ").arg(val1_equa5).arg(val2_equa5);
    ui->calcul5->setText(calc5);
}


void Jeu::Fin_jeu_calcul(){

    QString resu_jeu_calc = QString ("Vous avez gagnez %1 points, vous gagner donc %1 points dans le parti Matheu").arg(_cmt_pts);
    ui->Resultat_4->setText(resu_jeu_calc);

    _popularite[3] += _cmt_pts;//################################################################################################################

}


void Jeu::on_valider_calcul1_clicked()
{
    ui->valider_calcul1->setEnabled(false);
   _cmt++;

    if(ui->res_calcul1->value() == _resultat_equa1){
        _cmt_pts++;
        ui->valider_calcul1->setText("Bon resultat");
    }else{
        ui->valider_calcul1->setText("Mauvais resultat");
    }

    if(_cmt == 5) Fin_jeu_calcul();
}

void Jeu::on_valider_calcul2_clicked()
{
    ui->valider_calcul2->setEnabled(false);
    _cmt++;

    if(ui->res_calcul2->value() == _resultat_equa2){
        _cmt_pts++;
        ui->valider_calcul2->setText("Bon resultat");
    }else{
        ui->valider_calcul2->setText("Mauvais resultat");
    }

    if(_cmt == 5) Fin_jeu_calcul();
}

void Jeu::on_valider_calcul3_clicked()
{
    ui->valider_calcul3->setEnabled(false);
    _cmt++;

    if(ui->res_calcul3->value() == _resultat_equa3){
        _cmt_pts++;
        ui->valider_calcul3->setText("Bon resultat");
    }else{
        ui->valider_calcul3->setText("Mauvais resultat");
    }

    if(_cmt == 5) Fin_jeu_calcul();
}

void Jeu::on_valider_calcul4_clicked()
{
    ui->valider_calcul4->setEnabled(false);
    _cmt++;

    if(ui->res_calcul4->value() == _resultat_equa4){
        _cmt_pts++;
        ui->valider_calcul4->setText("Bon resultat");
    }else{
        ui->valider_calcul4->setText("Mauvais resultat");
    }

    if(_cmt == 5) Fin_jeu_calcul();
}

void Jeu::on_valider_calcul5_clicked()
{
    ui->valider_calcul5->setEnabled(false);
    _cmt++;

    if(ui->res_calcul5->value() == _resultat_equa5){
        _cmt_pts++;
        ui->valider_calcul5->setText("Bon resultat");
    }else{
        ui->valider_calcul5->setText("Mauvais resultat");
    }

    if(_cmt == 5) Fin_jeu_calcul();
}
