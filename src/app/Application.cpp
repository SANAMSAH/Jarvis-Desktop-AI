#include "Application.h"

#include "MainWindow.h"
#include "AIManager.h"
#include "ConversationManager.h"

Application::Application(QObject* parent)
    : QObject(parent)

{

}
Application::~Application()
{
    delete m_mainWindow;
}

bool Application::Initialize()
{
    m_aiManager = new AIManager(this);
    m_aiManager->Initialize();


    m_conversationManager = new ConversationManager(this);

    m_mainWindow = new MainWindow(m_aiManager,m_conversationManager);
    m_mainWindow->show();

    return true;
}