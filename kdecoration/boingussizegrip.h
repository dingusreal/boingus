/*
 * SPDX-FileCopyrightText: 2014 Hugo Pereira Da Costa <hugo.pereira@free.fr>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef boingussizegrip_h
#define boingussizegrip_h

#include "boingusdecoration.h"
#include "config-boingus.h"

#include <QMouseEvent>
#include <QPaintEvent>
#include <QWidget>
#include <QPointer>

#if BOINGUS_HAVE_X11
#include <xcb/xcb.h>
#endif

namespace Boingus
{

    //* implements size grip for all widgets
    class SizeGrip: public QWidget
    {

        Q_OBJECT

        public:

        //* constructor
        explicit SizeGrip( Decoration* );

        //* constructor
        virtual ~SizeGrip();

        protected Q_SLOTS:

        //* update background color
        void updateActiveState();

        //* update position
        void updatePosition();

        //* embed into parent widget
        void embed();

        protected:

        //*@name event handlers
        //@{

        //* paint
        virtual void paintEvent( QPaintEvent* ) override;

        //* mouse press
        virtual void mousePressEvent( QMouseEvent* ) override;

        //@}

        private:

        //* send resize event
        void sendMoveResizeEvent( QPoint );

        //* grip size
        enum {
            Offset = 0,
            GripSize = 14,
        };

        //* decoration
        QPointer<Decoration> m_decoration;

        //* move/resize atom
        #if BOINGUS_HAVE_X11
        xcb_atom_t m_moveResizeAtom = 0;
        #endif

    };


}

#endif
