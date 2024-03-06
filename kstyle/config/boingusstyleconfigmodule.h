/*
 * SPDX-FileCopyrightText: 2014 Hugo Pereira Da Costa <hugo.pereira@free.fr>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef boingusstyleconfigmodule_h
#define boingusstyleconfigmodule_h

#include "boingusstyleconfig.h"

#include <KCModule>

namespace Boingus
{

    //* configuration module
    class ConfigurationModule: public KCModule
    {

        Q_OBJECT

        public:
        ConfigurationModule(QWidget *parent, const QVariantList &args);

        public Q_SLOTS:

        void defaults() override;
        void load() override;
        void save() override;

        private:

        //* configuration
        StyleConfig* m_config;

    };

}

#endif
