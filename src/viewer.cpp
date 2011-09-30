#include "viewer.h"
#include <QDeclarativeEngine>
#include <QDebug>

PointyViewer::PointyViewer(QWidget *parent) :
    QDeclarativeView(parent)
{
  connect (engine(),SIGNAL(quit()),this,SLOT(doQuit()));
}

void
PointyViewer::runLocal (const QString & qmlFile)
{
  setSource (QUrl::fromLocalFile(qmlFile));
  platformShow ();
}

void
PointyViewer::runQrc (const QString & qmlFile)
{
  setSource (QUrl(QString ("qrc:///qml/%1").arg( qmlFile)));
  platformShow ();
}

void
PointyViewer::platformShow()
{
  setResizeMode(QDeclarativeView::SizeRootObjectToView);
#if defined(Q_OS_SYMBIAN) || defined(MEEGO_EDITION_HARMATTAN) || defined(Q_WS_SIMULATOR)
  qDebug () << __PRETTY_FUNCTION__ << " symbian|harmattan|Q_simulator";
  showFullScreen();
#else
  qDebug () << __PRETTY_FUNCTION__ << " linux";
  resize (QSize (600,400));
  showNormal ();
#endif
  show();
}

void
PointyViewer::doQuit ()
{
  emit quit ();    
}
