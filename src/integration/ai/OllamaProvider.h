#pragma once

#include "IAIProvider.h"

class QNetworkAccessManager;
class QNetworkReply;

class OllamaProvider : public IAIProvider
{
    Q_OBJECT

public:
    explicit OllamaProvider(QObject* parent = nullptr);
    ~OllamaProvider() override;

    bool Initialize() override;

    void SendPrompt(const QString& prompt) override;

    void CancelRequest() override;

    bool IsBusy() const override;

private:

    bool m_isBusy = false;

    QNetworkAccessManager* m_networkManager = nullptr;

    QNetworkReply* m_currentReply = nullptr;
};