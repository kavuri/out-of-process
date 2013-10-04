#include "ProcessTest.h"

#include <QDebug>

ProcessTest::ProcessTest(QObject *parent) :
    QObject(parent)
{
    QObject::connect (&mProcess, SIGNAL(started()),
                      this, SLOT(onStarted()));
    QObject::connect (&mProcess, SIGNAL(finished(int, QProcess::ExitStatus)),
                      this, SLOT(onFinished(int, QProcess::ExitStatus)));
    QObject::connect (&mProcess, SIGNAL(error(QProcess::ProcessError)),
                      this, SLOT(onError(QProcess::ProcessError)));
}

void
ProcessTest::startProcess (const QString cmd)
{
    //mProcess.start(cmd);
    mProcess.startDetached (cmd);

    mProcess.write ("something");
}

void
ProcessTest::onStarted ()
{
    qDebug() << "On started";
}

void
ProcessTest::onFinished (int exitcode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "onFinished with exit code " << exitcode << " and status " << exitStatus;
    QByteArray output = mProcess.readAllStandardOutput ();
    
    qDebug() << output;
}

void
ProcessTest::onError (QProcess::ProcessError pError)
{
    qDebug() << "onError with error " << pError;

    qDebug() << mProcess.readAllStandardError ();
}
