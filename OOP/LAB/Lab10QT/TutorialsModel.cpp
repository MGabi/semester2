#include "TutorialsModel.h"
#include <qdebug.h>
TutorialsModel::TutorialsModel(QObject *parent, int rows, int cols, vector<Tutorial*> tutorials):
    QAbstractTableModel(parent){
    this->rows = rows;
    this->cols = cols;
    this->tutorials = tutorials;
}

int TutorialsModel::rowCount(const QModelIndex &parent) const{
    return this->rows;
}

int TutorialsModel::columnCount(const QModelIndex &parent) const{
    return this->cols;
}

QVariant TutorialsModel::data(const QModelIndex &index, int role) const{
    if(role == Qt::DisplayRole){
        switch (index.column()) {
        case 0:
            return(QString("%1").arg(this->tutorials[index.row()]->getTitle().c_str()));
            break;
        case 1:
            return(QString("%1").arg(this->tutorials[index.row()]->getPresenter().c_str()));
            break;
        case 2:
            return(QString("%1").arg(this->tutorials[index.row()]->getDuration().toString().c_str()));
            break;
        case 3:
            return(QString("%1").arg(this->tutorials[index.row()]->getRefLink().c_str()));
            break;
        case 4:
            return(QString("%1").arg(this->tutorials[index.row()]->getLikes()));
            break;
        default:
            return(QString(""));
            break;
        }
    }
    return QVariant();
}

QVariant TutorialsModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if(role == Qt::DisplayRole){
        if(orientation == Qt::Horizontal){
            switch (section) {
            case 0:
                return QString("Title");
            case 1:
                return QString("Presenter");
            case 2:
                return QString("Ref link");
            case 3:
                return QString("Duration");
            case 4:
                return QString("Likes");
            default:
                return QString("");
            }
        }else if(orientation == Qt::Vertical){
            return QString("%1").arg(section+1);
        }
    }
    return QVariant();
}
