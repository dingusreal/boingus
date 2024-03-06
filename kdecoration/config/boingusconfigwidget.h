#ifndef boingusconfigwidget_h
#define boingusconfigwidget_h
//////////////////////////////////////////////////////////////////////////////
// boingusconfigurationui.h
// -------------------
//
// SPDX-FileCopyrightText: 2009 Hugo Pereira Da Costa <hugo.pereira@free.fr>
//
// SPDX-License-Identifier: MIT
//////////////////////////////////////////////////////////////////////////////

#include "ui_boingusconfigurationui.h"
#include "boingusexceptionlistwidget.h"
#include "boingussettings.h"
#include "boingus.h"

#include <KCModule>
#include <KSharedConfig>

#include <QWidget>
#include <QSharedPointer>

namespace Boingus
{

    //_____________________________________________
    class ConfigWidget: public KCModule
    {

        Q_OBJECT

        public:

        //* constructor
        explicit ConfigWidget( QWidget*, const QVariantList& );

        //* destructor
        virtual ~ConfigWidget() = default;

        //* default
        void defaults() override;

        //* load configuration
        void load() override;

        //* save configuration
        void save() override;

        protected Q_SLOTS:

        //* update changed state
        virtual void updateChanged();

        protected:

        //* set changed state
        void setChanged( bool );

        private:

        //* ui
        Ui_BoingusConfigurationUI m_ui;

        //* kconfiguration object
        KSharedConfig::Ptr m_configuration;

        //* internal exception
        InternalSettingsPtr m_internalSettings;

        //* changed state
        bool m_changed;

    };

}

#endif
