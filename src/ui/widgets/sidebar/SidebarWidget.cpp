#include "SidebarWidget.h"

#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <Conversation.h>

SidebarWidget::SidebarWidget(QWidget* parent)
    : QWidget(parent)
{
    InitializeUI();

	connect(m_newChatButton, &QPushButton::clicked, this, &SidebarWidget::newChatRequested);

    connect(
        m_chatList,
        &QListWidget::currentRowChanged,
        this,
        &SidebarWidget::OnCurrentRowChanged);
}

SidebarWidget::~SidebarWidget() = default;

void SidebarWidget::PopulateDummyChats()
{
    m_chatList->addItem("C++ Interview");
    m_chatList->addItem("Qt Project");
    m_chatList->addItem("Jarvis Design");
    m_chatList->addItem("Meeting Notes");
}

void SidebarWidget::InitializeUI()
{
    auto* layout = new QVBoxLayout(this);

    layout->setContentsMargins(12, 12, 12, 12);
    layout->setSpacing(10);

    QFont font;
    font.setPointSize(13);
    font.setBold(true);


    m_titleLabel = new QLabel("🤖 Jarvis");
    m_titleLabel->setAlignment(Qt::AlignCenter);
    m_titleLabel->setFont(font);

    m_searchEdit = new QLineEdit();
    m_searchEdit->setPlaceholderText("Search chats...");

    m_newChatButton = new QPushButton("➕ New Chat");

    m_recentChatsLabel = new QLabel("Recent Chats");

    m_chatList = new QListWidget();
    m_settingsButton = new QPushButton("Settings");
        

    layout->addWidget(m_titleLabel);
    layout->addWidget(m_searchEdit);
    layout->addWidget(m_newChatButton);
    layout->addWidget(m_recentChatsLabel);
    layout->addWidget(m_chatList);

    layout->addStretch();

    layout->addWidget(m_settingsButton);

    setFixedWidth(280);

   
    PopulateDummyChats();
}
void SidebarWidget::OnCurrentRowChanged(int row)
{
    if (row < 0)
        return;

    emit ConversationSelected(row);
}
void SidebarWidget::AddConversation(Conversation* conversation)
{
    m_chatList->addItem(conversation->Title());
}