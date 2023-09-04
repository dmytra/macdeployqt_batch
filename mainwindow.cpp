#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
        QString newPath = QFileDialog::getOpenFileName(this, "macdeployqt",
                                                       "/home",  "Unix executable(*)");
    ui->lineEdit->setText(newPath);
}

