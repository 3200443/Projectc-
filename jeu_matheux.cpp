#include "jeu_matheux.h"

#include <QTimer>
#include <QMessageBox>

void jeu_matheux::on_go_jeu_calcul_clicked()
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


void jeu_matheux::Fin_jeu_calcul(){

    QString resu_jeu_calc = QString ("Vous avez gagnez %1 points, vous gagner donc %1 points dans le parti Matheu").arg(_cmt_pts);
    ui->Resultat_4->setText(resu_jeu_calc);

    _popularite[3] += _cmt_pts;//################################################################################################################

}


void jeu_matheux::on_valider_calcul1_clicked()
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

void jeu_matheux::on_valider_calcul2_clicked()
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

void jeu_matheux::on_valider_calcul3_clicked()
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

void jeu_matheux::on_valider_calcul4_clicked()
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

void jeu_matheux::on_valider_calcul5_clicked()
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
