#pragma once

#include <QString>
#include <QDateTime>
#include <QUuid>
#include <memory>
#include <vector>

#include "Message.h"


class Conversation
{
public:
    Conversation();

    QString Id() const;
    QString Title() const;

    void SetTitle(const QString& title);

    
    void AddMessage(std::unique_ptr<Message> message);

    Message* GetMessage(size_t index) const;

    size_t MessageCount() const;
private:
    QString m_id;
    QString m_title;
    QDateTime m_createdAt;

    std::vector<std::unique_ptr<Message>> m_messages;
};