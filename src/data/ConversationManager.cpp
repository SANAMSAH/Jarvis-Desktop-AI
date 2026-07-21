#include "ConversationManager.h"

ConversationManager::ConversationManager(QObject* parent)
    : QObject(parent)
{
}

ConversationManager::~ConversationManager() = default;

bool ConversationManager::Initialize()
{
    return true;
}

void ConversationManager::CreateConversation()
{
    static int count = 1;

    auto conversation = std::make_unique<Conversation>();

    conversation->SetTitle(
        QString("New Chat %1").arg(count++)
    );

    auto message = std::make_unique<Message>();

    message->SetRole(MessageRole::Assistant);

    message->SetText("Hello! I'm Jarvis 👋. How can I help you today?");

    conversation->AddMessage(std::move(message));

    Conversation* ptr = conversation.get();
    SetCurrentConversation(ptr);
    m_conversations.push_back(std::move(conversation));

    emit ConversationCreated(ptr);
}

Conversation* ConversationManager::GetConversation(size_t index)
{
    if (index >= m_conversations.size())
        return nullptr;

    return m_conversations[index].get();
}

size_t ConversationManager::Count() const
{
    return m_conversations.size();
}

Conversation* ConversationManager::CurrentConversation() const
{
    return m_currentConversation;
}

void ConversationManager::SetCurrentConversation(Conversation* conversation)
{
    m_currentConversation = conversation;
    emit CurrentConversationChanged(conversation);
}
