
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "SidebarWidget.h"
#include "ChatPage.h"

#include <QHBoxLayout>
#include "AIManager.h"
#include "ConversationManager.h"
#include <QMessageBox>


MainWindow::MainWindow(
    AIManager* aiManager,
    ConversationManager* conversationManager,
    QWidget* parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_aiManager(aiManager),
    m_conversationManager(conversationManager)
{
    ui->setupUi(this);
    resize(1400, 900);

    setWindowTitle("Jarvis Desktop AI");

    InitializeUI();

	// Connect the signal from SidebarWidget to the slot in MainWindow
    connect(m_sidebar, &SidebarWidget::newChatRequested, this, &MainWindow::OnNewChatRequested);

    connect(m_conversationManager,&ConversationManager::ConversationCreated,m_sidebar,&SidebarWidget::AddConversation);

    connect(
        m_conversationManager,
        &ConversationManager::CurrentConversationChanged,
        m_chatPage,
        &ChatPage::LoadConversation);

    connect(
        m_sidebar,
        &SidebarWidget::ConversationSelected,
        this,
        &MainWindow::OnConversationSelected);

    connect(
        m_chatPage,
        &ChatPage::MessageSubmitted,
        this,
        &MainWindow::OnMessageSubmitted);

    connect(m_aiManager,
        &AIManager::ResponseCompleted,
        this,
        &MainWindow::OnAIResponseCompleted);

    connect(m_aiManager,
        &AIManager::ErrorOccurred,
        this,
        &MainWindow::OnAIError);

    connect(m_conversationManager,
        &ConversationManager::ConversationUpdated,
        this,
        &MainWindow::OnConversationUpdated);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitializeUI()
{
    auto* layout = new QHBoxLayout(ui->centralwidget);

    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    m_sidebar = new SidebarWidget(ui->centralwidget);
    m_chatPage = new ChatPage(ui->centralwidget);

    layout->addWidget(m_sidebar);
    layout->addWidget(m_chatPage, 1);
}
void MainWindow::OnConversationSelected(int index)
{
    Conversation* conversation =
        m_conversationManager->GetConversation(index);

    if (!conversation)
        return;

    m_conversationManager->SetCurrentConversation(conversation);
}
void MainWindow::OnMessageSubmitted(const QString& text)
{
    Conversation* conversation =
        m_conversationManager->CurrentConversation();

    auto message = std::make_unique<Message>();

    message->SetRole(MessageRole::User);
    message->SetText(text);

    conversation->AddMessage(std::move(message));
    m_chatPage->LoadConversation(conversation);

    m_aiManager->SendPrompt(text);
}
void MainWindow::OnAIResponseCompleted(const QString& response)
{
    m_conversationManager->AddAssistantMessage(response);
}
void MainWindow::OnAIError(const QString& error)
{
    QMessageBox::warning(this,
        "Jarvis",
        error);
}
void MainWindow::OnConversationUpdated(Conversation* conversation)
{
    if (!conversation)
        return;

    m_chatPage->LoadConversation(conversation);
}
void MainWindow::OnNewChatRequested()
{
    m_conversationManager->CreateConversation();
}