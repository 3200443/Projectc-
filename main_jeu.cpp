#include <QApplication>
#include "jeu.h"


int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    Jeu w;
    w.show();
    w.showFullScreen();

    srand(time(NULL));

    return a.exec();

}







//    QApplication app(argc, argv);

//    QWidget fenetre;
//    fenetre.setFixedSize(400, 200);


//    QPushButton bouton1("YOLO", &fenetre);
//    bouton1.setText("Boutton 1 ");
//    bouton1.setToolTip("Texte d'aide");
//    bouton1.setFont(QFont("Comic Sans MS", 20, QFont::Bold, true));

//    bouton1.move(60, 50);
//    //bouton1.setGeometry(50, 50, 20, 20);

//    QPushButton bouton2("YOLO", &fenetre);
//    bouton2.setText("Quitter ");
//    bouton2.setToolTip("Texte d'aide");
//    bouton2.setFont(QFont("Comic Sans MS", 20, QFont::Bold, true));
//    bouton2.move(100,100);
//    QObject::connect(&bouton2, SIGNAL(clicked()), qApp, SLOT(quit()));


//    QLCDNumber m_lcd(&fenetre);
//    m_lcd.setSegmentStyle(QLCDNumber::Flat);



//    fenetre.show();
//    bouton1.show();
//    bouton2.show();


//    return app.exec();
// }
