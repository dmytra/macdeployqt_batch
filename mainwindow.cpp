#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    this->createUI(QStringList() <<  "id"
//                                 <<  "Нечетность"
//                                 <<  "Имя компьютера"
//                                 <<  "IP адрес"
//                                 <<  "MAC адрес"
//                   );

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    // Заберём путь к файлу и его имененем, который будем open
//    QString newPath = QFileDialog::getOpenFileName(this, "Save SVG",
//                                                   path, tr("SVG files (*.svg)"));

     files = QFileDialog::getOpenFileNames(
        this,
        "Select one or more files to open",
        "/home",
        "Applicaton (*.app)");

//    for (int i = 0; i < files.size(); ++i)
//        qDebug() << files.at(i)  << Qt::endl;

//    for(int i = 0; files.size(); i++){
//        QString aa = files.at(i);
//        qDebug() << aa << Qt::endl;;
//        ui->tableWidget->insertRow(i);
//        ui->tableWidget->insertRow(i);
//        QTableWidgetItem* item = new QTableWidgetItem();
//        item->setText("text or number to display");
//        ui->tableWidget->setItem(i,0, item);
//    }


    QStringList headers = QStringList() <<  "id"
                  <<  "Нечетность"
                  <<  "Имя компьютера"
                  <<  "IP адрес"
                  <<  "MAC адрес";


    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    int i=1;
    QStringList::const_iterator constIterator;
    for (constIterator = files.constBegin(); constIterator != files.constEnd();
         ++constIterator)
    {
        qDebug() << (*constIterator).toLocal8Bit().constData() << Qt::endl;
            ui->tableWidget->insertRow(i);

                QTableWidgetItem* item = new QTableWidgetItem();
                item->setText("text or number to display");

                     ui->tableWidget->setItem(i,1, item);
                     i++;
    }
ui->tableWidget->resizeColumnsToContents();


//          for(int i = 0; files.count(); i++){
             // Insert row
             //ui->tableWidget->insertRow(i);

//             QTableWidgetItem *item = new QTableWidgetItem();
//             item->data(Qt::CheckStateRole);

//             if(files.value(1).toInt() == 1){
//                 item->setCheckState(Qt::Checked);
//             } else {
//                 item->setCheckState(Qt::Unchecked);
//             }

//             ui->tableWidget->setItem(i,1, item);
 //       }
         //ui->tableWidget->resizeColumnsToContents();



//     int a = ui->tableWidget->rowCount();
//     ui->tableWidget->setRowCount(a+1);

//     QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(
//         (row+1)*(column+1)));
//     tableWidget->setItem(row, column, newItem);

//    ui->tableWidget->setColumnCount(5);
//    ui->tableWidget->setShowGrid(true);
//    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
//    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->tableWidget->setHorizontalHeaderLabels(headers);
//    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
//    ui->tableWidget->hideColumn(0);


//    QTableWidget *t = ui->tableWidget;
//        for(int i = 0; files.size(); i++){
//            // Insert row
//            ui->tableWidget->insertRow(i);
//    t->item(i, 1)->setText("wef");
//    t->item(i, 2)->setText("wef");
//    t->item(i, 3)->setText("wef");
//    t->item(i, 4)->setText("wef");
//        }
    /* Perform filling QTableWidget records using a loop
     * */
//    for(int i = 0; files.size(); i++){
//        // Insert row
//        ui->tableWidget->insertRow(i);

//        QTableWidgetItem* item = new QTableWidgetItem();
//        item->setText("text or number to display");
//        ui->tableWidget->setItem(i,0, item);

//        ui->tableWidget->setItem(i,1, item);
//    }



}

//void MainWindow::createUI(const QStringList &headers)
//{
//    ui->tableWidget->setColumnCount(5);
//    ui->tableWidget->setShowGrid(true);
//    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
//    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->tableWidget->setHorizontalHeaderLabels(headers);
//    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
//    ui->tableWidget->hideColumn(0);

//        ui->tableWidget->insertRow(0);
//        /* Set the id column in the first taking it from the result of the SQL-query.
//         * This column will be hidden
//         * */
//        ui->tableWidget->setItem(1,0, new QTableWidgetItem("reterrtbXXX11"));
//           ui->tableWidget->setItem(2,0, new QTableWidgetItem("reterrtbXXX11"));

//            ui->tableWidget->setItem(3,0, new QTableWidgetItem("reterrtbXXX11"));

//    ui->tableWidget->resizeColumnsToContents();
//}
