#pragma once

#include <QWidget>

class SidebarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SidebarWidget(QWidget* parent = nullptr);
    ~SidebarWidget() override;

private:
    void InitializeUI();
};