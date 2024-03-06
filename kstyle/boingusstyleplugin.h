/*
 * SPDX-FileCopyrightText: 2014 Hugo Pereira Da Costa <hugo.pereira@free.fr>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef boingusstyleplugin_h
#define boingusstyleplugin_h

#include <QStylePlugin>

namespace Boingus
{

    class StylePlugin : public QStylePlugin
    {

        Q_OBJECT

        Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QStyleFactoryInterface" FILE "boingus.json" )

        public:

        //* constructor
        explicit StylePlugin(QObject *parent = nullptr):
            QStylePlugin(parent)
        {}

        //* returns list of valid keys
        QStringList keys() const;

        //* create style
        QStyle* create( const QString& ) override;

    };

}

#endif
