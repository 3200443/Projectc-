#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH
#include "Parti.hh"
#include "Pays.hh"
#include "Federation.hh"
#include "NFederation.hh"
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

private:
    Ui::MainWindow *ui;

    void mode1();

    int _nbpays;

    std::string _nomj;

    std::vector<Pays*> _monde;

    float _popularite[5];

    QString _notes;

    short _sondages;
};

#endif // MAINWINDOW_HH
