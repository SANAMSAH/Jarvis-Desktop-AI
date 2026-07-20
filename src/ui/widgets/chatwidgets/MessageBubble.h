#pragma once

#include <QWidget>

class MessageBubble : public QWidget
{
    Q_OBJECT

public:
    explicit MessageBubble(QWidget* parent = nullptr);
};