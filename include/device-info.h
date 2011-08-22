#ifndef GEUZEN_DEVICE_INFO_H
#define GEUZEN_DEVICE_INFO_H

#include <QSystemDeviceInfo>

QTM_USE_NAMESPACE

namespace geuzen
{

class DeviceInfo  : public QObject
{
Q_OBJECT
public:

  DeviceInfo (QObject *parent=0);
  
  Q_INVOKABLE void start ();
  
  Q_INVOKABLE int batteryLevel ();
  Q_INVOKABLE int batteryStatus ();
  
signals:

  void batteryLevelChanged (int batteryLevel);
  void batteryStatusChanged (int batteryStatus);
  
private slots:

  void getBatteryLevel (int);
  void getBatteryStatus (QSystemDeviceInfo::BatteryStatus  batteryStatus);
  void collectInfo ();
  
private:

  QSystemDeviceInfo   sdi;
  
};

} // namespace

#endif // DEVICEINFO_H
