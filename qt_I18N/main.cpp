#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QDebug>


/*
 * 执行文件翻译的过程
 * 1. 使用lupdate工具根据 pro文件获得ts文件 lupdate -pro qt_I18N.pro -ts tra.ts
 * lupdate -pro myI18N.pro
 * 2. 使用lrelease工具根据ts文件获得qm文件 lrelease [options] ts-files [-qm qm-file]
 * lrelease myI18N_zh_CN.ts
 * 3. 函数中指定翻译文件
 * 如下主文件中所示
 * 需要注意的是，翻译需要依赖提取tr中的文本内容，因此需要翻译的地方需要使用tr处理对应的文本
 * 当然以上步骤也能经过 工具->外部->Qt语言专家->(lupdate/lrelease)来完成
*/





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 如果想做成自动根据当地语言环境来设置翻译文件，可以使用 QLocale::system().name() 来获取
    // 这样就能根据当地语言来加载不同的翻译qm文件了
    // qDebug() << QLocale::system().name();   // "zh_CN"
    QTranslator translator;
    translator.load("../qt_I18N/tra.qm");
    a.installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
