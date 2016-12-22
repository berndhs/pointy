#ifndef SYNC_H
#define SYNC_H

#include <QObject>
#include <QTimer>

class Sync : public QObject
{
  Q_OBJECT
public:
  explicit Sync(QObject *parent = 0);

  void signup();
  bool open();
  void reRun();

signals:
  void tick();

public slots:

  void ticked();

private:

  QTimer  *clock;
  int     useCount;
};

#endif // SYNC_H
