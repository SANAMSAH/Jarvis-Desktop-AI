#include "OllamaProvider.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QUrl>


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
    QJsonObject message;

    message["role"] = "user";

    message["content"] = prompt;

    QJsonArray messages;
    messages.append(message);

	QJsonObject requestBody;

	requestBody["model"] = "qwen2.5-coder:3b";

	requestBody["messages"] = messages;

	requestBody["stream"] = false;

	QByteArray jsonData = QJsonDocument(requestBody).toJson(); 

	QNetworkRequest request(QUrl("http://localhost:11434/api/chat"));

    request.setHeader(QNetworkRequest::ContentTypeHeader,
        "application/json");

    m_currentReply =
        m_networkManager->post(
            request,
            jsonData);

    connect(m_currentReply,
        &QNetworkReply::finished,
        this,
        &OllamaProvider::OnReplyFinished);
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
void OllamaProvider::OnReplyFinished()
{
    if (!m_currentReply)
        return;

    // Handle network error
    if (m_currentReply->error() != QNetworkReply::NoError)
    {
        emit ErrorOccurred(m_currentReply->errorString());

        m_isBusy = false;

        m_currentReply->deleteLater();
        m_currentReply = nullptr;

        return;
    }

    QByteArray response = m_currentReply->readAll();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(response, &parseError);

    if (parseError.error != QJsonParseError::NoError)
    {
        emit ErrorOccurred("Failed to parse JSON: " + parseError.errorString());

        m_isBusy = false;

        m_currentReply->deleteLater();
        m_currentReply = nullptr;

        return;
    }

    QJsonObject root = doc.object();

    QJsonObject message = root["message"].toObject();

    QString content = message["content"].toString();

    m_isBusy = false;

    emit ResponseCompleted(content);

    m_currentReply->deleteLater();
    m_currentReply = nullptr;
}