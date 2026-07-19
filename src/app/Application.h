
#pragma once

#include "AIManager.h"

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
};