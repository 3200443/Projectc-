#ifndef JEU_MATHEUX_H
#define JEU_MATHEUX_H


class Jeu_Matheux
{
public:
    void on_go_jeu_calcul_clicked();

    void on_Jeu_4_clicked();

    void Fin_jeu_calcul();

    void on_valider_calcul1_clicked();

    void on_valider_calcul2_clicked();

    void on_valider_calcul3_clicked();

    void on_valider_calcul4_clicked();

    void on_valider_calcul5_clicked();

private :
    int  _resultat_equa1;
    int  _resultat_equa2;
    int  _resultat_equa3;
    int  _resultat_equa4;
    int  _resultat_equa5;

    int _cmt_pts;
    int _cmt;
};

#endif // JEU_MATHEUX_H
