/*
 * SPDX-FileCopyrightText: 2014 Hugo Pereira Da Costa <hugo.pereira@free.fr>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "boingusstyleplugin.h"
#include "boingusstyle.h"

#include <QApplication>

namespace Boingus
{

    //_________________________________________________
    QStyle* StylePlugin::create( const QString &key )
    {
        if( key.toLower() == QStringLiteral( "boingus" ) )
        {
            return new Style;
        }
        return nullptr;
    }

    //_________________________________________________
    QStringList StylePlugin::keys() const
    { return QStringList( QStringLiteral( "Boingus" ) ); }

}
