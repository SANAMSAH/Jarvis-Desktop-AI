#include "Conversation.h"

Conversation::Conversation()
{
    m_id = QUuid::createUuid().toString();
    m_createdAt = QDateTime::currentDateTime();
}

QString Conversation::Id() const
{
    return m_id;
}

QString Conversation::Title() const
{
    return m_title;
}

void Conversation::SetTitle(const QString& title)
{
    m_title = title;
}
void Conversation::AddMessage(std::unique_ptr<Message> message)
{
    m_messages.push_back(std::move(message));
}
Message* Conversation::GetMessage(size_t index) const
{
    if (index >= m_messages.size())
        return nullptr;

    return m_messages[index].get();
}
size_t Conversation::MessageCount() const
{
    return m_messages.size();
}