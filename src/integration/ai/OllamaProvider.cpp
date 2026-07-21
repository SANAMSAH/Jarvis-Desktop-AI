#include "OllamaProvider.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>

OllamaProvider::OllamaProvider(QObject* parent)
    : IAIProvider(parent)
{
}

OllamaProvider::~OllamaProvider() = default;

bool OllamaProvider::Initialize()
{
    m_networkManager = new QNetworkAccessManager(this);

    return true;
}

void OllamaProvider::SendPrompt(const QString& prompt)
{
    Q_UNUSED(prompt);

    m_isBusy = true;

    emit ResponseStarted();
}

void OllamaProvider::CancelRequest()
{
    if (m_currentReply)
    {
        m_currentReply->abort();
    }

    m_isBusy = false;
}

bool OllamaProvider::IsBusy() const
{
    return m_isBusy;
}