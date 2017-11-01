#include "MainWindow.hpp"

#include <QtGui/QApplication>
#include <QtGui/QDialog>


int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    
     mediaplayer::CMainWindow mainWnd;
     mainWnd.setWindowTitle( QObject::tr("dlg"));
     mainWnd.show();
//     QDialog dlg;
//     dlg.setWindowTitle( QObject::tr("dlg"));
//     dlg.show();

   
    return app.exec();
}