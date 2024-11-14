/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_udp;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPlainTextEdit *recordEdit;
    QWidget *widget_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *localPort;
    QLabel *label_2;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *aimPort;
    QLabel *label_3;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *aimIP;
    QLabel *label_4;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *localIP;
    QLabel *label_7;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *sendEdit;
    QLabel *label_5;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_8;
    QLabel *count;
    QLabel *label_6;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *openBtn;
    QPushButton *sendBtn;
    QPushButton *closeBtn;
    QPushButton *resetnumBtn;
    QPushButton *clearBtn;
    QWidget *widget_control;
    QWidget *widget_data_record;
    QLabel *label_8;
    QPlainTextEdit *data_record_edit;
    QWidget *widget_setting;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QComboBox *band_comboBox;
    QLabel *label_10;
    QComboBox *channel_comboBox;
    QLabel *label_12;
    QLineEdit *channel_freq;
    QLabel *label_11;
    QComboBox *branch_comboBox;
    QLabel *label_13;
    QLineEdit *first_switch;
    QLabel *label_14;
    QLineEdit *second_switch;
    QLabel *label_15;
    QLineEdit *third_switch;
    QLabel *label_16;
    QLineEdit *first_attenuator;
    QLabel *label_17;
    QLineEdit *second_attenuator;
    QLabel *label_18;
    QLineEdit *phaser;
    QLabel *label_20;
    QLineEdit *delay;
    QLabel *label_19;
    QLineEdit *calibrate;
    QPushButton *convert_btn;
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
            Widget->setObjectName("Widget");
        Widget->resize(1014, 617);
        horizontalLayout_3 = new QHBoxLayout(Widget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        widget_udp = new QWidget(Widget);
        widget_udp->setObjectName("widget_udp");
        widget = new QWidget(widget_udp);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(9, 9, 461, 301));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        recordEdit = new QPlainTextEdit(widget);
        recordEdit->setObjectName("recordEdit");
        recordEdit->setEnabled(true);

        verticalLayout->addWidget(recordEdit);

        widget_3 = new QWidget(widget_udp);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(10, 310, 351, 301));
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(9, 9, 223, 270));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName("widget_6");
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        localPort = new QLineEdit(widget_6);
        localPort->setObjectName("localPort");

        horizontalLayout_4->addWidget(localPort);

        label_2 = new QLabel(widget_6);
        label_2->setObjectName("label_2");

        horizontalLayout_4->addWidget(label_2);


        verticalLayout_2->addWidget(widget_6);

        widget_9 = new QWidget(widget_2);
        widget_9->setObjectName("widget_9");
        horizontalLayout_7 = new QHBoxLayout(widget_9);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        aimPort = new QLineEdit(widget_9);
        aimPort->setObjectName("aimPort");

        horizontalLayout_7->addWidget(aimPort);

        label_3 = new QLabel(widget_9);
        label_3->setObjectName("label_3");

        horizontalLayout_7->addWidget(label_3);


        verticalLayout_2->addWidget(widget_9);

        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName("widget_7");
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        aimIP = new QLineEdit(widget_7);
        aimIP->setObjectName("aimIP");

        horizontalLayout_5->addWidget(aimIP);

        label_4 = new QLabel(widget_7);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);


        verticalLayout_2->addWidget(widget_7);

        widget_8 = new QWidget(widget_2);
        widget_8->setObjectName("widget_8");
        horizontalLayout_6 = new QHBoxLayout(widget_8);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        localIP = new QLineEdit(widget_8);
        localIP->setObjectName("localIP");

        horizontalLayout_6->addWidget(localIP);

        label_7 = new QLabel(widget_8);
        label_7->setObjectName("label_7");

        horizontalLayout_6->addWidget(label_7);


        verticalLayout_2->addWidget(widget_8);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName("widget_4");
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        sendEdit = new QLineEdit(widget_4);
        sendEdit->setObjectName("sendEdit");

        horizontalLayout_2->addWidget(sendEdit);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName("label_5");

        horizontalLayout_2->addWidget(label_5);


        verticalLayout_2->addWidget(widget_4);

        widget_10 = new QWidget(widget_2);
        widget_10->setObjectName("widget_10");
        horizontalLayout_8 = new QHBoxLayout(widget_10);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        count = new QLabel(widget_10);
        count->setObjectName("count");
        count->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_8->addWidget(count);

        label_6 = new QLabel(widget_10);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_8->addWidget(label_6);


        verticalLayout_2->addWidget(widget_10);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(249, 9, 91, 231));
        verticalLayout_3 = new QVBoxLayout(widget_5);
        verticalLayout_3->setObjectName("verticalLayout_3");
        openBtn = new QPushButton(widget_5);
        openBtn->setObjectName("openBtn");

        verticalLayout_3->addWidget(openBtn);

        sendBtn = new QPushButton(widget_5);
        sendBtn->setObjectName("sendBtn");

        verticalLayout_3->addWidget(sendBtn);

        closeBtn = new QPushButton(widget_5);
        closeBtn->setObjectName("closeBtn");

        verticalLayout_3->addWidget(closeBtn);

        resetnumBtn = new QPushButton(widget_5);
        resetnumBtn->setObjectName("resetnumBtn");

        verticalLayout_3->addWidget(resetnumBtn);

        clearBtn = new QPushButton(widget_5);
        clearBtn->setObjectName("clearBtn");

        verticalLayout_3->addWidget(clearBtn);


        horizontalLayout_3->addWidget(widget_udp);

        widget_control = new QWidget(Widget);
        widget_control->setObjectName("widget_control");
        widget_data_record = new QWidget(widget_control);
        widget_data_record->setObjectName("widget_data_record");
        widget_data_record->setGeometry(QRect(9, 9, 255, 522));
        label_8 = new QLabel(widget_data_record);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(9, 9, 48, 16));
        data_record_edit = new QPlainTextEdit(widget_data_record);
        data_record_edit->setObjectName("data_record_edit");
        data_record_edit->setGeometry(QRect(9, 27, 237, 486));
        widget_setting = new QWidget(widget_control);
        widget_setting->setObjectName("widget_setting");
        widget_setting->setGeometry(QRect(260, 30, 241, 381));
        gridLayout = new QGridLayout(widget_setting);
        gridLayout->setObjectName("gridLayout");
        label_9 = new QLabel(widget_setting);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        band_comboBox = new QComboBox(widget_setting);
        band_comboBox->addItem(QString());
        band_comboBox->addItem(QString());
        band_comboBox->setObjectName("band_comboBox");
        band_comboBox->setEditable(false);

        gridLayout->addWidget(band_comboBox, 0, 1, 1, 2);

        label_10 = new QLabel(widget_setting);
        label_10->setObjectName("label_10");
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        channel_comboBox = new QComboBox(widget_setting);
        channel_comboBox->addItem(QString());
        channel_comboBox->addItem(QString());
        channel_comboBox->addItem(QString());
        channel_comboBox->addItem(QString());
        channel_comboBox->setObjectName("channel_comboBox");

        gridLayout->addWidget(channel_comboBox, 1, 1, 1, 2);

        label_12 = new QLabel(widget_setting);
        label_12->setObjectName("label_12");
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_12, 2, 0, 1, 1);

        channel_freq = new QLineEdit(widget_setting);
        channel_freq->setObjectName("channel_freq");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(channel_freq->sizePolicy().hasHeightForWidth());
        channel_freq->setSizePolicy(sizePolicy);

        gridLayout->addWidget(channel_freq, 2, 1, 1, 2);

        label_11 = new QLabel(widget_setting);
        label_11->setObjectName("label_11");
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        branch_comboBox = new QComboBox(widget_setting);
        branch_comboBox->addItem(QString());
        branch_comboBox->addItem(QString());
        branch_comboBox->addItem(QString());
        branch_comboBox->setObjectName("branch_comboBox");

        gridLayout->addWidget(branch_comboBox, 3, 1, 1, 2);

        label_13 = new QLabel(widget_setting);
        label_13->setObjectName("label_13");
        label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_13, 4, 0, 1, 1);

        first_switch = new QLineEdit(widget_setting);
        first_switch->setObjectName("first_switch");

        gridLayout->addWidget(first_switch, 4, 1, 1, 2);

        label_14 = new QLabel(widget_setting);
        label_14->setObjectName("label_14");
        label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_14, 5, 0, 1, 1);

        second_switch = new QLineEdit(widget_setting);
        second_switch->setObjectName("second_switch");

        gridLayout->addWidget(second_switch, 5, 1, 1, 2);

        label_15 = new QLabel(widget_setting);
        label_15->setObjectName("label_15");
        label_15->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_15, 6, 0, 1, 1);

        third_switch = new QLineEdit(widget_setting);
        third_switch->setObjectName("third_switch");

        gridLayout->addWidget(third_switch, 6, 1, 1, 2);

        label_16 = new QLabel(widget_setting);
        label_16->setObjectName("label_16");
        label_16->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_16, 7, 0, 1, 1);

        first_attenuator = new QLineEdit(widget_setting);
        first_attenuator->setObjectName("first_attenuator");

        gridLayout->addWidget(first_attenuator, 7, 1, 1, 2);

        label_17 = new QLabel(widget_setting);
        label_17->setObjectName("label_17");
        label_17->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_17, 8, 0, 1, 1);

        second_attenuator = new QLineEdit(widget_setting);
        second_attenuator->setObjectName("second_attenuator");

        gridLayout->addWidget(second_attenuator, 8, 1, 1, 2);

        label_18 = new QLabel(widget_setting);
        label_18->setObjectName("label_18");
        label_18->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_18, 9, 0, 1, 1);

        phaser = new QLineEdit(widget_setting);
        phaser->setObjectName("phaser");

        gridLayout->addWidget(phaser, 9, 1, 1, 2);

        label_20 = new QLabel(widget_setting);
        label_20->setObjectName("label_20");
        label_20->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_20, 10, 0, 1, 1);

        delay = new QLineEdit(widget_setting);
        delay->setObjectName("delay");

        gridLayout->addWidget(delay, 10, 1, 1, 2);

        label_19 = new QLabel(widget_setting);
        label_19->setObjectName("label_19");
        label_19->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_19, 11, 0, 1, 1);

        calibrate = new QLineEdit(widget_setting);
        calibrate->setObjectName("calibrate");

        gridLayout->addWidget(calibrate, 11, 1, 1, 2);

        convert_btn = new QPushButton(widget_setting);
        convert_btn->setObjectName("convert_btn");

        gridLayout->addWidget(convert_btn, 12, 2, 1, 1);

        widget_btn = new QWidget(widget_control);
        widget_btn->setObjectName("widget_btn");
        widget_btn->setGeometry(QRect(9, 537, 255, 41));
        horizontalLayout = new QHBoxLayout(widget_btn);
        horizontalLayout->setObjectName("horizontalLayout");
        array_setting_btn = new QPushButton(widget_btn);
        array_setting_btn->setObjectName("array_setting_btn");

        horizontalLayout->addWidget(array_setting_btn);

        calibration_setting_btn = new QPushButton(widget_btn);
        calibration_setting_btn->setObjectName("calibration_setting_btn");

        horizontalLayout->addWidget(calibration_setting_btn);

        read_data_btn = new QPushButton(widget_btn);
        read_data_btn->setObjectName("read_data_btn");

        horizontalLayout->addWidget(read_data_btn);

        clear_data_btn = new QPushButton(widget_btn);
        clear_data_btn->setObjectName("clear_data_btn");

        horizontalLayout->addWidget(clear_data_btn);

        rough_ctrl = new QRadioButton(widget_control);
        rough_ctrl->setObjectName("rough_ctrl");
        rough_ctrl->setGeometry(QRect(290, 450, 89, 16));
        rough_ctrl->setChecked(true);
        accurate_ctrl = new QRadioButton(widget_control);
        accurate_ctrl->setObjectName("accurate_ctrl");
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
        label_2->setText(QCoreApplication::translate("Widget", "\346\234\254\345\234\260\347\253\257\345\217\243", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\347\233\256\346\240\207\347\253\257\345\217\243", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\347\233\256\346\240\207IP", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\346\234\254\345\234\260IP", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\346\241\206", nullptr));
        count->setText(QString());
        label_6->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266/\345\217\221\351\200\201", nullptr));
        openBtn->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200", nullptr));
        sendBtn->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        closeBtn->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
        resetnumBtn->setText(QCoreApplication::translate("Widget", "\351\207\215\346\226\260\350\256\241\346\225\260", nullptr));
        clearBtn->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\350\256\260\345\275\225", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "\346\263\242\346\256\265", nullptr));
        band_comboBox->setItemText(0, QCoreApplication::translate("Widget", "Ka", nullptr));
        band_comboBox->setItemText(1, QCoreApplication::translate("Widget", "2-18GHz", nullptr));

        label_10->setText(QCoreApplication::translate("Widget", "\351\200\232\351\201\223", nullptr));
        channel_comboBox->setItemText(0, QCoreApplication::translate("Widget", "9", nullptr));
        channel_comboBox->setItemText(1, QCoreApplication::translate("Widget", "10", nullptr));
        channel_comboBox->setItemText(2, QCoreApplication::translate("Widget", "11", nullptr));
        channel_comboBox->setItemText(3, QCoreApplication::translate("Widget", "12", nullptr));

        label_12->setText(QCoreApplication::translate("Widget", "\351\200\232\351\201\223\351\242\221\347\216\207", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "\346\224\257\350\267\257", nullptr));
        branch_comboBox->setItemText(0, QCoreApplication::translate("Widget", "A\346\224\257\350\267\257", nullptr));
        branch_comboBox->setItemText(1, QCoreApplication::translate("Widget", "B\346\224\257\350\267\257", nullptr));
        branch_comboBox->setItemText(2, QCoreApplication::translate("Widget", "C\346\224\257\350\267\257", nullptr));

        label_13->setText(QCoreApplication::translate("Widget", "\344\270\200\347\272\247\345\274\200\345\205\263", nullptr));
        label_14->setText(QCoreApplication::translate("Widget", "\344\272\214\347\272\247\345\274\200\345\205\263", nullptr));
        label_15->setText(QCoreApplication::translate("Widget", "\344\270\211\347\272\247\345\274\200\345\205\263", nullptr));
        label_16->setText(QCoreApplication::translate("Widget", "\350\241\260\345\207\217\345\231\2501", nullptr));
        label_17->setText(QCoreApplication::translate("Widget", "\350\241\260\345\207\217\345\231\2502", nullptr));
        label_18->setText(QCoreApplication::translate("Widget", "\347\247\273\347\233\270\345\231\250", nullptr));
        label_20->setText(QCoreApplication::translate("Widget", "\345\273\266\346\227\266\345\231\250", nullptr));
        label_19->setText(QCoreApplication::translate("Widget", "\346\240\241\345\207\206", nullptr));
        convert_btn->setText(QCoreApplication::translate("Widget", "\347\241\256\350\256\244", nullptr));
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
