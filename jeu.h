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
    void on_bvalider_jeu1_clicked();
    void on_Jeu_1_clicked();

    void on_bvalider_jeu2_clicked();

    void on_bvalider_jeu2_valeur_clicked();

    void on_next_jeu2_clicked();

    void on_Jeu_2_clicked();

    void on_Jeu_3_clicked();

    void on_next_jeu3_clicked();

private:
    Ui::Jeu *ui;
    float _popularite[5];
    int _val_rand;
    int _cmt_jeu2;
    int _score_jeu2;
    bool _res = false;
};

#endif // JEU_H
