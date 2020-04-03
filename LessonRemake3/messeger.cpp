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

void Messeger::Auth_Finished()
{
    qDebug() << "Auth error: " << this->authError;
    qDebug() << "Token: " << this->getToken();
    emit regRequestCompleted(this->authError);

}
QString Messeger::getToken() {
    return this->token;
}

void Messeger::Reg_Finished()
{
    qDebug() << "Register error: " << this->registerError;
    emit regRequestCompleted(this->registerError);
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
            if (reply->error() != QNetworkReply::NoError) {
                this->authError = reply->errorString();
            } else {
                QJsonObject obj = QJsonDocument::fromJson(reply->readAll()).object();
                QString token = obj.value("token").toString();
                this->token = token;
            }
        this->Auth_Finished();
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
      if(reply->error() != QNetworkReply::NoError)
      {
          qDebug() << "Error:" << reply -> errorString();
      }
      else {
          qDebug() << "Everything is ok";
      }

      this->Reg_Finished();
      reply->deleteLater();

  });



}
