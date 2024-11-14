#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>

#include "convert.h"
#include "create_code_map.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QUdpSocket* udpSocket;

private slots:
    
    ///////////////////////////网络连接槽函数
    void on_openBtn_clicked();

    void readyRead_Slot();          //准备接收数据的槽函数

    void on_clearBtn_clicked();

    void on_sendBtn_clicked();

    void on_closeBtn_clicked();

    void on_resetnumBtn_clicked();
    
    ////////////////////////////控制部分槽函数

    void on_array_setting_btn_clicked();
    
    void on_calibration_setting_btn_clicked();
    
    void on_read_data_btn_clicked();
    
    void on_convert_btn_clicked();

    void on_band_comboBox_currentIndexChanged(int index);

    void on_rough_ctrl_toggled(bool checked);

    void on_accurate_ctrl_toggled(bool checked);

    void on_clear_data_btn_clicked();

    // void on_first_switch_spin_valueChanged(int arg1);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
