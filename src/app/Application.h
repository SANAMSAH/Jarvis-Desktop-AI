
#pragma once

#include <QObject>

class AIManager;
class ConversationManager;
class MainWindow;

class Application : public QObject
{
	Q_OBJECT

public:
    explicit Application(QObject* parent = nullptr);
    ~Application();

    bool Initialize();

private:
    MainWindow* m_mainWindow = nullptr;

    AIManager* m_aiManager = nullptr;
    ConversationManager* m_conversationManager = nullptr;
};