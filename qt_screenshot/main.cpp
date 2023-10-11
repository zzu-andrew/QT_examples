#include <QApplication>
#include <QPushButton>

#include "fireshot.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    // close all windows not close app
    a.setQuitOnLastWindowClosed(false);

    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
