#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "mygui.h"
#include "glwidget.h"

//#include <QUrl>
//#include <phonon/audiooutput.h>
//#include <phonon/mediaobject.h>
//#include <phonon/mediasource.h>
//#include <phonon/videowidget.h>

using namespace Phonon;

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

//=====box with 3 buttons =====//
//    mygui thegui;
//    thegui.show();

//=========rectangle==========//
//    glWidget widget;
//    widget.show();

        app.setApplicationName( QLatin1String("testphonon") );
        const QUrl url = QUrl( QLatin1String("file:///C:\Users\rynth\Music\Linkin Park Ft. Rakim - Guilty All The Same LeakedEarly.com.mp3") );
        MediaSource src( url );
        MediaObject obj;
        obj.setCurrentSource( src );

        AudioOutput audio( VideoCategory );
        Phonon::createPath( &obj, &video );
        Phonon::createPath( &obj, &audio );
        obj.play();




    return app.exec();
}
