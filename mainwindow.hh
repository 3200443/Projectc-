#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "Parti.hh"
#include "Pays.hh"
#include "Federation.hh"
#include "NFederation.hh"
#include "Labyrinthe.hh"

#include <QListWidget>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
private slots:

    void on_boption_clicked();

    void on_bretour_clicked();

    void on_bjouer_clicked();

    void on_bretour2_clicked();

    void on_btabnoteafficher_clicked();

    void on_btnotemodifier_clicked();

    void on_babandonner_clicked();

    void on_pushButton_clicked();


    void on_listWidget_itemSelectionChanged();

    void on_bVoyager_clicked();

    void on_bfin_clicked();

    void on_listWidget_itemClicked();

    void on_bsonder_clicked();

    void on_bfinminijeu_clicked();

    void on_bporte1_clicked();

    void on_bporte2_clicked();

    void on_bporte3_clicked();

    void on_blabarriere_clicked();

    void on_bquit3_clicked();

    void on_blababa_clicked();

private:
    Ui::MainWindow *ui;

    int _nbpays;

    int _tour; //note beacause count() is really unreliable

    std::string _nomj;

    std::vector<Pays*> _monde;

    int _popularite[4];

    QString _notes;

    short _sondages;

    Labyrinthe * _l;

    int _difficulte;

    void mode1();

    void fin();

    bool resultat();

    void inipop();

    int gerer_lab(int i);

    void fin_minijeu(bool r);

    void event();

    void creer_lab();
};

#endif // MAINWINDOW_HH
