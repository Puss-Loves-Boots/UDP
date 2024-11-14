#include "widget.h"
#include "ui_widget.h"

#include <QMessagebox>
#include <QDebug>
#include <QSpinBox>
//#include "convert.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("控制软件");
    this->setWindowIcon(QIcon(":/1.jpg"));

    ///////////////////////UDP连接时设置的默认端口号和ip地址、计数器初始化、默认发送文本，部分按钮初始化
    ui->localPort->setText("8081");
    ui->localIP->setText("127.0.0.1");
    ui->aimPort->setText("8082");
    ui->aimIP->setText("127.0.0.1");
    ui->sendEdit->setText("hello");
    ui->count->setText("0/0");
    udpSocket = new QUdpSocket(this);

    ui->closeBtn->setEnabled(false);
    ui->sendBtn->setEnabled(false);

    //////////////////////控制面板部分按钮和文本初始化
    ui->accurate_ctrl->setChecked(true);        ///////默认选择精控

    ui->first_attenuator->setText("0X3FF");


    ui->first_switch->setText("11101111");
    ui->second_switch->setText("1110");
    ui->third_switch->setText("1110");

}

Widget::~Widget()
{
    delete ui;
}

static int receive_num = 0;
static int send_num = 0;

/////////////////////////网络连接部分////////////////////////////////////////////////////////////////////////////////////////

void Widget::on_openBtn_clicked()
{
    if(udpSocket->bind(QHostAddress(ui->localIP->text()),ui->localPort->text().toUInt()) ==true)        //点击打开按钮，将套接字绑定用户指定端口
    {
        // QMessageBox::information(this, "Bind", "Bind ip and port success!");
        ui->recordEdit->appendPlainText("----Bind ip and port success!----");
    }
    else
        // QMessageBox::information(this, "Bind", "Bind ip and port fail");
        ui->recordEdit->appendPlainText("----Bind ip and port fail!----");

    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readyRead_Slot()));

    ui->openBtn->setDisabled(true);
    ui->closeBtn->setDisabled(false);
    ui->sendBtn->setEnabled(true);
}


void Widget::readyRead_Slot()
{
    // ui->recordEdit->appendPlainText("###############Receive##################");
    while(udpSocket->hasPendingDatagrams())             //循环读取所有待处理的数据报
    {
        QByteArray array;                               //存储接收数据
        array.resize(udpSocket->pendingDatagramSize());  //调整array大小
        udpSocket->readDatagram(array.data(), array.size());        //从udpSocket接收数据存储到array

        QString buff = array.data();                    //转换为string
        ui->recordEdit->appendPlainText("**Receive**: " + buff);         //接收界面显示数据
        receive_num+=buff.size();
        QString count = QString("%1 / %2").arg(QString::number(receive_num), QString::number(send_num));
        ui->count->setText(count);
    }
}


void Widget::on_sendBtn_clicked()
{
    qint16 port;
    QString sendBuff;
    QHostAddress address;           //IP

    address.setAddress(ui->aimIP->text());          //目标IP地址
    sendBuff = ui->sendEdit->text();                //发送的数据报
    port = ui->aimPort->text().toUInt();            //目标端口
    udpSocket->writeDatagram(sendBuff.toLocal8Bit(), sendBuff.size(), address, port);       //发送数据报
    ui->recordEdit->appendPlainText("**Send**: " + sendBuff);
    send_num+=sendBuff.size();
    QString count = QString("%1 / %2").arg(QString::number(receive_num), QString::number(send_num));
    ui->count->setText(count);
}


void Widget::on_closeBtn_clicked()
{
    udpSocket->close();
    // QMessageBox::information(this, "Close", "UDP disconnect");
    ui->recordEdit->appendPlainText("----UDP disconnect!----");
    ui->closeBtn->setDisabled(true);
    ui->openBtn->setDisabled(false);
    ui->sendBtn->setDisabled(true);
}


void Widget::on_clearBtn_clicked()
{
    ui->recordEdit->clear();
}


void Widget::on_resetnumBtn_clicked()
{
    receive_num = 0;
    send_num = 0;
    ui->count->setText("0/0");
}

///////////////////////////////////控制部分///////////////////////////////////////////////////////////////////////////////

