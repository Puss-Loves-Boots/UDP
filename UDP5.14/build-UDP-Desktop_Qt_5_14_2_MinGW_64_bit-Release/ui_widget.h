/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_udp;
    QWidget *send_record;
    QLabel *label;
    QPlainTextEdit *recordEdit;
    QLabel *label_6;
    QTextEdit *sendEdit;
    QWidget *cout_size;
    QLabel *send_size;
    QLabel *count;
    QLabel *label_22;
    QWidget *left_bottom;
    QVBoxLayout *verticalLayout;
    QWidget *btns_left;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *sendBtn;
    QPushButton *resetnumBtn;
    QPushButton *clearBtn_send;
    QLabel *label_5;
    QPushButton *clearBtn;
    QPushButton *openBtn;
    QPushButton *closeBtn;
    QWidget *ip_port;
    QGridLayout *gridLayout_2;
    QWidget *local_ip;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *localIP;
    QWidget *local_port;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *localPort;
    QWidget *aim_ip;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *aimIP;
    QWidget *aim_port;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QLineEdit *aimPort;
    QFrame *line;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *loopBtn;
    QLineEdit *looptime;
    QLabel *label_21;
    QLabel *currTime;
    QFrame *line_2;
    QWidget *widget_control;
    QWidget *widget_data_record;
    QLabel *label_8;
    QPlainTextEdit *data_record_edit;
    QWidget *widget_setting;
    QGridLayout *gridLayout;
    QComboBox *branch_comboBox;
    QComboBox *band_comboBox;
    QLineEdit *third_switch;
    QLineEdit *first_switch;
    QLineEdit *phaser;
    QLineEdit *second_switch;
    QLabel *label_10;
    QComboBox *channel_comboBox;
    QLabel *label_15;
    QLabel *label_20;
    QPushButton *convert_btn;
    QLineEdit *second_attenuator;
    QLineEdit *channel_freq;
    QLineEdit *calibrate;
    QLabel *label_17;
    QLabel *label_12;
    QLineEdit *delay;
    QLabel *label_11;
    QLabel *label_16;
    QLabel *label_19;
    QLabel *label_13;
    QLabel *label_9;
    QLabel *label_18;
    QLabel *label_14;
    QLineEdit *first_attenuator;
    QWidget *widget_btn;
    QHBoxLayout *horizontalLayout;
    QPushButton *array_setting_btn;
    QPushButton *calibration_setting_btn;
    QPushButton *read_data_btn;
    QPushButton *clear_data_btn;
    QRadioButton *rough_ctrl;
    QRadioButton *accurate_ctrl;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1020, 636);
        Widget->setAutoFillBackground(false);
        Widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(Widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widget_udp = new QWidget(Widget);
        widget_udp->setObjectName(QString::fromUtf8("widget_udp"));
        send_record = new QWidget(widget_udp);
        send_record->setObjectName(QString::fromUtf8("send_record"));
        send_record->setGeometry(QRect(9, 9, 471, 361));
        label = new QLabel(send_record);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 10, 48, 16));
        recordEdit = new QPlainTextEdit(send_record);
        recordEdit->setObjectName(QString::fromUtf8("recordEdit"));
        recordEdit->setEnabled(true);
        recordEdit->setGeometry(QRect(230, 30, 210, 325));
        recordEdit->setFocusPolicy(Qt::ClickFocus);
        recordEdit->setReadOnly(true);
        recordEdit->setTextInteractionFlags(Qt::NoTextInteraction);
        label_6 = new QLabel(send_record);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 10, 61, 16));
        sendEdit = new QTextEdit(send_record);
        sendEdit->setObjectName(QString::fromUtf8("sendEdit"));
        sendEdit->setGeometry(QRect(10, 30, 210, 325));
        cout_size = new QWidget(widget_udp);
        cout_size->setObjectName(QString::fromUtf8("cout_size"));
        cout_size->setGeometry(QRect(10, 370, 461, 31));
        send_size = new QLabel(cout_size);
        send_size->setObjectName(QString::fromUtf8("send_size"));
        send_size->setGeometry(QRect(9, 9, 201, 16));
        send_size->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        count = new QLabel(cout_size);
        count->setObjectName(QString::fromUtf8("count"));
        count->setGeometry(QRect(240, 10, 131, 16));
        count->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_22 = new QLabel(cout_size);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(380, 10, 71, 20));
        label_22->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        left_bottom = new QWidget(widget_udp);
        left_bottom->setObjectName(QString::fromUtf8("left_bottom"));
        left_bottom->setGeometry(QRect(0, 410, 461, 171));
        verticalLayout = new QVBoxLayout(left_bottom);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btns_left = new QWidget(left_bottom);
        btns_left->setObjectName(QString::fromUtf8("btns_left"));
        horizontalLayout_2 = new QHBoxLayout(btns_left);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sendBtn = new QPushButton(btns_left);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));

        horizontalLayout_2->addWidget(sendBtn);

        resetnumBtn = new QPushButton(btns_left);
        resetnumBtn->setObjectName(QString::fromUtf8("resetnumBtn"));

        horizontalLayout_2->addWidget(resetnumBtn);

        clearBtn_send = new QPushButton(btns_left);
        clearBtn_send->setObjectName(QString::fromUtf8("clearBtn_send"));

        horizontalLayout_2->addWidget(clearBtn_send);

        label_5 = new QLabel(btns_left);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        clearBtn = new QPushButton(btns_left);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));

        horizontalLayout_2->addWidget(clearBtn);

        openBtn = new QPushButton(btns_left);
        openBtn->setObjectName(QString::fromUtf8("openBtn"));

        horizontalLayout_2->addWidget(openBtn);

        closeBtn = new QPushButton(btns_left);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));

        horizontalLayout_2->addWidget(closeBtn);


        verticalLayout->addWidget(btns_left);

        ip_port = new QWidget(left_bottom);
        ip_port->setObjectName(QString::fromUtf8("ip_port"));
        gridLayout_2 = new QGridLayout(ip_port);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        local_ip = new QWidget(ip_port);
        local_ip->setObjectName(QString::fromUtf8("local_ip"));
        horizontalLayout_6 = new QHBoxLayout(local_ip);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(local_ip);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        localIP = new QLineEdit(local_ip);
        localIP->setObjectName(QString::fromUtf8("localIP"));
        localIP->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_6->addWidget(localIP);


        gridLayout_2->addWidget(local_ip, 0, 0, 1, 1);

        local_port = new QWidget(ip_port);
        local_port->setObjectName(QString::fromUtf8("local_port"));
        horizontalLayout_4 = new QHBoxLayout(local_port);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(local_port);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        localPort = new QLineEdit(local_port);
        localPort->setObjectName(QString::fromUtf8("localPort"));
        localPort->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_4->addWidget(localPort);


        gridLayout_2->addWidget(local_port, 0, 1, 1, 1);

        aim_ip = new QWidget(ip_port);
        aim_ip->setObjectName(QString::fromUtf8("aim_ip"));
        horizontalLayout_5 = new QHBoxLayout(aim_ip);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(aim_ip);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        aimIP = new QLineEdit(aim_ip);
        aimIP->setObjectName(QString::fromUtf8("aimIP"));
        aimIP->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_5->addWidget(aimIP);


        gridLayout_2->addWidget(aim_ip, 1, 0, 1, 1);

        aim_port = new QWidget(ip_port);
        aim_port->setObjectName(QString::fromUtf8("aim_port"));
        horizontalLayout_7 = new QHBoxLayout(aim_port);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(aim_port);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3);

        aimPort = new QLineEdit(aim_port);
        aimPort->setObjectName(QString::fromUtf8("aimPort"));
        aimPort->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_7->addWidget(aimPort);


        gridLayout_2->addWidget(aim_port, 1, 1, 1, 1);


        verticalLayout->addWidget(ip_port);

        line = new QFrame(widget_udp);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 400, 501, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(widget_udp);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 580, 169, 38));
        horizontalLayout_8 = new QHBoxLayout(widget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        loopBtn = new QPushButton(widget);
        loopBtn->setObjectName(QString::fromUtf8("loopBtn"));

        horizontalLayout_8->addWidget(loopBtn);

        looptime = new QLineEdit(widget);
        looptime->setObjectName(QString::fromUtf8("looptime"));

        horizontalLayout_8->addWidget(looptime);

        label_21 = new QLabel(widget);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_8->addWidget(label_21);

        currTime = new QLabel(widget_udp);
        currTime->setObjectName(QString::fromUtf8("currTime"));
        currTime->setGeometry(QRect(390, 590, 91, 16));

        horizontalLayout_3->addWidget(widget_udp);

        line_2 = new QFrame(Widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_2);

        widget_control = new QWidget(Widget);
        widget_control->setObjectName(QString::fromUtf8("widget_control"));
        widget_data_record = new QWidget(widget_control);
        widget_data_record->setObjectName(QString::fromUtf8("widget_data_record"));
        widget_data_record->setGeometry(QRect(9, 9, 255, 361));
        label_8 = new QLabel(widget_data_record);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(9, 9, 48, 16));
        data_record_edit = new QPlainTextEdit(widget_data_record);
        data_record_edit->setObjectName(QString::fromUtf8("data_record_edit"));
        data_record_edit->setGeometry(QRect(9, 27, 210, 325));
        widget_setting = new QWidget(widget_control);
        widget_setting->setObjectName(QString::fromUtf8("widget_setting"));
        widget_setting->setGeometry(QRect(260, 30, 241, 381));
        gridLayout = new QGridLayout(widget_setting);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        branch_comboBox = new QComboBox(widget_setting);
        branch_comboBox->addItem(QString());
        branch_comboBox->addItem(QString());
        branch_comboBox->addItem(QString());
        branch_comboBox->setObjectName(QString::fromUtf8("branch_comboBox"));

        gridLayout->addWidget(branch_comboBox, 3, 1, 1, 2);

        band_comboBox = new QComboBox(widget_setting);
        band_comboBox->addItem(QString());
        band_comboBox->addItem(QString());
        band_comboBox->setObjectName(QString::fromUtf8("band_comboBox"));
        band_comboBox->setEditable(false);

        gridLayout->addWidget(band_comboBox, 0, 1, 1, 2);

        third_switch = new QLineEdit(widget_setting);
        third_switch->setObjectName(QString::fromUtf8("third_switch"));

        gridLayout->addWidget(third_switch, 6, 1, 1, 2);

        first_switch = new QLineEdit(widget_setting);
        first_switch->setObjectName(QString::fromUtf8("first_switch"));

        gridLayout->addWidget(first_switch, 4, 1, 1, 2);

        phaser = new QLineEdit(widget_setting);
        phaser->setObjectName(QString::fromUtf8("phaser"));

        gridLayout->addWidget(phaser, 9, 1, 1, 2);

        second_switch = new QLineEdit(widget_setting);
        second_switch->setObjectName(QString::fromUtf8("second_switch"));

        gridLayout->addWidget(second_switch, 5, 1, 1, 2);

        label_10 = new QLabel(widget_setting);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        channel_comboBox = new QComboBox(widget_setting);
        channel_comboBox->addItem(QString());
        channel_comboBox->addItem(QString());
        channel_comboBox->addItem(QString());
        channel_comboBox->addItem(QString());
        channel_comboBox->setObjectName(QString::fromUtf8("channel_comboBox"));

        gridLayout->addWidget(channel_comboBox, 1, 1, 1, 2);

        label_15 = new QLabel(widget_setting);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 6, 0, 1, 1);

        label_20 = new QLabel(widget_setting);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout->addWidget(label_20, 10, 0, 1, 1);

        convert_btn = new QPushButton(widget_setting);
        convert_btn->setObjectName(QString::fromUtf8("convert_btn"));

        gridLayout->addWidget(convert_btn, 12, 2, 1, 1);

        second_attenuator = new QLineEdit(widget_setting);
        second_attenuator->setObjectName(QString::fromUtf8("second_attenuator"));

        gridLayout->addWidget(second_attenuator, 8, 1, 1, 2);

        channel_freq = new QLineEdit(widget_setting);
        channel_freq->setObjectName(QString::fromUtf8("channel_freq"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(channel_freq->sizePolicy().hasHeightForWidth());
        channel_freq->setSizePolicy(sizePolicy);

        gridLayout->addWidget(channel_freq, 2, 1, 1, 2);

        calibrate = new QLineEdit(widget_setting);
        calibrate->setObjectName(QString::fromUtf8("calibrate"));

        gridLayout->addWidget(calibrate, 11, 1, 1, 2);

        label_17 = new QLabel(widget_setting);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 8, 0, 1, 1);

        label_12 = new QLabel(widget_setting);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 2, 0, 1, 1);

        delay = new QLineEdit(widget_setting);
        delay->setObjectName(QString::fromUtf8("delay"));

        gridLayout->addWidget(delay, 10, 1, 1, 2);

        label_11 = new QLabel(widget_setting);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        label_16 = new QLabel(widget_setting);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 7, 0, 1, 1);

        label_19 = new QLabel(widget_setting);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout->addWidget(label_19, 11, 0, 1, 1);

        label_13 = new QLabel(widget_setting);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 4, 0, 1, 1);

        label_9 = new QLabel(widget_setting);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        label_18 = new QLabel(widget_setting);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 9, 0, 1, 1);

        label_14 = new QLabel(widget_setting);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 5, 0, 1, 1);

        first_attenuator = new QLineEdit(widget_setting);
        first_attenuator->setObjectName(QString::fromUtf8("first_attenuator"));

        gridLayout->addWidget(first_attenuator, 7, 1, 1, 2);

        widget_btn = new QWidget(widget_control);
        widget_btn->setObjectName(QString::fromUtf8("widget_btn"));
        widget_btn->setGeometry(QRect(0, 370, 261, 41));
        horizontalLayout = new QHBoxLayout(widget_btn);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        array_setting_btn = new QPushButton(widget_btn);
        array_setting_btn->setObjectName(QString::fromUtf8("array_setting_btn"));

        horizontalLayout->addWidget(array_setting_btn);

        calibration_setting_btn = new QPushButton(widget_btn);
        calibration_setting_btn->setObjectName(QString::fromUtf8("calibration_setting_btn"));

        horizontalLayout->addWidget(calibration_setting_btn);

        read_data_btn = new QPushButton(widget_btn);
        read_data_btn->setObjectName(QString::fromUtf8("read_data_btn"));

        horizontalLayout->addWidget(read_data_btn);

        clear_data_btn = new QPushButton(widget_btn);
        clear_data_btn->setObjectName(QString::fromUtf8("clear_data_btn"));

        horizontalLayout->addWidget(clear_data_btn);

        rough_ctrl = new QRadioButton(widget_control);
        rough_ctrl->setObjectName(QString::fromUtf8("rough_ctrl"));
        rough_ctrl->setGeometry(QRect(290, 450, 89, 16));
        rough_ctrl->setChecked(true);
        accurate_ctrl = new QRadioButton(widget_control);
        accurate_ctrl->setObjectName(QString::fromUtf8("accurate_ctrl"));
        accurate_ctrl->setGeometry(QRect(290, 480, 89, 16));
        accurate_ctrl->setChecked(false);

        horizontalLayout_3->addWidget(widget_control);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\266\210\346\201\257\350\256\260\345\275\225", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\346\241\206", nullptr));
        send_size->setText(QString());
        count->setText(QString());
        label_22->setText(QCoreApplication::translate("Widget", "\345\255\227\350\212\202(\346\224\266/\345\217\221)", nullptr));
        sendBtn->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        resetnumBtn->setText(QCoreApplication::translate("Widget", "\351\207\215\346\226\260\350\256\241\346\225\260", nullptr));
        clearBtn_send->setText(QCoreApplication::translate("Widget", "<<", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244", nullptr));
        clearBtn->setText(QCoreApplication::translate("Widget", ">>", nullptr));
        openBtn->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200", nullptr));
        closeBtn->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\346\234\254\345\234\260IP", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\234\254\345\234\260\347\253\257\345\217\243", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\347\233\256\346\240\207IP", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\347\233\256\346\240\207\347\253\257\345\217\243", nullptr));
        loopBtn->setText(QCoreApplication::translate("Widget", "\345\276\252\347\216\257\345\217\221\351\200\201", nullptr));
        label_21->setText(QCoreApplication::translate("Widget", "ms", nullptr));
        currTime->setText(QCoreApplication::translate("Widget", "\346\227\266\351\227\264", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\350\256\260\345\275\225", nullptr));
        branch_comboBox->setItemText(0, QCoreApplication::translate("Widget", "A\346\224\257\350\267\257", nullptr));
        branch_comboBox->setItemText(1, QCoreApplication::translate("Widget", "B\346\224\257\350\267\257", nullptr));
        branch_comboBox->setItemText(2, QCoreApplication::translate("Widget", "C\346\224\257\350\267\257", nullptr));

        band_comboBox->setItemText(0, QCoreApplication::translate("Widget", "Ka", nullptr));
        band_comboBox->setItemText(1, QCoreApplication::translate("Widget", "2-18GHz", nullptr));

        label_10->setText(QCoreApplication::translate("Widget", "\351\200\232\351\201\223", nullptr));
        channel_comboBox->setItemText(0, QCoreApplication::translate("Widget", "9", nullptr));
        channel_comboBox->setItemText(1, QCoreApplication::translate("Widget", "10", nullptr));
        channel_comboBox->setItemText(2, QCoreApplication::translate("Widget", "11", nullptr));
        channel_comboBox->setItemText(3, QCoreApplication::translate("Widget", "12", nullptr));

        label_15->setText(QCoreApplication::translate("Widget", "\344\270\211\347\272\247\345\274\200\345\205\263", nullptr));
        label_20->setText(QCoreApplication::translate("Widget", "\345\273\266\346\227\266\345\231\250", nullptr));
        convert_btn->setText(QCoreApplication::translate("Widget", "\347\241\256\350\256\244", nullptr));
        label_17->setText(QCoreApplication::translate("Widget", "\350\241\260\345\207\217\345\231\2502", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "\351\200\232\351\201\223\351\242\221\347\216\207", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "\346\224\257\350\267\257", nullptr));
        label_16->setText(QCoreApplication::translate("Widget", "\350\241\260\345\207\217\345\231\2501", nullptr));
        label_19->setText(QCoreApplication::translate("Widget", "\346\240\241\345\207\206", nullptr));
        label_13->setText(QCoreApplication::translate("Widget", "\344\270\200\347\272\247\345\274\200\345\205\263", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "\346\263\242\346\256\265", nullptr));
        label_18->setText(QCoreApplication::translate("Widget", "\347\247\273\347\233\270\345\231\250", nullptr));
        label_14->setText(QCoreApplication::translate("Widget", "\344\272\214\347\272\247\345\274\200\345\205\263", nullptr));
        array_setting_btn->setText(QCoreApplication::translate("Widget", "\351\230\265\345\210\227\350\256\276\347\275\256", nullptr));
        calibration_setting_btn->setText(QCoreApplication::translate("Widget", "\346\240\241\345\207\206\350\256\276\347\275\256", nullptr));
        read_data_btn->setText(QCoreApplication::translate("Widget", "\350\257\273\345\217\226\346\225\260\346\215\256", nullptr));
        clear_data_btn->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\346\225\260\346\215\256", nullptr));
        rough_ctrl->setText(QCoreApplication::translate("Widget", "\347\262\227\346\216\247", nullptr));
        accurate_ctrl->setText(QCoreApplication::translate("Widget", "\347\262\276\346\216\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
