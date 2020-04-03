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
    QString registerError;
    explicit Messeger(QObject *parent = nullptr);
    void anthenticate(const QString &login,
                      const QString &password);
    void registrate (const QString &login,
                     const QString &password);
private slots:
    void Reg_Finished();
    void Auth_Finished();

signals:
    void regRequestCompleted(QString);
    void authRequestCompleted(QString);

private:
    QNetworkAccessManager _net;
    QString token;
signals:

};

#endif // MESSEGER_H
