#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "services/JiraClient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbAddNewColumn_clicked();
    void addNewColumn(const QString& columnName);

private:
    Ui::MainWindow *ui;
    JiraClient m_JiraClient;

private:
    void setupView();
};

#endif // MAINWINDOW_H
