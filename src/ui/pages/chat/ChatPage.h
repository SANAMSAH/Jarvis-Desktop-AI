#pragma once

#include <QWidget>
//#include "Message.h"
#include "MessageBubble.h"
#include <QEvent>

class Conversation;
class QScrollArea;
class QVBoxLayout;
class QTextEdit;
class QPushButton;
class QLabel;
class Message;

class ChatPage : public QWidget
{
    Q_OBJECT

public:
    explicit ChatPage(QWidget* parent = nullptr);
    ~ChatPage() override;

private:
    void InitializeUI();
    void AddMessageBubble(Message* message);

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;

public slots:

    void LoadConversation(Conversation* conversation);
    void OnSendClicked();

signals:
    void MessageSubmitted(const QString& text);

private:
    QLabel* m_headerLabel;

    QScrollArea* m_scrollArea;

    QWidget* m_messagesWidget;

    QVBoxLayout* m_messagesLayout;

    QTextEdit* m_inputEdit;

    QPushButton* m_sendButton;
};