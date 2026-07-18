#pragma once

#include <QWidget>

class ChatPage : public QWidget
{
    Q_OBJECT

public:
    explicit ChatPage(QWidget* parent = nullptr);
    ~ChatPage() override;

private:
    void InitializeUI();
};