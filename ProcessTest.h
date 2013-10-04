#ifndef PROCESSTEST_H
#define PROCESSTEST_H

#include <QObject>
#include <QProcess>

class ProcessTest : public QObject
{
    Q_OBJECT
public:
    explicit ProcessTest(QObject *parent = 0);

    void startProcess(const QString cmd);

signals:
    
protected slots:
    void onStarted();
    
    void onFinished(int exitcode, QProcess::ExitStatus exitStatus);
    
    void onError(QProcess::ProcessError pError);

private:
    QProcess mProcess;
};

#endif // PROCESSTEST_H
