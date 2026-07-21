#pragma once

#include <QWidget>
class QLabel;
class QHBoxLayout;
class Message;

class MessageBubble : public QWidget
{
    Q_OBJECT

public:
    explicit MessageBubble(Message* message, QWidget* parent = nullptr);

private:
    void InitializeUI();

private:
    Message* m_message = nullptr;

    QLabel* m_avatarLabel = nullptr;
    QLabel* m_messageLabel = nullptr;

    QHBoxLayout* m_mainLayout = nullptr;
};