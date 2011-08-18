#ifndef SENSORBUCKET_H
#define SENSORBUCKET_H

#include <QMagnetometer>
#include <QOrientationSensor>
#include <QAccelerometer>
#include <QGyroscope>
#include <QAmbientLightSensor>
#include <QLightSensor>
#include <QCompass>

#include <QTimer>

QTM_USE_NAMESPACE

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

} // namespace
#endif // SENSORBUCKET_H
