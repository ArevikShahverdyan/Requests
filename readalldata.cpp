#include "readalldata.h"

ReadAllData::ReadAllData(QObject *parent) : QObject(parent)
{

}

ReadAllData::~ReadAllData()
{
    delete satellitePositions_object;
}

void ReadAllData::readAllData(QNetworkReply *reply)
{
    satellitePositions_object = new satellitePositions();
    if (reply->error() == QNetworkReply::NoError)
    {
        QJsonObject jsonObject= QJsonDocument::fromJson(reply->readAll()).object();
        QJsonObject infoData = jsonObject["info"].toObject();
        QJsonArray positionsData = jsonObject["positions"].toArray();
        QJsonObject subtree = positionsData.at(0).toObject();

        satellitePositions_object->name_v = infoData.value("satname").toString();
        satellitePositions_object->norad_ID_v = infoData.value("satid").toInt();
        satellitePositions_object->latitude_v = subtree.value("satlatitude").toDouble();
        satellitePositions_object->longitude_v = subtree.value("satlongitude").toDouble();
        satellitePositions_object->altitude_v = subtree.value("sataltitude").toDouble();


        /*qDebug() << "Satellite name: " << satellitePositions_object->name_v;
        qDebug() << "Satellite ID: " << satellitePositions_object->norad_ID_v;
        qDebug() << "Satellite latitude: " << satellitePositions_object->latitude_v;
        qDebug() << "Satellite longitude: " << satellitePositions_object->longitude_v;
        qDebug() << "Satellite altitude: " << satellitePositions_object->altitude_v;
        qDebug() << "Data is" << positionsData << "\n";*/
        emit(target_data(*satellitePositions_object));
        delete reply;
    }
    else
    {
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }
}
