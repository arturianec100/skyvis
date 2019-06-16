#ifndef ERRORINFO_H
#define ERRORINFO_H

#include <QtCore>

class ErrorInfo : public QException
{
public:    
    ErrorInfo();
    ErrorInfo(QString m_category, QString m_message, QString m_reason);
    ErrorInfo(ErrorInfo const& other) = default;
    virtual ~ErrorInfo() override = default;

    ErrorInfo & operator = (const ErrorInfo &other) = default;

private:
    QString m_category;
    QString m_message;
    QString m_reason;
};

Q_DECLARE_METATYPE(ErrorInfo)

#endif // ERRORINFO_H
