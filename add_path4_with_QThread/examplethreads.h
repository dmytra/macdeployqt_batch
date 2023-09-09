#ifndef EXAMPLETHREADS_H
#define EXAMPLETHREADS_H

#include <QThread>
#include <QProcess>

class ExampleThreads : public QThread
{
public:
    explicit ExampleThreads(QString threadName);

    // Override run () method, which will be located
    // executable code
    void run();
private:
    QString name;   // thread name
};

#endif // EXAMPLETHREADS_H
