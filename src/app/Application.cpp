#include "Application.h"

#include "MainWindow.h"

Application::Application() = default;


Application::~Application()
{
    delete m_mainWindow;
}

bool Application::Initialize()
{
    m_mainWindow = new MainWindow();

    m_mainWindow->show();

    return true;
}