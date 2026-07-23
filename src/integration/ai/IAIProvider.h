#pragma once

#include <QObject>
#include <QString>

class IAIProvider : public QObject
{
    Q_OBJECT

public:
    explicit IAIProvider(QObject* parent = nullptr)
        : QObject(parent)
    {
    }

    virtual ~IAIProvider() = default;

    virtual bool Initialize() = 0;

    virtual void SendPrompt(const QString& prompt) = 0;

    virtual void CancelRequest() = 0;

    virtual bool IsBusy() const = 0;

signals:

    void ResponseStarted();

    void ResponseChunkReceived(const QString& chunk);

    void ResponseCompleted(const QString& response);

    void ErrorOccurred(const QString& error);
};