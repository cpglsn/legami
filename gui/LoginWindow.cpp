#include "LoginWindow.h"
#include "../ui_loginwindow.h"
#include "../logica/Legami.h"
#include "../logica/User.h"

#include <QDebug>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
    , m_legami(new Legami())
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);

    // register button is disabled unless user checks the checkbox
    ui->registerButton->setEnabled(false);

    // connect actions
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(onAccepted()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(onRejected()));

    // connect checkbox
    connect(ui->newAccountCheckBox, SIGNAL(toggled(bool)), this, SLOT(onCheckboxToggled(bool)));

    // connect register button
    connect(ui->registerButton, SIGNAL(clicked()), this, SLOT(onRegisterClicked()));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::onAccepted()
{
    qDebug("accepted");
    if (m_legami->login(ui->loginLineEdit->text().toStdString(), ui->passwordLineEdit->text().toStdString())) {
        // create main window with user pointer
    } else {
        QMessageBox::critical(this, "Login ERROR!", "Utente inesistente");

        // clear information
        ui->loginLineEdit->clear();
        ui->passwordLineEdit->clear();
    }
}

void LoginWindow::onCheckboxToggled(bool toggled)
{
    ui->registerButton->setEnabled(toggled);
}

void LoginWindow::onRegisterClicked()
{
    // register new account
    if (!ui->loginLineEdit->text().isEmpty() && !ui->passwordLineEdit->text().isEmpty()) {
        User user(ui->loginLineEdit->text().toStdString(), ui->passwordLineEdit->text().toStdString());

        if (m_legami->registra(&user)) {
            QMessageBox::information(this, "Info", "Account creato");

            // clear information
            ui->loginLineEdit->clear();
            ui->passwordLineEdit->clear();
        }
    } else {
        // empty fields, ERROR
        QMessageBox::warning(this, "Errore", "Campi dati invalidi");
    }
}

void LoginWindow::onRejected()
{
    close();
}
