// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>

// QT_BEGIN_NAMESPACE
// namespace Ui {
// class MainWindow;
// }
// QT_END_NAMESPACE

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// private:
//     Ui::MainWindow *ui;
// };
// #endif // MAINWINDOW_H

// #pragma once
// #include <QMainWindow>
// class QTextEdit; class QLineEdit; class QPushButton;
// class ChatClient;

// class MainWindow : public QMainWindow {
//     Q_OBJECT
// public:
//     explicit MainWindow(QWidget* parent = nullptr);
// private:
//     QTextEdit* chatView;
//     QLineEdit* input;
//     QPushButton* sendBtn;
//     ChatClient* client;
//     void appendLine(const QString& line);
// };

#pragma once
#include <QMainWindow>
class QTextEdit;
class QLineEdit;
class QPushButton;
class ChatClient;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QTextEdit *chatView;
    QLineEdit *input;
    QPushButton *sendBtn;
    ChatClient *client;
    void appendLine(const QString &line, bool isSelf = false);
};
