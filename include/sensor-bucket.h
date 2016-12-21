#ifndef SENSORBUCKET_H
#define SENSORBUCKET_H

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

#include <QMagnetometer>
#include <QOrientationSensor>
#include <QAccelerometer>
#include <QGyroscope>
#include <QAmbientLightSensor>
#include <QLightSensor>
#include <QCompass>
#include <QProximitySensor>

#include <QTimer>


namespace experiment
{
class AccelSense : public QObject
{
Q_OBJECT
public:
  AccelSense (QObject *parent=0);

  Q_INVOKABLE void start ();

signals:

  void measurement (qreal dx, qreal dy, qreal dz);

private slots:

  void getReading ();
  
private:

  QAccelerometer   meter;

};

class GyroSense : public QObject
{
Q_OBJECT
public:
  GyroSense (QObject *parent=0);

  Q_INVOKABLE void start ();

signals:

  void measurement (qreal dx, qreal dy, qreal dz);

private slots:

  void getReading ();
  
private:

  QGyroscope    meter;
  QTimer        readTimer;

};

class AmbientLightSense : public QObject
{
Q_OBJECT
public:
  AmbientLightSense (QObject *parent=0);
  
  Q_INVOKABLE void start ();
  
signals:

  void measurement (int level);
  
private slots:

  void getReading ();
  
private:

  QAmbientLightSensor   meter;
  QTimer                readTimer;
};

class LuxSense : public QObject
{
Q_OBJECT
public:
  LuxSense (QObject *parent=0);
  
  Q_INVOKABLE void start ();
  
signals:

  void measurement (qreal lux);
  
private slots:

  void getReading ();
  
private:

  QLightSensor          meter;
  QTimer                readTimer;
};

class CompassSense : public QObject
{
Q_OBJECT
public:
  CompassSense (QObject *parent=0);
  
  Q_INVOKABLE void start ();
  
signals:

  void measurement (qreal degrees, qreal calibration);
  
private slots:

  void getReading ();
  
private:

  QCompass          meter;
  QTimer                readTimer;
};

class ProximitySense: public QObject
{
Q_OBJECT
public:
  ProximitySense (QObject *parent=0);
  
  Q_INVOKABLE void start ();
  
signals:

  void measurement (bool isClose);
  
private slots:

  void getReading ();
  
private:

  QProximitySensor    meter;
  QTimer              readTimer;
};

} // namespace
#endif // SENSORBUCKET_H
