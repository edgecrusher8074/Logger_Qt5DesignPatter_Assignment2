#include "logger.h"

#include <QFile>
#include <QTextStream>
#include <QDateTime>

#include <iostream>

Logger::Logger(const QString &fileName, QObject *parent)
    : QObject(parent)
    , m_fileName(fileName)
{
}

Logger::~Logger() = default;

void Logger::add(const QString &message)
{
    QFile file(m_fileName);
    if(!file.open(QFile::WriteOnly | QFile::Append))
        throw std::ios_base::failure("Could not open: " + m_fileName.toStdString());

    QTextStream output(&file);

    output << getTimeStamp() << ": '" << message << "'\n";
}

QString Logger::getTimeStamp() const
{
    auto current = QDateTime::currentDateTime();
    return current.toString(QString("yyyy-MM-dd HH:mm:ss.zzz"));
}
