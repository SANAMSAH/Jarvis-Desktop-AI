#pragma once

#include <QObject>
#include <QString>

#include <memory>

class IAIProvider;

class AIManager : public QObject
{
    Q_OBJECT

public:
    explicit AIManager(QObject* parent = nullptr);

    ~AIManager() override ;

    bool Initialize();

    bool IsBusy() const;

    void SendPrompt(const QString& prompt);

    void CancelRequest();

signals:

    void ResponseStarted();

    void ResponseChunkReceived(const QString& chunk);

    void ResponseCompleted();

    void ErrorOccurred(const QString& error);

private:

    bool m_isBusy = false;
    std::unique_ptr<IAIProvider> m_provider;
};