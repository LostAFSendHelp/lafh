#ifndef ADDCOLUMNVIEW_H
#define ADDCOLUMNVIEW_H

#include <QWidget>

namespace Ui {
class AddColumnView;
}

class AddColumnView : public QWidget
{
    Q_OBJECT

public:
    explicit AddColumnView(QWidget *parent = nullptr);
    ~AddColumnView();

signals:
    void onColumnCreatedSignal(const QString& columnName);

private slots:
    void on_pbConfirm_clicked();

private:
    Ui::AddColumnView *ui;

    void setupView();
};

#endif // ADDCOLUMNVIEW_H
