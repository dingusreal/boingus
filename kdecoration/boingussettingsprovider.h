#ifndef boingussettingsprovider_h
#define boingussettingsprovider_h
/*
 * SPDX-FileCopyrightText: 2014 Hugo Pereira Da Costa <hugo.pereira@free.fr>
 *
 * SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
 */

#include "boingusdecoration.h"
#include "boingussettings.h"
#include "boingus.h"

#include <KSharedConfig>

#include <QObject>

namespace Boingus
{

    class SettingsProvider: public QObject
    {

        Q_OBJECT

        public:

        //* destructor
        ~SettingsProvider();

        //* singleton
        static SettingsProvider *self();

        //* internal settings for given decoration
        InternalSettingsPtr internalSettings(Decoration *) const;

        public Q_SLOTS:

        //* reconfigure
        void reconfigure();

        private:

        //* constructor
        SettingsProvider();

        //* default configuration
        InternalSettingsPtr m_defaultSettings;

        //* exceptions
        InternalSettingsList m_exceptions;

        //* config object
        KSharedConfigPtr m_config;

        //* singleton
        static SettingsProvider *s_self;

    };

}

#endif
