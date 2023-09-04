#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("/Users/srtsrthwqethqerthsrthwryjwrtsdflly/Qt/6.2.4/macos/bin/macdeployqt");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     files = QFileDialog::getOpenFileNames(
        this,
        "Select one or more files to open",
        "/home",
        "Applicaton (*.app)");

    QStringList headers = QStringList() <<  "filenames app"
                  <<  "passed"
                  <<  "dmg";

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    //ui->tableWidget->hideColumn(0);

    int i=0;
    QStringList::const_iterator constIterator;
    for (constIterator = files.constBegin(); constIterator != files.constEnd();
         ++constIterator)
    {
        qDebug() << (*constIterator).toLocal8Bit().constData() << Qt::endl;
            ui->tableWidget->insertRow(i);

            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText((*constIterator).toLocal8Bit().constData());

            ui->tableWidget->setItem(i,0, item);
            i++;
    }
    ui->tableWidget->resizeColumnsToContents();
}

void MainWindow::on_pushButton_2_clicked()
{
    //    // Заберём путь к файлу и его имененем, который будем open
        newPath = QFileDialog::getOpenFileName(this, "macdeployqt",
                                                       "/home",  "Unix executable(*)");
    ui->lineEdit->setText(newPath);
}


void MainWindow::on_pushButton_3_clicked()
{

//            QProcess process;
//            process.start("ls", QStringList() << "-l");
//            process.waitForFinished();


    QString program =  ui->lineEdit->text();
            QStringList arguments;

            int i=0;
            QStringList::const_iterator constIterator;
            for (constIterator = files.constBegin(); constIterator != files.constEnd();
                 ++constIterator)
            {
            arguments.clear();

            if(ui->checkBox->isChecked() == 1) {
            arguments << (*constIterator).toLocal8Bit().constData() << "-dmg";
            }
            else
            {
            arguments << (*constIterator).toLocal8Bit().constData();
            }

// /Users/srtsrthwqethqerthsrthwryjwrtsdflly/Qt/6.2.4/macos/bin/macdeployqt
// /Users/srtsrthwqethqerthsrthwryjwrtsdflly/Downloads/Bike_Parking_By_CppBuzz.app


            qDebug() << program << " " << i << " "  <<  (*constIterator).toLocal8Bit().constData() << Qt::endl;

            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText("OK");

            ui->tableWidget->setItem(i,1, item);

            QTableWidgetItem* item2 = new QTableWidgetItem();
            if(ui->checkBox->isChecked() == 1) {
            item2->setText("OK");
            }
            else
            {
            item2->setText("---");
            }
                        ui->tableWidget->setItem(i,2, item2);

            QProcess *myProcess = new QProcess();
            myProcess->start(program, arguments);
            myProcess->waitForFinished();
            i++;
            }

}

