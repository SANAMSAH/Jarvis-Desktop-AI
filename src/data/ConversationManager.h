#pragma once

#include <QObject>
#include "Conversation.h"
class ConversationManager : public QObject
{
    Q_OBJECT

public:
    explicit ConversationManager(QObject* parent = nullptr);
    ~ConversationManager() override;

    bool Initialize();

    void CreateConversation();

    Conversation* GetConversation(size_t index);

    size_t Count() const;

    Conversation* CurrentConversation() const;

    void SetCurrentConversation(Conversation* conversation);

public:

    void AddUserMessage(const QString& text);

    void AddAssistantMessage(const QString& text);

    void AddSystemMessage(const QString& text);

private:

    Conversation* m_currentConversation = nullptr;
    std::vector<std::unique_ptr<Conversation>> m_conversations;

signals:
        void ConversationCreated(Conversation* conversation);
        void CurrentConversationChanged(Conversation* conversation);
        void ConversationUpdated(Conversation* conversation);
};