#include "ChatPage.h"

#include <QLabel>
#include <QVBoxLayout>

ChatPage::ChatPage(QWidget* parent)
    : QWidget(parent)
{
    InitializeUI();
}

ChatPage::~ChatPage() = default;

void ChatPage::InitializeUI()
{
    auto* layout = new QVBoxLayout(this);
        
    layout->setContentsMargins(20, 20, 20, 20);

    auto* label = new QLabel("Welcome to Jarvis");

    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label);
}