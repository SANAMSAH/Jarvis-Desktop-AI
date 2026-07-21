#include "AIManager.h"
#include "../integration/ai/IAIProvider.h"
#include "OllamaProvider.h"
AIManager::AIManager(QObject* parent)
    : QObject(parent)
{

    m_provider = std::make_unique<OllamaProvider>(this);

    connect(m_provider.get(),
        &IAIProvider::ResponseStarted,
        this,
        &AIManager::ResponseStarted);

    connect(m_provider.get(),
        &IAIProvider::ResponseChunkReceived,
        this,
        &AIManager::ResponseChunkReceived);

    connect(m_provider.get(),
        &IAIProvider::ResponseCompleted,
        this,
        &AIManager::ResponseCompleted);

    connect(m_provider.get(),
        &IAIProvider::ErrorOccurred,
        this,
        &AIManager::ErrorOccurred);

}

AIManager::~AIManager() = default;

bool AIManager::Initialize()
{
    if(!m_provider)
		return false;

	return m_provider->Initialize();
}

bool AIManager::IsBusy() const
{
    return m_provider && m_provider->IsBusy();
}

void AIManager::SendPrompt(const QString& prompt)
{
    if (!m_provider)
    {
        emit ErrorOccurred("No AI provider is configured.");
        return;
    }

    m_provider->SendPrompt(prompt);
}

void AIManager::CancelRequest()
{
    if (m_provider)
        m_provider->CancelRequest();
}