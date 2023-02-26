#include "startrequest.h"

StartRequest::StartRequest(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(startRequest()));
    //timer->start(1000);

}

StartRequest::~StartRequest()
{
    delete timer;
}

void StartRequest::startRequest()
{
    QString norad_ID[3] = {"47306", "40984", "39079"};

    QEventLoop eventLoop;
    QNetworkAccessManager manager;
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    /*for(int i = 0; i < norad_ID->length(); i++){
        qDebug()<<norad_ID[i];
        QNetworkRequest request(QUrl(QString("https://api.n2yo.com/rest/v1/satellite/positions/" + norad_ID[i] + "/40.18111/44.51361/0/2/&apiKey=KYS23A-ZR25PX-83S3JK-4ZW1")));
        QNetworkReply *reply = manager.get(request);
        eventLoop.exec();
        readAllData_object.readAllData(reply);
    }*/
    //HTTP requests
    /*QNetworkRequest request1(QUrl(QString("https://api.n2yo.com/rest/v1/satellite/tle/47306&apiKey=KYS23A-ZR25PX-83S3JK-4ZW1")));
    QNetworkReply *reply1 = manager.get(request1);

    QNetworkRequest request2(QUrl(QString("https://api.n2yo.com/rest/v1/satellite/tle/40984&apiKey=KYS23A-ZR25PX-83S3JK-4ZW1")));
    QNetworkReply *reply2 = manager.get(request2);

    QNetworkRequest request3(QUrl(QString("https://api.n2yo.com/rest/v1/satellite/tle/39079&apiKey=KYS23A-ZR25PX-83S3JK-4ZW1")));
    QNetworkReply *reply3 = manager.get(request3);*/

    /*QNetworkRequest request1(QUrl(QString("https://api.n2yo.com/rest/v1/satellite/positions/47306/40.18111/44.51361/0/2/&apiKey=KYS23A-ZR25PX-83S3JK-4ZW1")));
    QNetworkReply *reply1 = manager.get(request1);

    QNetworkRequest request2(QUrl(QString("https://api.n2yo.com/rest/v1/satellite/positions/40984/40.18111/44.51361/0/2/&apiKey=KYS23A-ZR25PX-83S3JK-4ZW1")));
    QNetworkReply *reply2 = manager.get(request2);*/

    QNetworkRequest request3(QUrl(QString("https://api.n2yo.com/rest/v1/satellite/positions/39079/40.18111/44.51361/0/2/&apiKey=KYS23A-ZR25PX-83S3JK-4ZW1")));
    QNetworkReply *reply3 = manager.get(request3);

    /*eventLoop.exec();
    readAllData_object.readAllData(reply1);
    eventLoop.exec();
    readAllData_object.readAllData(reply2);*/
    eventLoop.exec();
    readAllData_object.readAllData(reply3);

}
