### configuration plugin
add_definitions(-DTRANSLATION_DOMAIN=\"boingus_style_config\")
set(kstyle_boingus_config_PART_SRCS boingusstyleconfig.cpp)

set(kstyle_boingus_config_PART_SRCS ${kstyle_boingus_config_PART_SRCS} boingusstyleconfigmodule.cpp)

kconfig_add_kcfg_files(kstyle_boingus_config_PART_SRCS ../boingusstyleconfigdata.kcfgc)
set(kstyle_boingus_config_PART_FORMS ui/boingusstyleconfig.ui)
ki18n_wrap_ui(kstyle_boingus_config_PART_FORMS_HEADERS ${kstyle_boingus_config_PART_FORMS})

add_library(kstyle_boingus_config MODULE
    ${kstyle_boingus_config_PART_SRCS}
    ${kstyle_boingus_config_PART_FORMS_HEADERS}
)

target_link_libraries(kstyle_boingus_config Qt::Core Qt::Gui Qt::Widgets Qt::DBus)
target_link_libraries(kstyle_boingus_config KF5::CoreAddons KF5::ConfigCore KF5::ConfigWidgets KF5::I18n)
install(TARGETS kstyle_boingus_config DESTINATION ${KDE_INSTALL_QTPLUGINDIR})
install(FILES boingusstyleconfig.desktop DESTINATION  ${KDE_INSTALL_KSERVICES5DIR})

########### next target ###############
find_package(KF5KCMUtils CONFIG)
set_package_properties(KF5KCMUtils PROPERTIES
    DESCRIPTION "KF5 KCM utils Framework"
    URL "https://projects.kde.org/projects/frameworks/kcmutils"
    TYPE OPTIONAL
    PURPOSE "Required for boingus-settings5 application to build")

if( KF5KCMUtils_FOUND )
    set(boingus_settings_SOURCES main.cpp)
    add_executable(boingus-settings5 ${boingus_settings_SOURCES} )
    target_link_libraries(boingus-settings5 Qt::Core Qt::Gui Qt::Widgets )
    target_link_libraries(boingus-settings5 KF5::I18n KF5::KCMUtils)

    install(TARGETS boingus-settings5 ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

    # icon
    ecm_install_icons(ICONS sc-apps-boingus-settings.svgz
        DESTINATION ${KDE_INSTALL_ICONDIR}
        THEME hicolor )
endif()
