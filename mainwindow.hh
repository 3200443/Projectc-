#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH
#include "Parti.hh"
#include "Pays.hh"
#include "Federation.hh"
#include "NFederation.hh"

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

private:
    Ui::MainWindow *ui;

    void mode1();

    int _nbpays;

    std::string _nomj;

    std::set<Pays> _monde;

    float popularite[5];
};

#endif // MAINWINDOW_HH
