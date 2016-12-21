#ifndef POINTY_VIEWER_H
#define POINTY_VIEWER_H

#include <QQuickView>
#include <QWindow>

class PointyViewer : public QQuickView
{
Q_OBJECT
public:
  explicit PointyViewer(QWindow *parent = 0);
  
  void runLocal (const QString & qmlFile);
  void runQrc (const QString & qrcFile);

signals:
  
  void quit ();

public slots:
  
  void doQuit ();

private:

  void platformShow ();

};

#endif // PointyViewer_H
