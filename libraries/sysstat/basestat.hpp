/*************
**
** Project:      Qt-based interface to system statistics (libsysstat)
** Author:       Copyright (C) 2009 - 2012 Kuzma Shapran <Kuzma.Shapran@gmail.com>
** License:      LGPLv3
**
**  This file is part of SysStat library.
**
**  This library is free software; you can redistribute it and/or modify it
**  under the terms of the GNU Lesser General Public License as published by
**  the Free Software Foundation; either version 3 of the License, or any
**  later version. This work is distributed in the hope that it will be
**  useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
**  See the GNU Lesser General Public License for more details.
**
**  You should have received a copy of the GNU Lesser General Public License
**  along with the library.
**  If not, see <http://www.gnu.org/licenses/lgpl.html>.
**
*************/


#ifndef LIBSYSSTAT__BASE_STAT__INCLUDED
#define LIBSYSSTAT__BASE_STAT__INCLUDED


#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>

#include <sysstat/sysstat_global.hpp>


namespace SysStat {

class BaseStatPrivate;

class SYSSTATSHARED_EXPORT BaseStat : public QObject
{
    Q_OBJECT

public:
    BaseStat(QObject *parent = NULL);
    ~BaseStat();

    QStringList sources(void) const;

signals:
    void updateIntervalChanged(int);
    void monitoredSourceChanged(QString);

public:
    Q_PROPERTY(int updateInterval READ updateInterval WRITE setUpdateInterval RESET stopUpdating NOTIFY updateIntervalChanged)
    Q_PROPERTY(QString monitoredSource READ monitoredSource WRITE setMonitoredSource RESET monitorDefaultSource NOTIFY monitoredSourceChanged)

public slots:
    int updateInterval(void) const;
    void setUpdateInterval(int msec);
    void stopUpdating(void);

    QString monitoredSource(void) const;
    void setMonitoredSource(const QString &Source);
    void monitorDefaultSource(void);

protected:
    BaseStatPrivate* baseimpl;
};

}

#endif //LIBSYSSTAT__BASE_STAT__INCLUDED
