/*
 * SPDX-FileCopyrightText: 2014 Hugo Pereira Da Costa <hugo.pereira@free.fr>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef boingusaddeventfilter_h
#define boingusaddeventfilter_h

#include <QObject>
#include <QEvent>

namespace Boingus
{

    class AddEventFilter: public QObject
    {

        Q_OBJECT

        public:

        //* constructor
        AddEventFilter():
            QObject()
            {}

        //* event filter
        /** blocks all AddChild events */
        bool eventFilter( QObject*, QEvent* event ) override
        { return event->type() == QEvent::ChildAdded; }

    };

}

#endif
