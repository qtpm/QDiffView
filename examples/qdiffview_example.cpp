#include "qdiffview/qdiffview.h"
#include <QApplication>
#include <QTranslator>

QString oldSource = "abc\n" // same
                    "def\n" // removed
                    "ghi\n"
                    "jkl\n"
                    "mno\n" // remove one char insert one char
                    "pqr\n"
                    "stu\n" // remove one char
                    "vwx\n"
                    "yz\n" // insert one char
                    "1\n"
                    "2\n"
                    "3\n"
                    "4\n"
                    "5\n"
                    "6\n"
                    "7\n"
                    "8\n"
                    "9\n";

QString newSource = "abc\n"
                    "ghi\n"
                    "123\n" // inserted
                    "jkl\n"
                    "no!\n" // remove one char insert one char
                    "pqr\n"
                    "su\n" // remove one char
                    "vwx\n"
                    "yz!\n" // insert one char
                    "1\n"
                    "2\n"
                    "3\n"
                    "4\n"
                    "5\n"
                    "6\n"
                    "7\n"
                    "8\n"
                    "9\n";

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QTranslator translator;
    if (translator.load(QLocale::system(), "qdiffview", "_", ":/translations")) {
        app.installTranslator(&translator);
    }

    qdiffview::QDiffView *view = new qdiffview::QDiffView();
    view->setSource(oldSource, newSource);
    view->show();

    return app.exec();
}
