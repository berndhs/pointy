#include "sensor-bucket.h"


/****************************************************************
 * This file is distributed under the following license:
 *
 * Copyright (C) 2011, 
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, 
 *  Boston, MA  02110-1301, USA.
 ****************************************************************/


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
  qDebug() << Q_FUNC_INFO << "type " << meter.type;
  connect (&meter, SIGNAL (readingChanged()),
           this, SLOT (getReading()));
  qDebug () << "   Accel rates available: " << meter.availableDataRates();
  meter.setDataRate (10);
  clock.signup();
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
  if (!clock.open()) {
    return;
  }
  QAccelerometerReading * result = meter.reading();
  if (result) {
    qreal dx = result->x();
    qreal dy = result->y();
    qreal dz = result->z();
   // qDebug () << __PRETTY_FUNCTION__ << "  emit";
    emit measurement (dx,dy,dz);
  }
  clock.reRun();
}

/** \brief   Gyroscope  ********************
  */
GyroSense::GyroSense (QObject *parent)
  :QObject (parent),
   meter (this),
   readTimer (this)
{
  qDebug() << Q_FUNC_INFO << "type " << meter.type;
  connect (&meter, SIGNAL (readingChanged()),
           this, SLOT (getReading()));
  qDebug () << "   Gyro rates available: " << meter.availableDataRates();
  meter.setDataRate (10);
  connect (&readTimer, SIGNAL (timeout()),this, SLOT (getReading()));
  readTimer.start (500);
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
  qDebug() << Q_FUNC_INFO << "type " << meter.type;
  connect (&meter, SIGNAL (readingChanged()),
           this, SLOT (getReading()));
  qDebug () << "   AmbientLight rates available: " << meter.availableDataRates();
  meter.setDataRate (10);
  connect (&readTimer, SIGNAL (timeout()),this, SLOT (getReading()));
  readTimer.start (500);
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
  qDebug() << Q_FUNC_INFO << "type " << meter.type;
  connect (&meter, SIGNAL (readingChanged()),
           this, SLOT (getReading()));
  qDebug () << "   Lux rates available: " << meter.availableDataRates();
  meter.setDataRate (10);
  connect (&readTimer, SIGNAL (timeout()),this, SLOT (getReading()));
  readTimer.start (500);
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
  qDebug() << Q_FUNC_INFO << "type " << meter.type;
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
    if (degrees < 0) {
      degrees += 360.0;
    }
    qreal calibration = result->calibrationLevel();
    emit measurement (degrees, calibration);
  }
}

/** \brief   Proximity Sensor  ********************
  */
ProximitySense::ProximitySense (QObject *parent)
  :QObject (parent),
   meter (this),
   readTimer (this)
{
  qDebug () << __PRETTY_FUNCTION__;
  connect (&meter, SIGNAL (readingChanged()),
           this, SLOT (getReading()));
  qDebug () << "   Proximity rates available: " << meter.availableDataRates();
  meter.setDataRate (10);
  connect (&readTimer, SIGNAL (timeout()),this, SLOT (getReading()));
  readTimer.start (5*1000);
}

void
ProximitySense::start ()
{
  qDebug () << __PRETTY_FUNCTION__;
  meter.start ();
}

void
ProximitySense::getReading ()
{
  //qDebug () << __PRETTY_FUNCTION__;
  QProximityReading * result = meter.reading();
  if (result) {
    bool isClose = result->close();
    emit measurement (isClose);
  }
}



} // namespace
