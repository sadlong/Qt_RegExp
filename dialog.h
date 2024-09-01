#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

//正则表达式相关头文件
#include <QRegExp>
#include <QRegExpValidator>

//提示用户使用的消息框
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_Check_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
