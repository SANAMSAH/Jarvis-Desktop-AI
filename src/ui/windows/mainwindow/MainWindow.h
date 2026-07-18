#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class SidebarWidget;
class ChatPage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

    ~MainWindow() override;

private:
    void InitializeUI();

private:
    Ui::MainWindow* ui = nullptr;

    SidebarWidget* m_sidebar = nullptr;
    ChatPage* m_chatPage = nullptr;
};