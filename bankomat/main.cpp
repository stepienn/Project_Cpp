#include "mainwindow.h"
//#include "Konto.h"
//#include "Bankomat.h"
#include <QApplication>
#include "locale.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    QApplication a(argc, argv);
    MainWindow w;

    QWidget mainWidget;


    QString stylesheet =
        "QPushButton, QTextEdit {"
        "    border-style: solid;"
        "    border-width: 2px;"
        "    border-color: black;"
        "background-color: white;"
        "border-radius: 8px;"
        "}"
        "QLabel{"
        "color: black;"
        "}"
        "QTextEdit{"
        "background-color:#E9E9E9;"
        "font-weight: 700 "
        "}";

    w.setStyleSheet(stylesheet);
    w.setFixedSize(780, 520);

    w.show();
    return a.exec();
}
