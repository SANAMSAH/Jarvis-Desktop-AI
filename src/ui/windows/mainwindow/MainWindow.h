#pragma once

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class SidebarWidget;
class ChatPage;
class AIManager;
class ConversationManager;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(AIManager* aiManager, ConversationManager* conversationManager,QWidget* parent = nullptr);

    ~MainWindow() override;

private:
    void InitializeUI();

private:
    Ui::MainWindow* ui = nullptr;

    SidebarWidget* m_sidebar = nullptr;
    ChatPage* m_chatPage = nullptr;

    AIManager* m_aiManager;
    ConversationManager* m_conversationManager;

private slots:
	void OnNewChatRequested();
    void OnConversationSelected(int index);
    void OnMessageSubmitted(const QString& text);
};