#include "jeu.h"
#include "ui_jeu.h"


#include <QTimer>
#include <QMessageBox>

Jeu::Jeu(QWidget *parent) : QMainWindow(parent), ui(new Ui::Jeu){
    //srand(time(NULL));

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    _jeu_logicos = new Logicos(difficulte);  // facile = 0, normale = 1; difficile = 2;
    _jeu_guerre = new Guerre();
    _jeu_calcul = new Calcul();


    int difficulte = 2;
}

Jeu::~Jeu()
{
    delete ui;
}


// ======= Jeu Logicos =========

void Jeu::on_bvalider_jeu2_valeur_clicked()
{

    if(_jeu_logicos->get_cmt() > 0){

        _jeu_logicos->set_reponse(ui->spin_reponse->value());

        switch (_jeu_logicos->compare()){
            case 0 : ui->conseil->setText("Nombre trouvé !");
                    break;
            case 1 : ui->conseil->setText("Il faut un nombre plus grand !");
                    break;
            case 2 : ui->conseil->setText("Il faut un nombre plus petit !");
                    break;
        }

     }

        QString coup = QString("%1").arg(_jeu_logicos->get_cmt());
        ui->coups_restants->setText(coup);

    if(_jeu_logicos->get_cmt() == 0){
        ui->bvalider_jeu2_valeur->setEnabled(false);

         QString reponse = QString("%1").arg(_jeu_logicos->get_val_rand());
         ui->reponse->setText(reponse);


         if(_jeu_logicos->get_reussi() == true){

             ui->resul_pop_2->setText(" Vous avez gagnez, +5 points dans la popularite du parti Logicos ");
             _jeu_logicos->set_score_jeu();

         }else{
              ui->resul_pop_2->setText(" Vous avez perdu, pas de points dans la popularite du parti Logicos ");
         }
    }

}



void Jeu::on_next_jeu3_clicked()    // Bouton fin du jeu Logicos
{
    _popularite[2] += _jeu_logicos->get_score_jeu();    // 0 si perdu (par defaut)  |   +5pts sinon
    ui->stackedWidget->setCurrentIndex(2);
}

// ======= Fin Jeu Logicos =========




// ====== Table de page du début, delete par la suite ======

void Jeu::on_Jeu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Jeu::on_Jeu_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Jeu::on_Jeu_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


// ====== Boutons retours aux menu pdt le jeu ======
void Jeu::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Jeu::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Jeu::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



// ======== Jeu Guerre ========

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


    QString nb_clic = QString("%1").arg(_jeu_guerre->get_cmt());
    ui->nb_clic->setText(nb_clic);


    switch(_jeu_guerre->gene_val_rand()) {

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
    ui->lcdNumber->display(_jeu_guerre->increment_cmt_chrono());
}


void Jeu::on_go_timer_clicked()
{
    ui->go_timer->setEnabled(false);
    _m_timer = new QTimer(this);
    connect(_m_timer, SIGNAL(timeout()), this, SLOT(Jeu_button()));
    connect(_m_timer, SIGNAL(timeout()), this, SLOT(chronometre()));
    _m_timer->start(500);

}

void Jeu::Calcul_pop_jeu3(){

    _jeu_guerre->set_temps_final(ui->lcdNumber->value());

    if(_jeu_guerre->get_temps_final() <= 15 ){

        ui->Resultat_3->setText("Temps inferieur a 15 s : popularite parti agressif + 10 points");
        _jeu_guerre->set_score_jeu(10);
        //_popularite[1] += 10;

    }else if(15 < _jeu_guerre->get_temps_final() && _jeu_guerre->get_temps_final() < 30){
        ui->Resultat_3->setText("Temps compris entre 15 et 30 s :popularite parti agressif + 5 points");
        _jeu_guerre->set_score_jeu(5);
       // _popularite[1] += 5;

    }else{
        ui->Resultat_3->setText("Temps supérieur a 30 s : pas de points gagnes pour le parti agressif");
    }

}

