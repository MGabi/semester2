#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startApp();

private slots:
    void on_jumpBtn_clicked();

    void on_saveBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
