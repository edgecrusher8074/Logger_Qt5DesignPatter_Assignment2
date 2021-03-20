#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>

/**
 * @brief Assignment 2 for Qt5 Design Patterns Tutorial on Udemy.
 * @todo Make a simple that logs stdio to a file.
 * @author edgecrusher8074
 */
#include "logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream stream(stdin);
    QString line;

    Logger fileLogger("stdin.log");

    while (stream.readLineInto(&line)) {
        fileLogger.add(line);
    }
    return a.exec();
}
