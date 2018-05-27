#ifndef ADMINISTRATORWINDOW_H
#define ADMINISTRATORWINDOW_H

#include <QWidget>
#include "CSVRepo.h"
#include "Controller.h"
#include "TutorialsModel.h"
#include <QModelIndex>

namespace Ui {
class AdministratorWindow;
}

class AdministratorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdministratorWindow(QWidget *parent = 0, CSVRepo* repo = nullptr, Controller* ctrl = nullptr);
    ~AdministratorWindow();
    void refreshTutorials(vector<Tutorial*> tutorials);
private slots:
    void on_buttonAdd_clicked();

    void on_buttonDelete_clicked();

    void on_buttonUpdate_clicked();

    void setupDataInTable();

public slots:
    void onCellSelected(QModelIndex index);

private:
    CSVRepo *repo;
    Controller *ctrl;
    TutorialsModel* model;
    int currentRow = -1;
    int currentColumn = -1;
    Ui::AdministratorWindow *ui;
};

#endif // ADMINISTRATORWINDOW_H
