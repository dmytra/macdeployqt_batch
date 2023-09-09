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

    myProcess->start(toProgram, toArguments);
    myProcess->waitForStarted();

    qDebug() << toProgram << " " << toArguments << Qt::endl;

    if (!myProcess->waitForFinished())
        qDebug() << "Make failed:" ;//<< myProcess->errorString();
    else
    {
        qDebug() << "Make output: " << toName << " " << index;//<< myProcess->readAll();
    }

}
