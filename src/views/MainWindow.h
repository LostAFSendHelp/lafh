#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void setupView();
};

#endif // MAINWINDOW_H
