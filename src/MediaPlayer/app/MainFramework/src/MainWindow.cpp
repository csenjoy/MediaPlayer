#include "MainWindow.hpp"
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QPainter>
#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include <QtGui/QStyleOption>

namespace mediaplayer
{

    CMainWindow::CMainWindow(QWidget *parent)
        :QWidget(parent,Qt::Window |Qt::FramelessWindowHint )
        ,m_moveabled(false)
    {

        if (this->objectName().isEmpty())
            this->setObjectName(QString::fromUtf8("MainFramework"));
        m_mainLayout = new QVBoxLayout(this);
        m_mainLayout->setContentsMargins(0,0,0,0);
        m_mainLayout->setSpacing(0);
        //三块区域最上层：标题栏
        m_titleWidget=new QWidget;
        m_titleWidget->setObjectName("titleWidget");
        QHBoxLayout * hTitleLayout=new QHBoxLayout(m_titleWidget);
        hTitleLayout->setContentsMargins(0,0,0,0);
        hTitleLayout->setSpacing(0);
        QPushButton *menuButton=new QPushButton;
        menuButton->setToolTip(tr("mainMenu"));
        menuButton->setObjectName("menuButton");
        menuButton->setText(tr("MediaPlayer"));
        hTitleLayout->addWidget(menuButton);
        //水平分隔符
        QSpacerItem *hLSpacerItem=new QSpacerItem(40,20,QSizePolicy::Expanding);
        hTitleLayout->addSpacerItem(hLSpacerItem);
        m_vedioName=new QLabel;
        m_vedioName->setObjectName("vedioName");
        m_vedioName->setText(tr("vedioName"));
        hTitleLayout->addWidget(m_vedioName);
        QSpacerItem *hRSpacerItem=new QSpacerItem(40,20,QSizePolicy::Expanding);
        hTitleLayout->addSpacerItem(hRSpacerItem);
        //功能按钮
        QPushButton *feedbackButton=new QPushButton;
        feedbackButton->setObjectName("feedbackButton");
        feedbackButton->setToolTip(tr("feedback"));
        QPushButton *styleButton=new QPushButton;
        styleButton->setObjectName("styleButton");
        styleButton->setToolTip(tr("styleMgr"));
        QPushButton *minButton=new QPushButton;
        minButton->setObjectName("minButton");
        minButton->setToolTip(tr("minimum"));
        QPushButton *maxButton=new QPushButton;
        maxButton->setObjectName("maxButton");
        maxButton->setToolTip(tr("maximum"));
        QPushButton *closeButton=new QPushButton;
        closeButton->setObjectName("closeButton");
        closeButton->setToolTip(tr("close"));
        hTitleLayout->addWidget(feedbackButton);
        hTitleLayout->addWidget(styleButton);
        hTitleLayout->addWidget(minButton);
        hTitleLayout->addWidget(maxButton);
        hTitleLayout->addWidget(closeButton);

        //标题栏加入主布局
        m_mainLayout->addWidget(m_titleWidget);

        //三块区域：中间显示区域
        m_centerWidget=new QWidget;
        m_centerWidget->setObjectName("m_centerWidget");
        m_hCenterLayout=new QHBoxLayout(m_centerWidget);
        m_hCenterLayout->setContentsMargins(0,0,0,0);
        m_hCenterLayout->setSpacing(0);

        //左侧播放窗口
        QWidget *lWidget=new QWidget;
        QWidget *rWidget=new QWidget;
        insertCenterWidget(lWidget,rWidget);

        m_mainLayout->addWidget(m_centerWidget,1);


        //三块区域：下侧工具条
        m_mediaPlayToolBar=new QWidget;
        m_mainLayout->addWidget(m_mediaPlayToolBar);

        std::string qsspath="../configure/styles/MainFramework/MainFramework.qss";
        QString qss=readQss(qsspath);
        setStyleSheet(qss);
        resize(400,600);

    }

    CMainWindow::~CMainWindow()
    {

    }

    bool CMainWindow::insertCenterWidget( QWidget*lMediaPlayWnd,QWidget *rMediaResListWnd )
    {
        if(lMediaPlayWnd&&rMediaResListWnd&&m_hCenterLayout)
        {
            m_hCenterLayout->addWidget(lMediaPlayWnd,1);
            m_hCenterLayout->addWidget(rMediaResListWnd);

            m_lMediaPlayWnd=lMediaPlayWnd;
            m_rMediaResListWnd=rMediaResListWnd;
            return true;
        }
        return false;
    }

    QString CMainWindow::readQss( const std::string filename)
    {

        QString tmpStr("");
        QFile qssFile(QString::fromStdString(filename));
        if (qssFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&qssFile);
            tmpStr = in.readAll();
            qssFile.close();
        }
        return tmpStr;

    }

    void CMainWindow::paintEvent( QPaintEvent * )
    {
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }

    void CMainWindow::mousePressEvent( QMouseEvent * e)
    {
        //标题栏和下方 toolbar栏才能移动
        const QPoint &point=e->pos();
        if(point.y() < m_titleWidget->height())   
        {
            m_lastPos=point;   
            m_moveabled=true;
        }
        else
           m_moveabled=false;
         e->ignore();         
    }

    void CMainWindow::mouseMoveEvent( QMouseEvent * e)
    {
        if(m_moveabled)
        {
            const QPoint &point=e->globalPos();
            QPoint tempPoint=point-m_lastPos;
            move(tempPoint);
        }      
    }

}