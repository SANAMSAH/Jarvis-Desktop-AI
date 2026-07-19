#pragma once

#include <QObject>

class ConversationManager : public QObject
{
    Q_OBJECT

public:
    explicit ConversationManager(QObject* parent = nullptr);
    ~ConversationManager() override;

    bool Initialize();
};