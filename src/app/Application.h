
#pragma once

class MainWindow;

class Application
{
public:
    Application();
    ~Application();

    bool Initialize();

private:
    MainWindow* m_mainWindow = nullptr;
};