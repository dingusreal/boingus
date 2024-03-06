//////////////////////////////////////////////////////////////////////////////
// boingusanimationconfigitem.h
// animation configuration item
// -------------------
//
// SPDX-FileCopyrightText: 2010 Hugo Pereira Da Costa <hugo.pereira@free.fr>
//
// SPDX-License-Identifier: MIT
//////////////////////////////////////////////////////////////////////////////

#include <QAbstractScrollArea>
#include <QApplication>
#include <QIcon>

#include <KCMultiDialog>
#include <KLocalizedString>

//__________________________________________
int main(int argc, char *argv[])
{
    KLocalizedString::setApplicationDomain("boingus_style_config");

    QApplication app( argc, argv );
    app.setApplicationName( i18n( "Boingus Settings" ) );
    app.setWindowIcon( QIcon::fromTheme( QStringLiteral( "boingus-settings" ) ) );

    KCMultiDialog dialog;
    dialog.setWindowTitle( i18n( "Boingus Settings" ) );
    dialog.addModule( QStringLiteral( "boingusstyleconfig" ) );
    dialog.addModule( QStringLiteral( "boingusdecorationconfig" ) );
    dialog.show();

    foreach( auto child, dialog.findChildren<QAbstractScrollArea*>() )
    {
        child->adjustSize();
        child->viewport()->adjustSize();
    }

    return app.exec();
}
