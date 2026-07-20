#include "ChatPage.h"
#include "Conversation.h"

#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QFont>

ChatPage::ChatPage(QWidget* parent)
    : QWidget(parent)
{
    InitializeUI();
}

ChatPage::~ChatPage() = default;

void ChatPage::InitializeUI()
{
    // ==========================
    // Main Layout
    // ==========================

    auto* mainLayout = new QVBoxLayout(this);

    mainLayout->setContentsMargins(25, 20, 25, 20);
    mainLayout->setSpacing(15);

    // ==========================
    // Header
    // ==========================

    m_headerLabel = new QLabel("Welcome to Jarvis", this);

    QFont headerFont;

    headerFont.setPointSize(16);
    headerFont.setBold(true);

    m_headerLabel->setFont(headerFont);

    m_headerLabel->setStyleSheet(
        "color:white;"
    );

    QFont font;
    font.setPointSize(14);
    font.setBold(true);

    m_headerLabel->setFont(font);

    mainLayout->addWidget(m_headerLabel);

    // ==========================
    // Scroll Area
    // ==========================

    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setFrameShape(QFrame::NoFrame);

    m_scrollArea->setStyleSheet(R"(
    QScrollArea
    {
        border:none;
        background:transparent;
    }
    )");

    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setFrameShape(QFrame::NoFrame);

    m_messagesWidget = new QWidget();
    m_messagesWidget->setStyleSheet(R"(
    QWidget
    {
        background:#202123;
        border-radius:12px;
    }
    )");

    m_messagesLayout = new QVBoxLayout(m_messagesWidget);
    m_messagesLayout->setContentsMargins(20, 20, 20, 20);

    m_messagesLayout->setSpacing(15);

    m_messagesLayout->setAlignment(Qt::AlignTop);
    m_messagesLayout->setSpacing(12);

    m_scrollArea->setWidget(m_messagesWidget);

    mainLayout->addWidget(m_scrollArea, 1);

    // ==========================
    // Bottom Input
    // ==========================

    auto* inputLayout = new QHBoxLayout();

    inputLayout->setSpacing(10);

    m_inputEdit = new QTextEdit(this);
    m_inputEdit->setPlaceholderText("Message Jarvis...");

    m_inputEdit->setMinimumHeight(70);

    m_inputEdit->setMaximumHeight(120);

    m_inputEdit->setStyleSheet(R"(

    QTextEdit
    {
        background:#2B2B2B;
        color:white;

        border:1px solid #404040;

        border-radius:10px;

        padding:10px;
    }

    )");

    m_sendButton = new QPushButton("➤", this);

    m_sendButton->setFixedSize(50, 50);

    m_sendButton->setCursor(Qt::PointingHandCursor);

    m_sendButton->setStyleSheet(R"(

    QPushButton
    {
        background:#7C3AED;

        color:white;

        border:none;

        border-radius:25px;

        font-size:20px;
    }

    QPushButton:hover
    {
        background:#8B5CF6;
    }

    )");


    inputLayout->addWidget(m_inputEdit);
    inputLayout->addWidget(m_sendButton);

    mainLayout->addLayout(inputLayout);
}
void ChatPage::LoadConversation(Conversation* conversation)
{
    if (!conversation)
        return;

    qDebug() << "Conversation:"
        << conversation->Title();

    qDebug() << "Messages:"
        << conversation->MessageCount();
}