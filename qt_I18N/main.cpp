#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>


/*
 * 执行文件翻译的过程
 * 1. 使用lupdate工具根据 pro文件获得ts文件 lupdate -pro qt_I18N.pro -ts tra.ts
 * lupdate -pro myI18N.pro
 * 2. 使用lrelease工具根据ts文件获得qm文件 lrelease [options] ts-files [-qm qm-file]
 * lrelease myI18N_zh_CN.ts
 * 3. 函数中指定翻译文件
 * 如下主文件中所示
 * 需要注意的是，翻译需要依赖提取tr中的文本内容，因此需要翻译的地方需要使用tr处理对应的文本
 *
*/





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QTranslator translator;
    translator.load("../qt_I18N/tra.qm");
    a.installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
