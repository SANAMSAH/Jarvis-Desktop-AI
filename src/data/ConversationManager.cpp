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

void ConversationManager::AddUserMessage(const QString& text)
{
    if (!m_currentConversation)
        return;

    auto message = std::make_unique<Message>();

    message->SetRole(MessageRole::User);
    message->SetText(text);

    m_currentConversation->AddMessage(std::move(message));

    emit ConversationUpdated(m_currentConversation);
}

void ConversationManager::AddAssistantMessage(const QString& text)
{
    if (!m_currentConversation)
        return;

    auto message = std::make_unique<Message>();

    message->SetRole(MessageRole::Assistant);
    message->SetText(text);

    m_currentConversation->AddMessage(std::move(message));

    emit ConversationUpdated(m_currentConversation);
}

void ConversationManager::AddSystemMessage(const QString& text)
{
    if (!m_currentConversation)
        return;

    auto message = std::make_unique<Message>();

    message->SetRole(MessageRole::System);
    message->SetText(text);

    m_currentConversation->AddMessage(std::move(message));

    emit ConversationUpdated(m_currentConversation);
}

void ConversationManager::AddThinkingMessage()
{

    if (!m_currentConversation)
        return;

    auto message = std::make_unique<Message>();

    message->SetRole(MessageRole::Assistant);
    message->SetText("is thinking..."); 
    message->SetThinking(true);

    m_currentConversation->AddMessage(std::move(message));

    emit ConversationUpdated(m_currentConversation);
}

void ConversationManager::CompleteThinkingMessage(const QString& response)
{
    if (!m_currentConversation)
        return;

    Message* message = m_currentConversation->LastMessage();

    if (!message)
        return;

    if (!message->IsThinking())
        return;

    message->SetThinking(false);

    message->SetText(response);

    emit ConversationUpdated(m_currentConversation);
}


