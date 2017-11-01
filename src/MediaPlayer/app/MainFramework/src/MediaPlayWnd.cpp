#include "MediaPlayWnd.hpp"
namespace mediaplayer
{
    CMediaPlayWnd::CMediaPlayWnd(QWidget *parent)
        :QWidget(parent)
    {
        m_vMainLayout=new QVBoxLayout(this);
        m_vMainLayout->setContentsMargins(0,0,0,0);
        m_vMainLayout->setSpacing(0);

        

    }

    bool CMediaPlayWnd::init()
    {
        return true;
    }

    void CMediaPlayWnd::fini()
    {

    }



}