#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

//验证手机号码
//1、筛选出里面的数字字符
//2、使用正则表达式匹配数字字符是否是11位
void Dialog::on_pushButton_Check_clicked()
{
    QRegExp regxtel("\\d+");    //这是一个比较宽泛的匹配规则，可以匹配到所有的数字序列。
    QRegExp regxtelStr("^1([358][0-9]|4[579]|6[2567]|7[0135678]|9[0123589])[0-9]{8}$"); //正则表达式规则
    QRegExpValidator regxtelvlt(regxtelStr);    //用于验证符合 regxtelStr 正则表达式的字符串

    //QString strDest;
    int iPos = 0;   //用于记录在字符串中查找的位置
    int inPos = 0;  //用于记录验证位置的起始值

    //在 ui->lineEdit_Phone 的文本中，从 iPos 开始查找数字序列。如果找到，则返回找到的位置。
    while((iPos = regxtel.indexIn(ui->lineEdit_Phone->text(), iPos)) != -1) {
        QString strPhones = regxtel.cap(0); //获取当前找到的数字序列。
        QValidator::State result = regxtelvlt.validate(strPhones, inPos);   //验证提取的电话号码 strPhones 是否符合正则表达式

        if(QValidator::Acceptable == result) {
            QMessageBox::information(this, "提示", "手机号码验证正确！", QMessageBox::Yes);
        } else {
            QMessageBox::critical(this, "提示", "手机号码验证错误！", QMessageBox::Yes);
        }

        iPos += regxtel.matchedLength();    //更新查找的位置，以便继续查找下一个数字序列。
    }
}
