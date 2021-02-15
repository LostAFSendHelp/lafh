#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "PlannerColumn.h"
#include "AddColumnView.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_JiraClient(this)
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

    // AddColumnView
    auto addColumnView = new AddColumnView;
    ui->hLayoutMain->addWidget(addColumnView, 0, Qt::AlignTop);
    QObject::connect(addColumnView,
                     SIGNAL(onColumnCreatedSignal(const QString&)),
                     this,
                     SLOT(addNewColumn(const QString&)));

    // Setup Jira client
    connect(&m_JiraClient, &JiraClient::authenticated, [=]() {
        ui->pbAddNewColumn->setText("Auth");
    });

#ifdef QT_DEBUG
    ui->frMain->setFrameShape(QFrame::Box);
#endif

}

void MainWindow::on_pbAddNewColumn_clicked()
{
    m_JiraClient.authorize();
}

void MainWindow::addNewColumn(const QString& columnName) {
    auto index = ui->hLayoutMain->count() - 1;
    ui->hLayoutMain->insertWidget(index, new PlannerColumn(nullptr, columnName));
}
