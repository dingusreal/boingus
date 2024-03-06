/*
 * SPDX-FileCopyrightText: 2014 Hugo Pereira Da Costa <hugo.pereira@free.fr>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef boingusbusyindicatorengine_h
#define boingusbusyindicatorengine_h

#include "boingusanimation.h"
#include "boingusbaseengine.h"
#include "boingusbusyindicatordata.h"
#include "boingusdatamap.h"

namespace Boingus
{

    //* handles progress bar animations
    class BusyIndicatorEngine: public BaseEngine
    {

        Q_OBJECT

        //* declare opacity property
        Q_PROPERTY( int value READ value WRITE setValue )

        public:

        //* constructor
        explicit BusyIndicatorEngine( QObject* );

        //*@name accessors
        //@{

        //* true if widget is animated
        bool isAnimated( const QObject* );

        //* value
        int value() const
        { return _value; }

        //@}

        //*@name modifiers
        //@{

        //* register progressbar
        bool registerWidget( QObject* );

        //* duration
        void setDuration( int ) override;

        //* set object as animated
        void setAnimated( const QObject*, bool );

        //* opacity
        void setValue( int value );

        //@}

        public Q_SLOTS:

        //* remove widget from map
        bool unregisterWidget( QObject* ) override;

        protected:

        //* returns data associated to widget
        DataMap<BusyIndicatorData>::Value data( const QObject* );

        private:

        //* map widgets to progressbar data
        DataMap<BusyIndicatorData> _data;

        //* animation
        Animation::Pointer _animation;

        //* value
        int _value = 0;

    };

}

#endif