void Jeu::Action_jeu_clic(){
    _jeu_guerre->increment_cmt();

    if(_jeu_guerre->get_cmt() >= 10){
        _m_timer->stop();
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
    _popularite[1] = _jeu_guerre->get_score_jeu();
    ui->stackedWidget->setCurrentIndex(3);
}

// =========== Fin Jeu Guerre ===============




// ============== Jeu calcul =============

void Jeu::on_go_jeu_calcul_clicked()
{
    ui->go_jeu_calcul->setEnabled(false);

    ui->valider_calcul1->setEnabled(true);
    ui->valider_calcul2->setEnabled(true);
    ui->valider_calcul3->setEnabled(true);
    ui->valider_calcul4->setEnabled(true);
    ui->valider_calcul5->setEnabled(true);

    ui->res_calcul1->setMaximum(1000);
    ui->res_calcul2->setMaximum(1000);
    ui->res_calcul3->setMaximum(1000);
    ui->res_calcul4->setMaximum(1000);
    ui->res_calcul5->setMaximum(1000);


    QString calc1 = QString (" %1 x %2 ").arg(_jeu_calcul->get_val1_equa1()).arg(_jeu_calcul->get_val2_equa1());
    ui->calcul1->setText(calc1);

    QString calc2 = QString (" %1 x %2 ").arg(_jeu_calcul->get_val1_equa2()).arg(_jeu_calcul->get_val2_equa2());
    ui->calcul2->setText(calc2);

    QString calc3 = QString (" %1 x %2 ").arg(_jeu_calcul->get_val1_equa3()).arg(_jeu_calcul->get_val2_equa3());
    ui->calcul3->setText(calc3);

    QString calc4 = QString (" %1 x %2 ").arg(_jeu_calcul->get_val1_equa4()).arg(_jeu_calcul->get_val2_equa4());
    ui->calcul4->setText(calc4);

    QString calc5 = QString (" %1 x %2 = ").arg(_jeu_calcul->get_val1_equa5()).arg(_jeu_calcul->get_val2_equa5());
    ui->calcul5->setText(calc5);
}


void Jeu::Fin_jeu_calcul(){
    QString resu_jeu_calc = QString ("Vous avez gagnez %1 points pour le parti Matheu").arg(_jeu_calcul->get_cmt_pts());
    ui->Resultat_4->setText(resu_jeu_calc);
}

void Jeu::on_valider_calcul1_clicked()
{
    ui->valider_calcul1->setEnabled(false);
    _jeu_calcul->increment_cmt();

    if(ui->res_calcul1->value() == _jeu_calcul->get_resultat_equa1()){
       _jeu_calcul->increment_cmt_pts();
        ui->valider_calcul1->setText("Bon resultat");
    }else{
        ui->valider_calcul1->setText("Mauvais resultat");
    }

    if(_jeu_calcul->get_cmt() == 5) Fin_jeu_calcul();
}

void Jeu::on_valider_calcul2_clicked()
{
    ui->valider_calcul2->setEnabled(false);
    _jeu_calcul->increment_cmt();

    if(ui->res_calcul2->value() == _jeu_calcul->get_resultat_equa2()){
        _jeu_calcul->increment_cmt_pts();
        ui->valider_calcul2->setText("Bon resultat");
    }else{
        ui->valider_calcul2->setText("Mauvais resultat");
    }

    if(_jeu_calcul->get_cmt() == 5) Fin_jeu_calcul();
}

void Jeu::on_valider_calcul3_clicked()
{
    ui->valider_calcul3->setEnabled(false);
    _jeu_calcul->increment_cmt();

    if(ui->res_calcul3->value() == _jeu_calcul->get_resultat_equa3()){
        _jeu_calcul->increment_cmt_pts();
        ui->valider_calcul3->setText("Bon resultat");
    }else{
        ui->valider_calcul3->setText("Mauvais resultat");
    }

    if(_jeu_calcul->get_cmt() == 5) Fin_jeu_calcul();
}

void Jeu::on_valider_calcul4_clicked()
{
    ui->valider_calcul4->setEnabled(false);
    _jeu_calcul->increment_cmt();

    if(ui->res_calcul4->value() == _jeu_calcul->get_resultat_equa4()){
        _jeu_calcul->increment_cmt_pts();
        ui->valider_calcul4->setText("Bon resultat");
    }else{
        ui->valider_calcul4->setText("Mauvais resultat");
    }

    if(_jeu_calcul->get_cmt() == 5) Fin_jeu_calcul();
}

void Jeu::on_valider_calcul5_clicked()
{
    ui->valider_calcul5->setEnabled(false);
    _jeu_calcul->increment_cmt();

    if(ui->res_calcul5->value() == _jeu_calcul->get_resultat_equa5()){
        _jeu_calcul->increment_cmt_pts();
        ui->valider_calcul5->setText("Bon resultat");
    }else{
        ui->valider_calcul5->setText("Mauvais resultat");
    }

    if(_jeu_calcul->get_cmt() == 5) Fin_jeu_calcul();
}


void Jeu::on_Resultat_4_destroyed()
{
    _popularite[3] += _jeu_calcul->get_cmt_pts();
}

