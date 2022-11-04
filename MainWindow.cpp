#include "MainWindow.h"

#include <QtCore/QStandardPaths>
#include <QtCore/QUrlQuery>
#include <QtGui/QDesktopServices>
#include <QtGui/QScreen>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QScrollBar>

MainWindow::MainWindow(QWidget* p) : QWidget(parent) {
	setupUi(this);

}

Qstring MainWindow::readUsername(QString username) {
	user = username;
	return user;
}

Qstring MainWindow::readPassword(QString password) {
	pass = password;
	return pass;
}

void MainWindow::on_qaCreateAccount_triggered() {
	//open CreateAccount page
}

void MainWindow::on_qaLogin_triggered() {
	//open Log In page 
}