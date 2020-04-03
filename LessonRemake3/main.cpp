#include <QCoreApplication>
#include "messeger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Messeger auth;
    auth.registrate("my_login1",
                     "my_password");
    auth.anthenticate("my_login2","my_password");

    return a.exec();
}
