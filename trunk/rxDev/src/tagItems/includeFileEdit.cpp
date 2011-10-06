#include "ui_includeFileEdit.h"
#include "includeFileEdit.h"
#include <QMessageBox>

IncludeFileEdit::IncludeFileEdit(IncludeFileItem *item, QWidget *parent) : QDialog(parent), ui(new Ui::IncludeFileEdit) {
    ui->setupUi(this);
    ui->lineEdit_file->setText(item->getFile());
    ui->lineEdit_namespace->setText(item->getNamespace());
    ui->lineEdit_if->setText(item->getIf());
    ui->lineEdit_unless->setText(item->getUnless());
    ui->comboBox_clearParams->setCurrentIndex(item->getClearParams());
    envModel = new QStandardItemModel(item->envItems.count(),4);
    envModel->setHeaderData(0,Qt::Horizontal,QObject::tr("name"));
    envModel->setHeaderData(1,Qt::Horizontal,QObject::tr("value"));
    envModel->setHeaderData(2,Qt::Horizontal,QObject::tr("if"));
    envModel->setHeaderData(3,Qt::Horizontal,QObject::tr("unless"));
    for (int row = 0; row < item->envItems.count(); ++row) {
        QStandardItem *item0 = new QStandardItem(QString(item->envItems.at(row)->getName()));
        envModel->setItem(row,0,item0);
        item0 = new QStandardItem(QString(item->envItems.at(row)->getValue()));
        envModel->setItem(row,1,item0);
        item0 = new QStandardItem(QString(item->envItems.at(row)->getIf()));
        envModel->setItem(row,2,item0);
        item0 = new QStandardItem(QString(item->envItems.at(row)->getUnless()));
        envModel->setItem(row,3,item0);

    }
    ui->tableView_envItems->setModel(envModel);
    argModel = new QStandardItemModel(item->argItems.count(),5);
    argModel->setHeaderData(0,Qt::Horizontal,QObject::tr("name"));
    argModel->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    argModel->setHeaderData(2,Qt::Horizontal,QObject::tr("value"));
    envModel->setHeaderData(3,Qt::Horizontal,QObject::tr("if"));
    envModel->setHeaderData(4,Qt::Horizontal,QObject::tr("unless"));
    for (int row = 0; row < item->argItems.count(); ++row) {
        QStandardItem *item0 = new QStandardItem(QString(item->argItems.at(row)->getName()));
        argModel->setItem(row,0,item0);
        switch (item->argItems.at(row)->getValue_or_default()){
        //Todo: fix, the values don't get read correct
        case 0:
            item0 = new QStandardItem(QString("-"));
            argModel->setItem(row,1,item0);
            item0 = new QStandardItem(QString("-"));
            argModel->setItem(row,2,item0);
            item0 = new QStandardItem(QString(item->argItems.at(row)->getIf()));
            argModel->setItem(row,3,item0);
            item0 = new QStandardItem(QString(item->argItems.at(row)->getUnless()));
            argModel->setItem(row,4,item0);
            break;
        case 1:
            item0 = new QStandardItem(QString("value"));
            argModel->setItem(row,1,item0);
            item0 = new QStandardItem(QString(item->argItems.at(row)->getValue()));
            argModel->setItem(row,2,item0);
            item0 = new QStandardItem(QString(item->argItems.at(row)->getIf()));
            argModel->setItem(row,3,item0);
            item0 = new QStandardItem(QString(item->argItems.at(row)->getUnless()));
            argModel->setItem(row,4,item0);
            break;
        case 2:
            item0 = new QStandardItem(QString("default"));
            argModel->setItem(row,1,item0);
            item0 = new QStandardItem(QString(item->argItems.at(row)->getValue()));
            argModel->setItem(row,2,item0);
            item0 = new QStandardItem(QString(item->argItems.at(row)->getIf()));
            argModel->setItem(row,3,item0);
            item0 = new QStandardItem(QString(item->argItems.at(row)->getUnless()));
            argModel->setItem(row,4,item0);
            break;
        }
    }
    ui->tableView_argItems->setModel(argModel);

}

IncludeFileEdit::~IncludeFileEdit() {
    delete ui;
}

void IncludeFileEdit::reject() {
    ui->lineEdit_file->setText("");
    QDialog::reject();
}

void IncludeFileEdit::accept() {

    if ( ui->lineEdit_file->text()==""){
        QMessageBox::information(this, (QString::fromUtf8("Information")),
                                 QString::fromUtf8("<h2>No file specified</h2>"
                                                   "<p>Please insert the correct file path!</p>"));
        ui->lineEdit_file->setFocus();

    } else{

        QDialog::accept();
    }

}

QString IncludeFileEdit::getFile(){
    return ui->lineEdit_file->text();
}
QString IncludeFileEdit::getNamespace(){
    return ui->lineEdit_namespace->text();

}
int IncludeFileEdit::getClearParam()
{
    return ui->comboBox_clearParams->currentIndex();
}
QString IncludeFileEdit::getIf()
{
    return ui->lineEdit_if->text();
}

QString IncludeFileEdit::getUnless()
{
    return ui->lineEdit_unless->text();
}
