#include <QDebug>
#include <QTimer>


#include "device-info.h"


namespace geuzen
{
DeviceInfo::DeviceInfo (QObject *parent)
  :QObject (parent),
   sdi (this)
{
  connect (&sdi, SIGNAL (batteryLevelChanged (int)),
            this, SLOT (getBatteryLevel (int)));
  connect (&sdi, SIGNAL (batteryStatusChanged (QSystemDeviceInfo::BatteryStatus)),
            this, SLOT (getBatteryStatus (QSystemDeviceInfo::BatteryStatus)));
}

void
DeviceInfo::start ()
{
  QTimer::singleShot (750,this, SLOT (collectInfo()));
}

void
DeviceInfo::collectInfo ()
{
  int level = batteryLevel ();
  int status = batteryStatus ();
  emit batteryStatusChanged (status);
  emit batteryLevelChanged (level);
}

int
DeviceInfo::batteryLevel ()
{
  int newLevel = sdi.batteryLevel();
  return newLevel;
}

int
DeviceInfo::batteryStatus ()
{
  int newStatus = int (sdi.batteryStatus());
  return newStatus;
}

void
DeviceInfo::getBatteryLevel (int level)
{
  qDebug () << __PRETTY_FUNCTION__ << level;
  emit batteryLevelChanged (level);
}

void
DeviceInfo::getBatteryStatus (QSystemDeviceInfo::BatteryStatus status)
{
  qDebug () << __PRETTY_FUNCTION__ << status;
  emit batteryStatusChanged (status);
}

} // namespace
