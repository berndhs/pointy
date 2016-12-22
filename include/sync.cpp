#include "sync.h"

Sync::Sync(QObject *parent) : QObject(parent),
  useCount(0)
{

  clock = new QTimer (this);
  clock->setInterval(500);
  clock->start(500);
}

void
Sync::signup()
{
  useCount = 0;
}

void
Sync::ticked()
{
  useCount = 1;
}

bool
Sync::open()
{
  return useCount > 0;
}

void
Sync::reRun()
{
  useCount = 0;
  clock->start();
}
