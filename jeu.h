#ifndef JEU_H
#define JEU_H

#include <QMainWindow>

namespace Ui {
class Jeu;
}

class Jeu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Jeu(QWidget *parent = 0);
    ~Jeu();

private slots:


    void on_bvalider_jeu2_clicked();

    void on_bvalider_jeu2_valeur_clicked();

    void on_Jeu_2_clicked();

    void on_Jeu_3_clicked();

    void on_next_jeu3_clicked();

    void on_go_timer_clicked();

    void Jeu_button();

    void chronometre();

    void Calcul_pop_jeu3();

    void  Action_jeu_clic();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_next_jeu3_2_clicked();
    void on_go_jeu_calcul_clicked();

    void on_Jeu_4_clicked();

    void Fin_jeu_calcul();

    void on_valider_calcul1_clicked();

    void on_valider_calcul2_clicked();

    void on_valider_calcul3_clicked();

    void on_valider_calcul4_clicked();

    void on_valider_calcul5_clicked();

private:
    Ui::Jeu *ui;
    float _popularite[5];
    int _val_rand;
    int _cmt_jeu2;
    int _score_jeu2;

// ======= Jeu clic ========
    int _cmt_jeu3;
    float _cmt_chrono;
    QTimer *_m_timer;
    QTimer *_ch_timer;

// ====== Jeu calcul ======
    int  _resultat_equa1;
    int  _resultat_equa2;
    int  _resultat_equa3;
    int  _resultat_equa4;
    int  _resultat_equa5;

    int _cmt_pts;
    int _cmt;

};

#endif // JEU_H
