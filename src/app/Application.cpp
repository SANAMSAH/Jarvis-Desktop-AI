#include "Application.h"

#include "MainWindow.h"

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


    m_mainWindow = new MainWindow();
    m_mainWindow->show();

    return true;
}