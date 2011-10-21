#ifndef RXDEV_H
#define RXDEV_H


#include "ros/ros.h"
#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>

//#include <QFileSystemWatcher>
#include <QStringListModel>
#include <QStringList>
#include <QFileSystemModel>
#include <QFileDialog>
#include <QThread>

#include "QDebug"
#include "QFile"
#include "QDir"
#include "QDesktopServices"
#include "QTimer"

#include "QRegExp"
#include <QSettings>

#include <QStandardItemModel>

#include "launchFileView.h"
#include "launchFileScene.h"

#include "tinyxml.h"
#include "tagItems/argItem.h"
#include "tagItems/remapItem.h"
#include "tagItems/remapArrow.h"
#include "tagItems/includeFileItem.h"
#include "tagItems/machineItem.h"
#include "tagItems/groupItem.h"

class LaunchFileScene;
class LaunchFileView;

//Datastructure for specfile data
class rosNode {
public:
    QString nodeType;
    QString nodePackage;
    QStringList nodeInput;
    QStringList nodeOutput;
    QStringList nodeServices;
    QStringList nodeParameters;
};



namespace Ui {
    class RxDev;
    class UpdateNodesThread;

}

class RxDev : public QMainWindow
{
    Q_OBJECT

public:
    explicit RxDev(QWidget *parent = 0);
    QSettings settings;
    rosNode node;


    ~RxDev();


public slots:



private slots:
    void on_actionAvailable_Nodes_changed();
    void setupCreator();

    void selectionHandle_3(const QItemSelection &,const QItemSelection &);
    void selectionHandle_availableNodes(const QItemSelection &,const QItemSelection &);
    void on_pushButton_createPackage_clicked();
    void on_actionAbout_rxdev_activated();
    void changeToolBar();

    void enableCreatePackageButton(const QString &text);

    void openFileOrFolder();
    void showContextMenu(const QPoint &point);

    void deleteFile();
    void createNewFile();
    void createNewFolder();

    void renameFolder();

    void loadSettings();


    //new

    void availableNodes();
    void showContextMenu_availableNodes(const QPoint &point);
void openSpecFile();
    void collapseNode();
    void expandNode();
    void collapseAll();
    void expandAll();

    void nodeParser(const QString nodeFile);

    void fillItemModel_availableNodes(const QString nodeFile);
    void setupConnector();
    //end new
    void on_actionLoad_Launchfile_triggered();

    void on_actionSave_as_Launchfile_triggered();



    void on_actionRemap_triggered();

    void on_actionDrag_Drop_triggered();

    void on_actionDelete_Item_triggered();

// new 19.08

    bool maybeSave();
    void setViewScale(const QString &scale);

    //end 19.08

    //new 21.08

    //void itemInserted(NodeItem *item);

    //end 21.08
    void on_pushButton_Param_clicked();
    //5.09.
    QPointF findSpace(QPointF currentPoint);

    void on_pushButton_includeFile_clicked();

    void on_pushButton_machine_clicked();

    void on_pushButton_arg_clicked();

    void on_pushButton_env_clicked();

    void on_pushButton_group_clicked();

    void on_actionAvailable_Tags_changed();



    void loadDocument( TiXmlNode * pParent);
    void create_groupItem(TiXmlNode *pParent);
    void create_paramItem(ParameterItem &newParam, TiXmlNode * pParent,int &x, int &y);
    void create_rosparamItem(RosparamItem &newRosparam, TiXmlNode * pParent,int &x, int &y);
    void create_envItem(EnvItem &newEnv,TiXmlNode * pParent,int &x, int &y);
    void create_argItem(ArgItem &newArg,TiXmlNode * pParent,int &x, int &y);
    void create_remapItem(RemapItem &newRemap, TiXmlNode * pParent,int &x, int &y);
    void create_remapArrow(const remapArrowData *arrowData);
    void create_includeFileItem(IncludeFileItem &newInclude,TiXmlNode *pParent,int &x, int &y);
    void create_machineItem(MachineItem &nemMachine, TiXmlNode *pParent,int &x, int &y);
    void prepare_nodeOrTest(TiXmlNode *nodeNode,QString &nodePackage, QString &nodeType,QStringList &nodeSubs,
                            QStringList &nodePubs,QStringList &nodeArgs,QStringList &nodeSrvs);
    void create_nodeorTestItem(NodeItem &newNode, int nodeOrTest,TiXmlNode * pParent,int &x, int &y);
    void on_pushButton_remap_clicked();
    void beginParsing(TiXmlNode *pParent);
    QPoint getCoords(TiXmlNode *node);
    void getGroupDim(TiXmlNode *node,int &width, int &height);
    void on_pushButton_refreshNodes_clicked();


    void on_actionSettings_triggered();

    void on_actionNew_Launchfile_triggered();

    void on_pushButton_rosparam_clicked();

private:
    Ui::RxDev *ui;
    QLabel *rosCoreStatus;
    QPushButton *rosCoreButton;
    QProcess *rosCoreProcess;
    QStringListModel *model;
    QStringListModel *model_2;
    QFileSystemModel *workingModel;
    QStandardItemModel *model_availableNodes;
    //QFileSystemWatcher *watcher;
    QStringList packageList;
    QStringList nodeList;
    bool check;
    bool project;
    QDir workingDir;
    QDir currentDir;

    //new
     //end new

    //new 19.08
    QPoint m_lastPos;
    QSize m_lastSize;

LaunchFileScene * scene;
LaunchFileView * gview; ///< the graphics view will contain and display the scene.



protected:

    void setupToolBar();
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void moveEvent(QMoveEvent *event);
    //void showEvent(QShowEvent *event);

    void saveWindowState();
    void restoreWindowState();
    //end 19.08
};


#endif // RXDEV_H





