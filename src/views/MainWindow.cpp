#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "PlannerColumn.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupView() {
    // Setup view here
    ui->hLayoutMain->setAlignment(Qt::AlignLeading);

#ifdef QT_DEBUG
    ui->frMain->setFrameShape(QFrame::Box);
#endif

}

void MainWindow::on_pbAddNewColumn_clicked()
{
    ui->hLayoutMain->addWidget(new PlannerColumn);
}
