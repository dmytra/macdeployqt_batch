#include "examplethreads.h"
#include <QDebug>

ExampleThreads::ExampleThreads(QString threadName) :
    name(threadName)
{

}

void ExampleThreads::run()
{
    QProcess *myProcess = new QProcess();

    // /Users/srtsrthwqethqerthsrthwryjwrtsdflly/Qt/6.2.4/macos/bin/macdeployqt
    // /Users/srtsrthwqethqerthsrthwryjwrtsdflly/Downloads/Bike_Parking_By_CppBuzz.app
    QStringList arguments;

//    if(ui->checkBox->isChecked() == 1) {
//        arguments << "/Users/srtsrthwqethqerthsrthwryjwrtsdflly/Downloads/Bike_Parking_By_CppBuzz.app" << "-dmg";
//    }
//    else
//    {
//        arguments << "/Users/srtsrthwqethqerthsrthwryjwrtsdflly/Downloads/Bike_Parking_By_CppBuzz.app";
//    }

    arguments << "/Users/srtsrthwqethqerthsrthwryjwrtsdflly/Downloads/Bike_Parking_By_CppBuzz.app" << "-dmg";

    myProcess->start("/Users/srtsrthwqethqerthsrthwryjwrtsdflly/Qt/6.2.4/macos/bin/macdeployqt", arguments);
    myProcess->waitForStarted();

    qDebug() << "/Users/srtsrthwqethqerthsrthwryjwrtsdflly/Qt/6.2.4/macos/bin/macdeployqt" << " " << arguments << Qt::endl;
}
