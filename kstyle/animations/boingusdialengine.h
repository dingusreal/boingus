/*
 * SPDX-FileCopyrightText: 2014 Hugo Pereira Da Costa <hugo.pereira@free.fr>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef boingusdialengine_h
#define boingusdialengine_h

#include "boingusdialdata.h"
#include "boinguswidgetstateengine.h"

namespace Boingus
{

    //* stores dial hovered action and timeLine
    class DialEngine: public WidgetStateEngine
    {

        Q_OBJECT

        public:

        //* constructor
        explicit DialEngine( QObject* parent ):
            WidgetStateEngine( parent )
        {}

        //* destructor
        virtual ~DialEngine()
        {}

        //* register dial
        virtual bool registerWidget( QWidget*, AnimationModes );

        //* control rect
        virtual void setHandleRect( const QObject* object, const QRect& rect )
        {
            if( DataMap<WidgetStateData>::Value data = this->data( object, AnimationHover ) )
            { static_cast<DialData*>(data.data())->setHandleRect( rect ); }
        }

        //* mouse position
        virtual QPoint position( const QObject* object )
        {
            if( DataMap<WidgetStateData>::Value data = this->data( object, AnimationHover ) )
            {

                return static_cast<const DialData*>(data.data())->position();

            } else return QPoint( -1, -1 );
        }

    };

}

#endif
