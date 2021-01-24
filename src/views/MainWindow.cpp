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
    ui->scrollAreaHLayout->setAlignment(Qt::AlignLeading);
}

void MainWindow::on_pbAddNewColumn_clicked()
{
    ui->scrollAreaHLayout->addWidget(new PlannerColumn, 0, Qt::AlignTop);
}
