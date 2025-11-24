// #include "mainwindow.h"
// #include "ui_mainwindow.h"

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);
// }

// MainWindow::~MainWindow()
// {
//     delete ui;
// }




// #include "MainWindow.h"
// #include "ChatClient.h"
// #include <QTextEdit>
// #include <QLineEdit>
// #include <QPushButton>
// #include <QVBoxLayout>
// #include <QWidget>

// MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent),
//     chatView(new QTextEdit), input(new QLineEdit), sendBtn(new QPushButton("Send")),
//     client(new ChatClient(this))
// {
//     chatView->setReadOnly(true);
//     auto* container = new QWidget; setCentralWidget(container);
//     auto* layout = new QVBoxLayout(container);
//     layout->addWidget(chatView);
//     layout->addWidget(input);
//     layout->addWidget(sendBtn);

//     connect(client, &ChatClient::connected, this, [this]{ appendLine("Connected."); });
//     connect(client, &ChatClient::messageReceived, this, [this](const QString& t){ appendLine(t); });
//     connect(client, &ChatClient::errorText, this, [this](const QString& e){ appendLine("Error: " + e); });
//     connect(sendBtn, &QPushButton::clicked, this, [this]{
//         if (!input->text().isEmpty()) { client->sendText(input->text()); input->clear(); }
//     });

//     client->connectTo("127.0.0.1", 12345);
// }

// void MainWindow::appendLine(const QString& line) { chatView->append(line); }




// MainWindow.cpp
#include "MainWindow.h"
#include "ChatClient.h"
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent),
    chatView(new QTextEdit), input(new QLineEdit), sendBtn(new QPushButton("发送")),
    client(new ChatClient(this))
{
    chatView->setReadOnly(true);

    // 布局：聊天区 + 输入区（输入框 + 按钮）
    auto* container = new QWidget; setCentralWidget(container);
    auto* mainLayout = new QVBoxLayout(container);
    auto* inputLayout = new QHBoxLayout;

    inputLayout->addWidget(input);
    inputLayout->addWidget(sendBtn);

    mainLayout->addWidget(chatView);
    mainLayout->addLayout(inputLayout);

    // 美化样式
    chatView->setStyleSheet(
        "QTextEdit {"
        " background-color: #f9f9f9;"
        " border: 1px solid #cccccc;"
        " font: 14px 'Microsoft YaHei';"
        " color: #333333;"
        " padding: 6px;"
        "}"
        );

    input->setStyleSheet(
        "QLineEdit {"
        " border: 1px solid #888888;"
        " border-radius: 6px;"
        " padding: 6px;"
        " font: 14px 'Microsoft YaHei';"
        "}"
        );

    sendBtn->setStyleSheet(
        "QPushButton {"
        " background-color: #4CAF50;"
        " color: white;"
        " border-radius: 6px;"
        " padding: 6px 12px;"
        " font-weight: bold;"
        "}"
        "QPushButton:hover { background-color: #45a049; }"
        );

    // 信号槽
    connect(client, &ChatClient::connected, this, [this]{ appendLine("✅ 已连接服务器"); });
    connect(client, &ChatClient::messageReceived, this, [this](const QString& t){ appendLine(t); });
    connect(client, &ChatClient::errorText, this, [this](const QString& e){ appendLine("❌ 错误: " + e); });
    connect(sendBtn, &QPushButton::clicked, this, [this]{
        if (!input->text().isEmpty()) {
            client->sendText(input->text());
            appendLine("我: " + input->text(), true);
            input->clear();
        }
    });

    client->connectTo("127.0.0.1", 12345);
}

void MainWindow::appendLine(const QString& line, bool isSelf) {
    if (isSelf)
        chatView->append("<p style='color:blue;'><b>" + line + "</b></p>");
    else
        chatView->append("<p style='color:green;'>" + line + "</p>");
}
