#pragma once

#include <QWidget>
class Conversation;
class QScrollArea;
class QVBoxLayout;
class QTextEdit;
class QPushButton;
class QLabel;

class ChatPage : public QWidget
{
    Q_OBJECT

public:
    explicit ChatPage(QWidget* parent = nullptr);
    ~ChatPage() override;

private:
    void InitializeUI();

public slots:

    void LoadConversation(Conversation* conversation);

private:
    QLabel* m_headerLabel;

    QScrollArea* m_scrollArea;

    QWidget* m_messagesWidget;

    QVBoxLayout* m_messagesLayout;

    QTextEdit* m_inputEdit;

    QPushButton* m_sendButton;
};