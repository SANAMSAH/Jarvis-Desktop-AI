#include "Message.h"

Message::Message()
{
    m_timestamp = QDateTime::currentDateTime();
}

QString Message::Text() const
{
    return m_text;
}

void Message::SetText(const QString& text)
{
    m_text = text;
}

MessageRole Message::Role() const
{
    return m_role;
}

void Message::SetRole(MessageRole role)
{
    m_role = role;
}

QDateTime Message::Timestamp() const
{
    return m_timestamp;
}