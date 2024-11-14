#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
//    map<int, int> num_ctrlcode_map = create_num_ctrlcode_map();
//    for(auto it : num_ctrlcode_map)
//    {
//        hex_bin_new(it.second);
//    }
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
