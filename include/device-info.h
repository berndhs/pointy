#ifndef GEUZEN_DEVICE_INFO_H
#define GEUZEN_DEVICE_INFO_H

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
#include <QObject>


namespace geuzen
{

class DeviceInfo  : public QObject
{
Q_OBJECT
public:

  DeviceInfo (QObject *parent=0);
  Q_PROPERTY(QString sysName READ sysName NOTIFY sysNameChanged)
  Q_PROPERTY(QString kernel READ kernel NOTIFY kernelChanged)
  Q_PROPERTY(QString cpu READ cpu NOTIFY cpuChanged)
  Q_INVOKABLE void start ();

  QString sysName() const;

  QString kernel() const;

  QString cpu() const;

signals:

  
  void sysNameChanged(QString sysName);

  void kernelChanged(QString kernel);

  void cpuChanged(QString cpu);

private slots:

  void collectInfo ();
  
private:

};

} // namespace

#endif // DEVICEINFO_H
