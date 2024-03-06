/*
 * SPDX-FileCopyrightText: 2014 Hugo Pereira Da Costa <hugo.pereira@free.fr>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef boingusgeneric_data_h
#define boingusgeneric_data_h

#include "boingusanimationdata.h"
#include "boingusanimation.h"

#include <QObject>
#include <QTextStream>
namespace Boingus
{


    //* generic data
    class GenericData: public AnimationData
    {

        Q_OBJECT

        //* declare opacity property
        Q_PROPERTY( qreal opacity READ opacity WRITE setOpacity )

        public:

        //* constructor
        GenericData( QObject* parent, QWidget* widget, int duration );

        //* return animation object
        const Animation::Pointer& animation() const
        { return _animation; }

        //* duration
        void setDuration( int duration ) override
        { _animation.data()->setDuration( duration ); }

        //* opacity
        qreal opacity() const
        { return _opacity; }

        //* opacity
        void setOpacity( qreal value )
        {

            value = digitize( value );
            if( _opacity == value ) return;

            _opacity = value;
            setDirty();

        }

        private:

        //* animation handling
        Animation::Pointer _animation;

        //* opacity variable
        qreal _opacity = 0;

    };

}

#endif
