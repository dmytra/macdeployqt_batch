#ifndef EXAMPLETHREADS_H
#define EXAMPLETHREADS_H

#include <QThread> //https://habr.com/ru/articles/150274/
#include <QProcess>
#include <QDialog>
#include <QVBoxLayout>

class ExampleThreads : public QThread
{
public:
    explicit ExampleThreads(QString threadName, int i, QString program, QStringList arguments);

    // Override run () method, which will be located
    // executable code
    void run();
    ~ExampleThreads();
private:
    QString toName;   // thread name
    int index;
    QString toProgram;
    QStringList toArguments;

};

#endif // EXAMPLETHREADS_H
