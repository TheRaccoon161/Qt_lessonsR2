#ifndef MESSEGER_H
#define MESSEGER_H

#include <QObject>
#include <QNetworkAccessManager>

class Messeger : public QObject
{
    Q_OBJECT
public:
    QString getToken();
    QString authError;
    explicit Messeger(QObject *parent = nullptr);
    void anthenticate(const QString &login,
                      const QString &password);
    void registrate (const QString &login,
                     const QString &password);

signals:
    void regRequestCompleted(QString);
    void authRequestCompleted(QString,QString);

private:
    QNetworkAccessManager _net;
};

#endif // MESSEGER_H
