#pragma once

#include <QWidget>

class QLabel;
class QLineEdit;
class QPushButton;
class QListWidget;

class SidebarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SidebarWidget(QWidget* parent = nullptr);
    ~SidebarWidget() override;

    //constexpr int SidebarWidth = 280;

public:
    void PopulateDummyChats();

private:
    void InitializeUI();

private:
    QLabel* m_titleLabel = nullptr;
    QLabel* m_recentChatsLabel = nullptr;
    QLineEdit* m_searchEdit = nullptr;
    QPushButton* m_newChatButton = nullptr;
    QListWidget* m_chatList = nullptr;
    QPushButton* m_settingsButton = nullptr;
};