void Widget::on_convert_btn_clicked()
{
    ////////////////////////////////////////
    qint16 port;
    QString sendBuff;
    QHostAddress address;           //IP

    address.setAddress(ui->aimIP->text());          //目标IP地址
    // sendBuff = ui->sendEdit->text();                //发送的数据报
    port = ui->aimPort->text().toUInt();            //目标端口
    ////////////////////////////////////////

    // ui->recordEdit->appendPlainText("###############Send##################");

    ///////////////////////////最外层的判断，选择精控还是粗控
    if(ui->accurate_ctrl->isChecked())      //精控
    {
        if(ui->band_comboBox->currentText() == "Ka")
        {
            if(ui->phaser->text().isEmpty())
            {
                string code = ui->first_attenuator->text().toStdString();
                string control_code = code_convert(1, code);
                sendBuff = QString::fromStdString(control_code);
            }
            else if(!ui->phaser->text().isEmpty())
            {
                string code = ui->phaser->text().toStdString();
                string control_code = code_convert(2, code);
                sendBuff = QString::fromStdString(control_code);
            }
        }
        else if(ui->band_comboBox->currentText() == "2-18GHz")
        {
            if(ui->phaser->text().isEmpty())
            {
                string code = ui->first_attenuator->text().toStdString();
                string control_code = code_convert(4, code);
                sendBuff = QString::fromStdString(control_code);
            }
            else if(!ui->phaser->text().isEmpty())
            {
                string code = ui->phaser->text().toStdString();
                string control_code = code_convert(5, code);
                sendBuff = QString::fromStdString(control_code);
            }
        }
    }
    else if(ui->rough_ctrl->isChecked())        //粗控
    {
        if(ui->band_comboBox->currentText() == "Ka")
        {
            string sub_code1 = ui->first_switch->text().toStdString();
            string sub_code2 = ui->second_switch->text().toStdString();
            string sub_code3 = ui->third_switch->text().toStdString();
            string code = sub_code1 + sub_code2 + sub_code3;
            if(ui->channel_comboBox->currentText() == "9")      //通道9-12
            {
                string control_code = code_convert(7, code);
                sendBuff = QString::fromStdString(control_code);
            }
            else if(ui->channel_comboBox->currentText() == "10")      //通道9-12
            {
                string control_code = code_convert(8, code);
                sendBuff = QString::fromStdString(control_code);
            }
            else if(ui->channel_comboBox->currentText() == "11")      //通道9-12
            {
                string control_code = code_convert(9, code);
                sendBuff = QString::fromStdString(control_code);
            }
            else if(ui->channel_comboBox->currentText() == "12")      //通道9-12
            {
                string control_code = code_convert(10, code);
                sendBuff = QString::fromStdString(control_code);
            }
        }
    }

    ui->recordEdit->appendPlainText("**Send**: " + sendBuff);
    udpSocket->writeDatagram(sendBuff.toLocal8Bit(), sendBuff.size(), address, port);
    send_num++;
    QString count = QString("%1 / %2").arg(QString::number(receive_num), QString::number(send_num));
    ui->count->setText(count);

}

///////////////////////////////////控制部分/////////////////////////////

void Widget::on_array_setting_btn_clicked()         //阵列设置
{
    
}

void Widget::on_calibration_setting_btn_clicked()   //校准设置
{
    
}

void Widget::on_read_data_btn_clicked()             //读取数据
{
    
}


void Widget::on_band_comboBox_currentIndexChanged(int index)        //选择Ka还是2-18，并改变相应的通道
{
    ui->channel_comboBox->clear();
    if(index == 0)
    {
        ui->channel_comboBox->clear();
        QStringList list = {"9", "10", "11", "12"};
        ui->channel_comboBox->addItems(list);
    }
    else
    {
        QStringList list = {"1", "2", "3", "4", "5", "6", "7", "8"};
        ui->channel_comboBox->addItems(list);
    }
    if(ui->accurate_ctrl->isChecked())
    {
        ui->data_record_edit->appendPlainText("----" + ui->band_comboBox->currentText() + "天线精控----");
        ui->data_record_edit->appendPlainText("");
    }
    else
    {
        ui->data_record_edit->appendPlainText("----" + ui->band_comboBox->currentText() + "天线粗控----");
        ui->data_record_edit->appendPlainText("");
    }

}


void Widget::on_rough_ctrl_toggled(bool checked)        //选择粗控，相应控件可用，其余不可用
{
    if(checked == true)
    {
        ui->first_attenuator->setEnabled(false);
        ui->second_attenuator->setEnabled(false);
        ui->phaser->setEnabled(false);

        ui->first_switch->setEnabled(true);
        ui->second_switch->setEnabled(true);
        ui->third_switch->setEnabled(true);

        ui->data_record_edit->appendPlainText("----" + ui->band_comboBox->currentText() + "天线粗控----");
        ui->data_record_edit->appendPlainText("");
    }
}


void Widget::on_accurate_ctrl_toggled(bool checked)         //选择精控，相应控件可用，其余不可用
{
    if(checked == true)
    {
        ui->first_switch->setEnabled(false);
        ui->second_switch->setEnabled(false);
        ui->third_switch->setEnabled(false);

        ui->first_attenuator->setEnabled(true);
        ui->second_attenuator->setEnabled(true);
        ui->phaser->setEnabled(true);

        ui->data_record_edit->appendPlainText("----" + ui->band_comboBox->currentText() + "天线精控----");
        ui->data_record_edit->appendPlainText("");
    }
}


void Widget::on_clear_data_btn_clicked()
{
    ui->data_record_edit->clear();
}


// void Widget::on_first_switch_spin_valueChanged(int arg1)
// {
//     qDebug() << arg1;
// }

