
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "SidebarWidget.h"
#include "ChatPage.h"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1400, 900);

    setWindowTitle("Jarvis Desktop AI");

    InitializeUI();
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