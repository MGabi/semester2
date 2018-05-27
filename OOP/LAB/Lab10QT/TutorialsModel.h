#ifndef TUTORIALSMODEL_H
#define TUTORIALSMODEL_H
#include <QAbstractTableModel>
#include <vector>
#include "Tutorial.h"
class TutorialsModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    int rows = -1;
    int cols = -1;
    vector<Tutorial*> tutorials;

public:
    TutorialsModel(QObject *parent, int rows, int cols, vector<Tutorial*> tutorials);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif // TUTORIALSMODEL_H
