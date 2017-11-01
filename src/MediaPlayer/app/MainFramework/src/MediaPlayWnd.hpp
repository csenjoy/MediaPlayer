#ifndef MEDIAPLAYWND_HPP_
#define MEDIAPLAYWND_HPP_
#include <QtGui/QWidget>
#include <QtGui/QVBoxLayout>
namespace mediaplayer{
    class CVedioPlayWnd;
    class CVedioSettingBar;
    class CVedioProgressBar;
    class CMediaPlayWnd :public QWidget
    {
        Q_OBJECT
    public:
        CMediaPlayWnd(QWidget *parent=NULL);
        ~CMediaPlayWnd();
        bool init();
        void fini();
    private:
        CVedioSettingBar        *m_vedioSetting;
        CVedioPlayWnd           *m_vedioPlayWnd;
        CVedioProgressBar       *m_progressBar;
        
        QVBoxLayout             *m_vMainLayout;
    };


}

#endif 