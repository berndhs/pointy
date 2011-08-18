#include "sensor-bucket.h"

#include <QAccelerometerReading>
#include <QGyroscopeReading>

#include <QDebug>

namespace experiment
{

/** \brief   Accelerometer  ********************
  */
  
AccelSense::AccelSense (QObject *parent)
  :QObject (parent),
   meter (this)
{
  qDebug () << __PRETTY_FUNCTION__;
  connect (&meter, SIGNAL (readingChanged()),
           this, SLOT (getReading()));
  qDebug () << "   Accel rates available: " << meter.availableDataRates();
  meter.setDataRate (10);
}

void
AccelSense::start ()
{
  qDebug () << __PRETTY_FUNCTION__;
  meter.start ();
}

void
AccelSense::getReading ()
{
 // qDebug () << __PRETTY_FUNCTION__;
  QAccelerometerReading * result = meter.reading();
  if (result) {
    qreal dx = result->x();
    qreal dy = result->y();
    qreal dz = result->z();
   // qDebug () << __PRETTY_FUNCTION__ << "  emit";
    emit measurement (dx,dy,dz);
  }
}

/** \brief   Gyroscope  ********************
  */
GyroSense::GyroSense (QObject *parent)
  :QObject (parent),
   meter (this),
   readTimer (this)
{
  qDebug () << __PRETTY_FUNCTION__;
  connect (&meter, SIGNAL (readingChanged()),
           this, SLOT (getReading()));
  qDebug () << "   Gyro rates available: " << meter.availableDataRates();
  meter.setDataRate (10);
  connect (&readTimer, SIGNAL (timeout()),this, SLOT (getReading()));
  readTimer.start (100);
}

void
GyroSense::start ()
{
  qDebug () << __PRETTY_FUNCTION__;
  meter.start ();
}

void
GyroSense::getReading ()
{
  //qDebug () << __PRETTY_FUNCTION__;
  QGyroscopeReading * result = meter.reading();
  if (result) {
    qreal dx = result->x();
    qreal dy = result->y();
    qreal dz = result->z();
    qDebug () << __PRETTY_FUNCTION__ << "  emit gyro " << dx << "/" << dy << "/" << dz;
    emit measurement (dx,dy,dz);
  }
}


/** \brief   Ambient Light Sensor  ********************
  */
AmbientLightSense::AmbientLightSense (QObject *parent)
  :QObject (parent),
   meter (this),
   readTimer (this)
{
  qDebug () << __PRETTY_FUNCTION__;
  connect (&meter, SIGNAL (readingChanged()),
           this, SLOT (getReading()));
  qDebug () << "   AmbientLight rates available: " << meter.availableDataRates();
  meter.setDataRate (10);
  connect (&readTimer, SIGNAL (timeout()),this, SLOT (getReading()));
  //readTimer.start (100);
}

void
AmbientLightSense::start ()
{
  qDebug () << __PRETTY_FUNCTION__;
  meter.start ();
}

void
AmbientLightSense::getReading ()
{
  //qDebug () << __PRETTY_FUNCTION__;
  QAmbientLightReading * result = meter.reading();
  if (result) {
    QAmbientLightReading::LightLevel level = result->lightLevel();
    //qDebug () << __PRETTY_FUNCTION__ << "  emit ambient " << level;
    emit measurement (int(level));
  }
}

/** \brief   Light Sensor  ********************
  */
LuxSense::LuxSense (QObject *parent)
  :QObject (parent),
   meter (this),
   readTimer (this)
{
  qDebug () << __PRETTY_FUNCTION__;
  connect (&meter, SIGNAL (readingChanged()),
           this, SLOT (getReading()));
  qDebug () << "   Lux rates available: " << meter.availableDataRates();
  meter.setDataRate (10);
  connect (&readTimer, SIGNAL (timeout()),this, SLOT (getReading()));
  //readTimer.start (100);
}

void
LuxSense::start ()
{
  qDebug () << __PRETTY_FUNCTION__;
  meter.start ();
}

void
LuxSense::getReading ()
{
  //qDebug () << __PRETTY_FUNCTION__;
  QLightReading * result = meter.reading();
  if (result) {
    qreal level = result->lux();
    //qDebug () << __PRETTY_FUNCTION__ << "  emit lux " << level;
    emit measurement (level);
  }
}

/** \brief   Compass Sensor  ********************
  */
CompassSense::CompassSense (QObject *parent)
  :QObject (parent),
   meter (this),
   readTimer (this)
{
  qDebug () << __PRETTY_FUNCTION__;
  connect (&meter, SIGNAL (readingChanged()),
           this, SLOT (getReading()));
  qDebug () << "   Compass rates available: " << meter.availableDataRates();
  meter.setDataRate (10);
  connect (&readTimer, SIGNAL (timeout()),this, SLOT (getReading()));
  readTimer.start (5*1000);
}

void
CompassSense::start ()
{
  qDebug () << __PRETTY_FUNCTION__;
  meter.start ();
}

void
CompassSense::getReading ()
{
  //qDebug () << __PRETTY_FUNCTION__;
  QCompassReading * result = meter.reading();
  if (result) {
    qreal degrees = result->azimuth();
    qreal calibration = result->calibrationLevel();
    qDebug () << __PRETTY_FUNCTION__ << "  emit compass " << degrees << " " << calibration;
    emit measurement (degrees, calibration);
  }
}



} // namespace
