/*
 * SPDX-FileCopyrightText: 2014 Hugo Pereira Da Costa <hugo.pereira@free.fr>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "boingusstyleconfigmodule.h"

#include <KPluginFactory>


K_PLUGIN_FACTORY(
    BoingusStyleConfigFactory,
    registerPlugin<Boingus::ConfigurationModule>(QStringLiteral("kcmodule"));
)

#include "boingusstyleconfigmodule.moc"

namespace Boingus
{

    //_______________________________________________________________________
    ConfigurationModule::ConfigurationModule(QWidget *parent, const QVariantList &args):
        KCModule(parent, args)
    {
        setLayout(new QVBoxLayout(this));
        layout()->addWidget( m_config = new StyleConfig( this ) );
        connect(m_config, static_cast<void (StyleConfig::*)(bool)>(&StyleConfig::changed), this, static_cast<void (KCModule::*)(bool)>(&KCModule::changed));
    }

    //_______________________________________________________________________
    void ConfigurationModule::defaults()
    {
        m_config->defaults();
        KCModule::defaults();
    }

    //_______________________________________________________________________
    void ConfigurationModule::load()
    {
        m_config->load();
        KCModule::load();
    }

    //_______________________________________________________________________
    void ConfigurationModule::save()
    {
        m_config->save();
        KCModule::save();
    }

}
