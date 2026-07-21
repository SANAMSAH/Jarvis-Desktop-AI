#include "MessageBubble.h"


#include "Message.h"

#include <QHBoxLayout>
#include <QLabel>

MessageBubble::MessageBubble(Message* message, QWidget* parent)
    : QWidget(parent),
    m_message(message)
{
    InitializeUI();
}

void MessageBubble::InitializeUI()
{
    m_mainLayout = new QHBoxLayout(this);

    m_mainLayout->setContentsMargins(10, 5, 10, 5);

    m_avatarLabel = new QLabel(this);
    m_messageLabel = new QLabel(this);

    m_messageLabel->setWordWrap(true);

    m_messageLabel->setText(m_message->Text());

    if (m_message->IsAssistant())
    {
        m_avatarLabel->setText("🤖");

        m_messageLabel->setStyleSheet(R"(
            QLabel
            {
                background:#2D2F36;
                color:white;
                padding:12px;
                border-radius:12px;
            }
        )");

        m_mainLayout->addWidget(m_avatarLabel);
        m_mainLayout->addWidget(m_messageLabel);
        m_mainLayout->addStretch();
    }
    else
    {
        m_avatarLabel->setText("👤");

        m_messageLabel->setStyleSheet(R"(
            QLabel
            {
                background:#7C3AED;
                color:white;
                padding:12px;
                border-radius:12px;
            }
        )");

        m_mainLayout->addStretch();
        m_mainLayout->addWidget(m_messageLabel);
        m_mainLayout->addWidget(m_avatarLabel);
    }
}