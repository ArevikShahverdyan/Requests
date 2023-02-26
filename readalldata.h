#ifndef READALLDATA_H
#define READALLDATA_H

#include <QNetworkReply>
#include <QObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
using namespace std;

struct satellitePositions
{
    Q_GADGET
    Q_PROPERTY(QString    name     MEMBER  name_v)
    Q_PROPERTY(int    norad_ID     MEMBER  norad_ID_v)
    Q_PROPERTY(double    latitude     MEMBER  latitude_v)
    Q_PROPERTY(double    longitude     MEMBER  longitude_v)
    Q_PROPERTY(double    altitude     MEMBER  altitude_v)

public:

    QString name_v;
    int  norad_ID_v;
    double latitude_v;
    double longitude_v;
    double altitude_v;

};

Q_DECLARE_METATYPE(satellitePositions);

class ReadAllData : public QObject
{
    Q_OBJECT
public:
    explicit ReadAllData(QObject *parent = nullptr);
    ~ReadAllData();

    void readAllData(QNetworkReply *reply);

public:
    satellitePositions *satellitePositions_object;

signals:
    void target_data(satellitePositions satellitePositions_object);

};

#endif // READALLDATA_H
