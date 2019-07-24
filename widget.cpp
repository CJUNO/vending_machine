#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    moneyChack(money);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    money += n;
    moneyChack(money);
    ui ->lcdNumber->display(money);
}

void Widget::moneyChack(int m){
    ui->coffee100->setEnabled(false);
    ui->pbcoffee150->setEnabled(false);
    ui->pbcola->setEnabled(false);


    if (m<100){
        ui->coffee100->setEnabled(false);
        ui->pbcoffee150->setEnabled(false);
        ui->pbcola->setEnabled(false);
    }

    else if(m<150 && m>=100){
        ui->pbcoffee150->setEnabled(false);
        ui->pbcola->setEnabled(false);
        ui->coffee100->setEnabled(true);
    }

    else if (m<200){
        ui->pbcola->setEnabled(false);
        ui->coffee100->setEnabled(true);
        ui->pbcoffee150->setEnabled(true);
    }
    else{
        ui->coffee100->setEnabled(true);
        ui->pbcoffee150->setEnabled(true);
        ui->pbcola->setEnabled(true);
    }
}



void Widget::on_pb10_clicked()
{
    changeMoney(10);
    //ui->pbcola->setEnabled(false);  // TEST CODE
    //QMessageBox msg;  // TEST CODE
    //msg.information(nullptr, "error", "error!!");  // TEST CODE
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbcoffee150_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbcola_clicked()
{
    changeMoney(-200);
}

void Widget::on_coffee100_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbreset_clicked()
{
    QMessageBox msg;
    QString totalString;
    int smallChange500 = 0;
    int smallChange100 = 0;
    int smallChange50 = 0;
    int smallChange10 = 0;

    while(1){
        if(money>=500){
            smallChange500 = money / 500;
            money = money - (500 * smallChange500);
        }
        else if(money >= 100){
            smallChange100 = money / 100;
            money = money - (100 * smallChange100);
        }
        else if(money >= 50){
            smallChange50 = money / 50;
            money = money - (50 * smallChange50);
        }
        else if (money >= 10) {
            smallChange10 = money / 10;
            money = money - (10 * smallChange10);
        }
        else{
            break;
        }
    }

    totalString = QString("500 : %1 / 100 : %2 / 50 : %3 / 10 : %4")
                .arg(smallChange500)
                .arg(smallChange100)
                .arg(smallChange50)
                .arg(smallChange10);

    ui ->lcdNumber->display(money);

    moneyChack(money);

    msg.information(nullptr, "small change", totalString);



    // QMessageBox msg;  // TEST CODE
    // msg.information(nullptr, "small change", "error!!");  // TEST CODE
}
