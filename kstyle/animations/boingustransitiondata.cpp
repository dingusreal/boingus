//////////////////////////////////////////////////////////////////////////////
// boingustransitiondata.cpp
// data container for generic transitions
// -------------------
//
// SPDX-FileCopyrightText: 2009 Hugo Pereira Da Costa <hugo.pereira@free.fr>
//
// SPDX-License-Identifier: MIT
//////////////////////////////////////////////////////////////////////////////

#include "boingustransitiondata.h"

namespace Boingus
{

    //_________________________________________________________________
    TransitionData::TransitionData( QObject* parent, QWidget* target, int duration ):
        QObject( parent ),
        _transition( new TransitionWidget( target, duration ) )
    { _transition.data()->hide(); }

    //_________________________________________________________________
    TransitionData::~TransitionData()
    { if( _transition ) _transition.data()->deleteLater(); }

}
