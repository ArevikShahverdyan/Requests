#ifndef STARTREQUEST_H
#define STARTREQUEST_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QCoreApplication>
#include <readalldata.h>
#include <QTimer>
class StartRequest : public QObject
{
    Q_OBJECT
public:
    explicit StartRequest(QObject *parent = nullptr);
    ~StartRequest();


public:
    ReadAllData readAllData_object;

private:
    QTimer *timer;

public slots:
    void startRequest();


};

#endif // STARTREQUEST_H
