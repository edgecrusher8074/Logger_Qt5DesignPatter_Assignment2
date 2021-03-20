#pragma once

#include <QObject>

/**
 * @brief The Logger class
 * @details A simple logger for writing data into a file.
 */
class Logger : public QObject
{
    Q_OBJECT
public:
    Logger(const QString& fileName, QObject *parent =nullptr);
    ~Logger();

    void add(const QString& message);

protected:
    void initialize();
    QString getTimeStamp() const;

private:
    QString m_fileName;
};

