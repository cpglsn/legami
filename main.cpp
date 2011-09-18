#include <QtGui/QApplication>

#include "gui/LoginWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // faccio vedere il dialogo di login. Se accettato, mostro schermata principale
    LoginWindow w;
    w.show();

    return a.exec();
}
