################# Qt/KDE #################
find_package(Qt5 ${QT_MIN_VERSION} REQUIRED CONFIG COMPONENTS Widgets DBus)
find_package(KF5 REQUIRED COMPONENTS
    I18n
    Config
    GuiAddons
    IconThemes
    ConfigWidgets
    WindowSystem)

find_package(Qt5 COMPONENTS Quick X11Extras)
set(BOINGUS_HAVE_QTQUICK ${Qt5Quick_FOUND})
set(BOINGUS_HAVE_QTX11EXTRAS ${Qt5X11Extras_FOUND})

find_package( KF5FrameworkIntegration CONFIG )
set_package_properties(KF5FrameworkIntegration PROPERTIES
    DESCRIPTION "KF5 Framework Integration"
    URL "https://projects.kde.org/projects/frameworks/frameworkintegration"
    TYPE OPTIONAL
    PURPOSE "Required to use KStyle convenience functionalities in style")

set(BOINGUS_HAVE_KSTYLE ${KF5FrameworkIntegration_FOUND})


################# includes #################
include_directories(
  animations
  debug
)

include_directories(${CMAKE_SOURCE_DIR}/libboinguscommon)
include_directories(${CMAKE_BINARY_DIR}/libboinguscommon)

################# configuration #################
configure_file(config-boingus.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config-boingus.h )

########### next target ###############
set(boingus_PART_SRCS
    animations/boingusanimation.cpp
    animations/boingusanimations.cpp
    animations/boingusanimationdata.cpp
    animations/boingusbaseengine.cpp
    animations/boingusbusyindicatordata.cpp
    animations/boingusbusyindicatorengine.cpp
    animations/boingusdialdata.cpp
    animations/boingusdialengine.cpp
    animations/boingusenabledata.cpp
    animations/boingusgenericdata.cpp
    animations/boingusheaderviewdata.cpp
    animations/boingusheaderviewengine.cpp
    animations/boingusscrollbardata.cpp
    animations/boingusscrollbarengine.cpp
    animations/boingusspinboxengine.cpp
    animations/boingusspinboxdata.cpp
    animations/boingusstackedwidgetdata.cpp
    animations/boingusstackedwidgetengine.cpp
    animations/boingustabbarengine.cpp
    animations/boingustabbardata.cpp
    animations/boingustoolboxengine.cpp
    animations/boingustransitiondata.cpp
    animations/boingustransitionwidget.cpp
    animations/boinguswidgetstateengine.cpp
    animations/boinguswidgetstatedata.cpp
    debug/boinguswidgetexplorer.cpp
    boingusaddeventfilter.cpp
    boingusblurhelper.cpp
    boingusframeshadow.cpp
    boingushelper.cpp
    boingusmdiwindowshadow.cpp
    boingusmnemonics.cpp
    boinguspropertynames.cpp
    boingusshadowhelper.cpp
    boingussplitterproxy.cpp
    boingusstyle.cpp
    boingusstyleplugin.cpp
    boingustileset.cpp
    boinguswindowmanager.cpp
    boingustoolsareamanager.cpp
)

kconfig_add_kcfg_files(boingus_PART_SRCS ../kdecoration/boingussettings.kcfgc)
kconfig_add_kcfg_files(boingus_PART_SRCS boingusstyleconfigdata.kcfgc)
add_library(boingus MODULE ${boingus_PART_SRCS})
target_link_libraries(boingus Qt::Core Qt::Gui Qt::Widgets Qt::DBus)
if( BOINGUS_HAVE_QTQUICK )
    target_link_libraries(boingus Qt::Quick)
endif()
if (BOINGUS_HAVE_QTX11EXTRAS)
    target_link_libraries(boingus Qt::X11Extras)
endif()
target_link_libraries(boingus KF5::ConfigCore KF5::ConfigWidgets KF5::GuiAddons KF5::IconThemes KF5::WindowSystem)
target_link_libraries(boingus boinguscommon5)

if(KF5FrameworkIntegration_FOUND)
    target_link_libraries(boingus KF5::Style)
endif()

if (WIN32)
    # As stated in https://docs.microsoft.com/en-us/cpp/c-runtime-library/math-constants M_PI only gets defined
    # when if _USE_MATH_DEFINES is defined
    target_compile_definitions(boingus PRIVATE _USE_MATH_DEFINES _BSD_SOURCE)
endif()


########### install files ###############
install(TARGETS boingus DESTINATION ${KDE_INSTALL_QTPLUGINDIR}/styles/)
install(FILES boingus.themerc  DESTINATION  ${KDE_INSTALL_DATADIR}/kstyle/themes)

########### subdirectories ###############
add_subdirectory(config)
