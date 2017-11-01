#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QtGui/QWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QLabel>
#include <QtCore/QString>
#include <QtCore/QPoint>
#include <QtGui/QPaintEvent>
#include <QtGui/QMouseEvent>
namespace mediaplayer
{
    //四个边大小
    static const int MARGIN=20;
    
    class CMediaPlayToolBar;
    class CMainWindow :public QWidget
    {
        Q_OBJECT
    public:
        CMainWindow(QWidget *parent=NULL);
        ~CMainWindow();
        bool insertCenterWidget(QWidget*lMediaPlayWnd,QWidget *rMediaResListWnd);
    protected:
        void paintEvent(QPaintEvent *);
        void mouseMoveEvent(QMouseEvent *);
        void mousePressEvent(QMouseEvent *);
    private:
        QString readQss(const std::string );




        QVBoxLayout     *m_mainLayout;
        //标题中央，视频名称
        QWidget         *m_titleWidget;
        QLabel          *m_vedioName;         
        //播放区域
        QWidget         *m_centerWidget;
        QHBoxLayout     *m_hCenterLayout;
        QWidget         *m_lMediaPlayWnd;
        QWidget         *m_rMediaResListWnd;
        //工具条
        QWidget         *m_mediaPlayToolBar;

        //窗口移动
        QPoint          m_lastPos;
        bool            m_moveabled;
    };

}






#endif