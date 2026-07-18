#include "SidebarWidget.h"

#include <QVBoxLayout>
#include <QPushButton>

SidebarWidget::SidebarWidget(QWidget* parent)
    : QWidget(parent)
{
    InitializeUI();
}

SidebarWidget::~SidebarWidget() = default;

void SidebarWidget::InitializeUI()
{
    auto* layout = new QVBoxLayout(this);

    layout->setContentsMargins(12, 12, 12, 12);
    layout->setSpacing(10);

    auto* btnNewChat = new QPushButton("New Chat");
    auto* btnHistory = new QPushButton("History");
    auto* btnModels = new QPushButton("Models");
    auto* btnSettings = new QPushButton("Settings");

    layout->addWidget(btnNewChat);
    layout->addWidget(btnHistory);
    layout->addWidget(btnModels);

    layout->addStretch();

    layout->addWidget(btnSettings);

    setFixedWidth(260);
}