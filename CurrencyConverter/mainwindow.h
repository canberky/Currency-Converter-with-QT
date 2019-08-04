#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager ;
private slots:
    void pushPressed();
    void replyFinishedUSD(QNetworkReply*);
    void replyFinishedEUR(QNetworkReply*);
    void replyFinishedGBP(QNetworkReply*);
    void replyFinishedCNY(QNetworkReply*);
};




#endif // MAINWINDOW_H
