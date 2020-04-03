#include "messeger.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

Messeger::Messeger(QObject *parent) : QObject(parent)
{

}

void Messeger::anthenticate(const QString &login, const QString &password)
{
    QUrl url ("http://127.0.0.1:7936/auth");

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    QJsonObject body;
    body ["login"] = login;
    body ["password"] = password;
    QByteArray bodyData = QJsonDocument(body).toJson();

    QNetworkReply *reply= _net.post(request, bodyData);

    connect(reply, &QNetworkReply::finished,
                [this, reply](){
                QJsonObject obj = QJsonDocument::fromJson(reply->readAll()).object();
                emit authRequestCompleted(reply->errorString(),
                                          obj.value("token").toString());
                reply->deleteLater();

    });
}



void Messeger::registrate(const QString &login, const QString &password)
{
  QUrl url ("http://127.0.0.1:7936/register");

  QNetworkRequest request(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
  QJsonObject body;
  body ["login"] = login;
  body ["password"] = password;
  QByteArray bodyData = QJsonDocument(body).toJson();

  QNetworkReply *reply= _net.post(request, bodyData);

  connect(reply, &QNetworkReply::finished,[this,reply](){
      emit regRequestCompleted(reply -> errorString());
      reply->deleteLater();

  });



}
