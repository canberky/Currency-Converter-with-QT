#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <QRegExp>
#include <QtGui>



//constructor of MainWindow class
//sets connections of buttons
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->USD,SIGNAL(released()),this,SLOT(pushPressed()));
    connect(ui->EUR,SIGNAL(released()),this,SLOT(pushPressed()));
    connect(ui->GBP,SIGNAL(released()),this,SLOT(pushPressed()));
    connect(ui->CNY,SIGNAL(released()),this,SLOT(pushPressed()));
}
//destructor of MainWindow class
MainWindow::~MainWindow()
{
    delete ui;
}

//finds the button whichis pressed and makes calculations according to that
void MainWindow::pushPressed()
{

    QPushButton * button = (QPushButton*)sender();
    if(button->text() == "USD"){
        manager = new QNetworkAccessManager(this) ;

             connect(manager, SIGNAL(finished(QNetworkReply *)),this, SLOT(replyFinishedUSD(QNetworkReply *)));

             // Initiate retrieval of  the data from the web page.
             // When completed, slot replyFinished will be called.
             manager->get(QNetworkRequest(QUrl("https://api.fixer.io/latest?base=TRY&symbols=USD")));
    }
    if(button->text() == "EUR"){
        manager = new QNetworkAccessManager(this) ;

             connect(manager, SIGNAL(finished(QNetworkReply *)),this, SLOT(replyFinishedEUR(QNetworkReply *)));

             // Initiate retrieval of  the data from the web page.
             // When completed, slot replyFinished will be called.
             manager->get(QNetworkRequest(QUrl("https://api.fixer.io/latest?base=TRY&symbols=EUR")));
    }
    if(button->text() == "GBP"){
        manager = new QNetworkAccessManager(this) ;

             connect(manager, SIGNAL(finished(QNetworkReply *)),this, SLOT(replyFinishedGBP(QNetworkReply *)));

             // Initiate retrieval of  the data from the web page.
             // When completed, slot replyFinished will be called.
             manager->get(QNetworkRequest(QUrl("https://api.fixer.io/latest?base=TRY&symbols=GBP")));
    }
    if(button->text() == "CNY"){
        manager = new QNetworkAccessManager(this) ;

             connect(manager, SIGNAL(finished(QNetworkReply *)),this, SLOT(replyFinishedCNY(QNetworkReply *)));

             // Initiate retrieval of  the data from the web page.
             // When completed, slot replyFinished will be called.
             manager->get(QNetworkRequest(QUrl("https://api.fixer.io/latest?base=TRY&symbols=CNY")));
    }

}
//gets the change rate of TL/USD value from given url, reads it with regex and makes the necessary calculations
void MainWindow::replyFinishedUSD(QNetworkReply *reply)  {

    QStringList pieces = ui->TLInput->text().split( "T" );
    QString neededWord = pieces.value( 0 );
    double value = neededWord.toDouble();

    QString str ;
    int pos = 0;

    // read the data fetched from the web site
    QString data = (QString) reply->readAll();

    // use pattern matching to extract the rate
    QRegExp rx("(\\d+\\.\\d+)");

    if ( rx.indexIn(data, pos) != -1 ) {
    str = QString ("")+ rx.cap(1)+(" TL/USD");    // rate found
    }
    else {
    str = QString("Error") ;
    }

    // set the text of the label
    ui->RateResult->setText(str) ;

    double result = value*rx.cap(1).toDouble();

    QString res;
    //precision can be changed below code section
    res = QString::number(result,'f',2) + " USD";
    ui->AmountResult->setText(res);

    QString tli;
    //precision can be changed below code section
    tli = QString::number(value,'g',neededWord.length()) + " TL";
    ui->TLInput->setText(tli);

}
//gets the change rate of TL/EUR value from given url, reads it with regex and makes the necessary calculations
void MainWindow::replyFinishedEUR(QNetworkReply *reply)  {

    QStringList pieces = ui->TLInput->text().split( "T" );
    QString neededWord = pieces.value( 0 );
    double value = neededWord.toDouble();

    QString str ;
    int pos = 0;

    // read the data fetched from the web site
    QString data = (QString) reply->readAll();

    // use pattern matching to extract the rate
    QRegExp rx("(\\d+\\.\\d+)");

    if ( rx.indexIn(data, pos) != -1 ) {
    str = QString ("")+ rx.cap(1)+(" TL/EUR");    // rate found
    }
    else {
    str = QString("Error") ;
    }

    // set the text of the label
    ui->RateResult->setText(str) ;
    double result = value*rx.cap(1).toDouble();

    QString res;
    //precision can be changed below code section
    res = QString::number(result,'f',2) + " EUR";
    ui->AmountResult->setText(res);

    QString tli;
    //precision can be changed below code section
    tli = QString::number(value,'g',neededWord.length()) + " TL";
    ui->TLInput->setText(tli);

}
//gets the change rate of TL/GBP value from given url, reads it with regex and makes the necessary calculations
void MainWindow::replyFinishedGBP(QNetworkReply *reply)  {

    QStringList pieces = ui->TLInput->text().split( "T" );
    QString neededWord = pieces.value( 0 );
    double value = neededWord.toDouble();

    QString str ;
    int pos = 0;

    // read the data fetched from the web site
    QString data = (QString) reply->readAll();

    // use pattern matching to extract the rate
    QRegExp rx("(\\d+\\.\\d+)");

    if ( rx.indexIn(data, pos) != -1 ) {
    str = QString ("")+ rx.cap(1)+(" TL/GBP");    // rate found
    }
    else {
    str = QString("Error") ;
    }

    // set the text of the label
    ui->RateResult->setText(str) ;
    double result = value*rx.cap(1).toDouble();

    QString res;
    res = QString::number(result,'f',2) + " GBP";
    ui->AmountResult->setText(res);

    QString tli;
    tli = QString::number(value, 'g',neededWord.length()) + " TL";
    ui->TLInput->setText(tli);

}
//gets the change rate of TL/CNY value from given url, reads it with regex and makes the necessary calculations
void MainWindow::replyFinishedCNY(QNetworkReply *reply)  {

    QStringList pieces = ui->TLInput->text().split( "T" );
    QString neededWord = pieces.value( 0 );
    double value = neededWord.toDouble();

    QString str ;
    int pos = 0;

    // read the data fetched from the web site
    QString data = (QString) reply->readAll();

    // use pattern matching to extract the rate
    QRegExp rx("(\\d+\\.\\d+)");

    if ( rx.indexIn(data, pos) != -1 ) {
    str = QString ("")+ rx.cap(1)+(" TL/CNY");    // rate found
    }
    else {
    str = QString("Error") ;
    }

    // set the text of the label
    ui->RateResult->setText(str) ;
    double result = value*rx.cap(1).toDouble();

    QString res;
    res = QString::number(result,'f',2) + " CNY";
    ui->AmountResult->setText(res);

    QString tli;
    tli = QString::number(value,'g',neededWord.length()) + " TL";
    ui->TLInput->setText(tli);

}

