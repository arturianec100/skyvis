#include "errorinfo.h"

ErrorInfo::ErrorInfo() :
    m_category(QString("unknown")), m_message(QString("Unknown error")),
    m_reason(QString("Improperly constructed ErrorInfo"))
{

}

ErrorInfo::ErrorInfo(QString category, QString message, QString reason) :
    m_category(category), m_message(message), m_reason(reason)
{

}
