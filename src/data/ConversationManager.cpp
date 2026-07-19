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