#include <QCoreApplication>
#include <QProcess>

#include "ProcessTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    ProcessTest pt;
    pt.startProcess (argv[1]);
    return a.exec();
}
