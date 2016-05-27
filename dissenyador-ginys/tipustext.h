#ifndef TIPUSTEXT_H
#define TIPUSTEXT_H

#include <QWidget>

namespace Ui {
class tipusText;
}

class tipusText : public QWidget
{
    Q_OBJECT

public:
    explicit tipusText(QWidget *parent = 0);
    ~tipusText();

private slots:
    void on_pushButton_clicked();

    void on_btnCancel_clicked();

    void on_btnAdd_clicked();

    void on_btnColor_clicked();

signals:
    void nouText(QString id,QString text,QString color,QString family,QString tamany,bool negreta, bool cursiva);
private:
    Ui::tipusText *ui;
};

#endif // TIPUSTEXT_H
