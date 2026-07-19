#pragma once

#include <QObject>

class AIManager : public QObject
{
    Q_OBJECT

public:
    explicit AIManager(QObject* parent = nullptr);

    ~AIManager() override;

    bool Initialize();
};