#include "examplethreads.h"
#include "mainwindow.h"
#include <QDebug>

ExampleThreads::ExampleThreads(QString threadName, int i, QString program, QStringList arguments) :
    toName(threadName), index(i), toProgram(program), toArguments(arguments)
{

}

ExampleThreads::~ExampleThreads()
{

}

void ExampleThreads::run()
{
    QProcess *myProcess = new QProcess();

    myProcess->startDetached(toProgram, toArguments);
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    myProcess->setProcessEnvironment(env);

    //myProcess->setEnvironment(QProcess::systemEnvironment());
    //myProcess->waitForStarted();
    //myProcess->waitForFinished();
    //myProcess->close();

    qDebug() << toProgram << " " << toArguments << Qt::endl;

    if (!myProcess->waitForFinished())
        qDebug() << "Make failed:" ;//<< myProcess->errorString();
    else
    {
        qDebug() << "Make output: " << toName << " " << index;//<< myProcess->readAll();
    }

    if (myProcess->exitCode() == 1)
        qDebug() << "Make failed: not finished " ;//<< myProcess->errorString();
    else
    {
        qDebug() << "Make output: finished " << toName << " " << index;//<< myProcess->readAll();

        //############CRASH##############
//        QDialog *Dblack = new QDialog();
//        QVBoxLayout *vlayout = new QVBoxLayout;
//        Dblack->setFixedSize(300,280);

//        Dblack->setLayout(vlayout);
//        Dblack->show();
    }

}
