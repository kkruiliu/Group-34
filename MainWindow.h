#pragma once

#ifndef BWB_MAINWINDOW_H_
#define BWB_MAINWINDOW_H_

#include <QtWidgets/QMainWindow>
#include <string>

#include "ui_MainWindow.h"

class Account; 
class CreateAccount;  

class MainWindow : public QMainWindow {

private:
	Q_OBJECT
	Q_DISABLE_COPY(MainWindow)
	Ui::MainWindow ui;

public:
	MainWindow(QWidget* parent);
	Qstring readUsername(QString username); //read username inputted in username box
	Qstring readPassword(QString password); //read password inputted in password box

//going to different pages 
public slots:
	void on_qaCreateAccount_triggered();   //action for going to the Create Account page
	void on_qaLogin_triggered();           //action for going to the Login/Account page 

}

#endif
