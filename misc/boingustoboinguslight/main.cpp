#include <KColorScheme>
#include <KConfig>
#include <KConfigGroup>

#include <QDebug>

int main()
{
    KConfig globals("kdeglobals");
    KConfigGroup general(&globals, "General");
    if (general.readEntry("ColorScheme") != QLatin1String("Boingus")) {
        return 0;
    }
    QString boingusLightPath = QStandardPaths::locate(QStandardPaths::GenericDataLocation, QStringLiteral("color-schemes/BoingusLight.colors"));
    if (boingusLightPath.isEmpty()) {
        return 0;
    }
    KConfig boingusLight(boingusLightPath, KConfig::SimpleConfig);
    for (const auto &group : boingusLight.groupList()) {
        auto destination = KConfigGroup(&globals, group);
        KConfigGroup(&boingusLight, group).copyTo(&destination, KConfig::Notify);
    }
}
