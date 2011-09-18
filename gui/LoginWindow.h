#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QtGui/QWidget>

namespace Ui {
    class LoginWindow;
}

class Legami;

class LoginWindow : public QWidget
{
    Q_OBJECT
public:
    LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void onAccepted();
    void onCheckboxToggled(bool toggled);
    void onRegisterClicked();
    void onRejected();

private:
    Ui::LoginWindow *ui;
    Legami *m_legami;
};


#endif  // LOGIN_WINDOW_H
