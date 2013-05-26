/* ============================================================
* StatusBarIcons - Extra icons in statusbar for QupZilla
* Copyright (C) 2013  David Rosca <nowrep@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#ifndef SBI_ICONSMANAGER_H
#define SBI_ICONSMANAGER_H

#include <QWidget>
#include <QHash>

class QupZilla;

class SBI_IconsManager : public QObject
{
    Q_OBJECT
public:
    explicit SBI_IconsManager(const QString &settingsPath, QObject* parent = 0);

    void loadSettings();

    void reloadIcons();
    void destroyIcons();

signals:

public slots:
    void mainWindowCreated(QupZilla* window);
    void mainWindowDeleted(QupZilla* window);

private:
    QString m_settingsPath;
    bool m_showImagesIcon;
    bool m_showJavaScriptIcon;
    bool m_showNetworkIcon;

    QHash<QupZilla*, QWidgetList> m_windows;
};

#endif // SBI_ICONSMANAGER_H