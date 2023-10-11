#include <QApplication>
#include <QDesktopWidget>
#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QTreeView>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription("Qt Dir View Example");
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption dontUseCustomDirectoryIconsOption("c", "Set QFileIconProvider::DontUseCustomDirectoryIcons");
    parser.addOption(dontUseCustomDirectoryIconsOption);
    parser.addPositionalArgument("directory", "The directory to start in.");
    parser.process(app);
    const QString rootPath = parser.positionalArguments().isEmpty()
        ? QString() : parser.positionalArguments().first();

    QFileSystemModel model;
    model.setRootPath("");
    if (parser.isSet(dontUseCustomDirectoryIconsOption))
        model.iconProvider()->setOptions(QFileIconProvider::DontUseCustomDirectoryIcons);
    QTreeView tree;
    tree.setModel(&model);
    if (!rootPath.isEmpty()) {
        const QModelIndex rootIndex = model.index(QDir::cleanPath(rootPath));
        if (rootIndex.isValid())
            tree.setRootIndex(rootIndex);
    }

    // Demonstrating look and feel features
    tree.setAnimated(false);
    tree.setIndentation(20);
    tree.setSortingEnabled(true);
    const QSize availableSize = QApplication::desktop()->availableGeometry(&tree).size();
    tree.resize(availableSize / 2);
    tree.setColumnWidth(0, tree.width() / 3);

    tree.setWindowTitle(QObject::tr("Dir View"));
    tree.show();

    return app.exec();
}
