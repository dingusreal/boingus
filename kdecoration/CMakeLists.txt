add_definitions(-DTRANSLATION_DOMAIN="boingus_kwin_deco")

find_package(KF5 REQUIRED COMPONENTS CoreAddons GuiAddons ConfigWidgets WindowSystem I18n IconThemes)
find_package(Qt5 CONFIG REQUIRED COMPONENTS DBus)

### XCB
find_package(XCB COMPONENTS XCB)
set_package_properties(XCB PROPERTIES
  DESCRIPTION "X protocol C-language Binding"
  URL "https://xcb.freedesktop.org"
  TYPE OPTIONAL
  PURPOSE "Required to pass style properties to native Windows on X11 Platform"
)

if(UNIX AND NOT APPLE)

  set(BOINGUS_HAVE_X11 ${XCB_XCB_FOUND})
  if (XCB_XCB_FOUND)
    find_package(Qt5 REQUIRED CONFIG COMPONENTS X11Extras)
  endif()

else()

  set(BOINGUS_HAVE_X11 FALSE)

endif()

################# configuration #################
configure_file(config-boingus.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config-boingus.h )

################# includes #################
include_directories(${CMAKE_SOURCE_DIR}/libboinguscommon)
include_directories(${CMAKE_BINARY_DIR}/libboinguscommon)

################# newt target #################
### plugin classes
set(boingusdecoration_SRCS
    boingusbutton.cpp
    boingusdecoration.cpp
    boingusexceptionlist.cpp
    boingussettingsprovider.cpp
    boingussizegrip.cpp)

kconfig_add_kcfg_files(boingusdecoration_SRCS boingussettings.kcfgc)

### config classes
### they are kept separately because they might move in a separate library in the future
set(boingusdecoration_config_SRCS
    config/boingusconfigwidget.cpp
    config/boingusdetectwidget.cpp
    config/boingusexceptiondialog.cpp
    config/boingusexceptionlistwidget.cpp
    config/boingusexceptionmodel.cpp
    config/boingusitemmodel.cpp
)

set(boingusdecoration_config_PART_FORMS
   config/ui/boingusconfigurationui.ui
   config/ui/boingusdetectwidget.ui
   config/ui/boingusexceptiondialog.ui
   config/ui/boingusexceptionlistwidget.ui
)

ki18n_wrap_ui(boingusdecoration_config_PART_FORMS_HEADERS ${boingusdecoration_config_PART_FORMS})

### build library
add_library(boingusdecoration MODULE
    ${boingusdecoration_SRCS}
    ${boingusdecoration_config_SRCS}
    ${boingusdecoration_config_PART_FORMS_HEADERS})

target_link_libraries(boingusdecoration
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::DBus
    PRIVATE
        boinguscommon5
        KDecoration2::KDecoration
        KF5::ConfigCore
        KF5::CoreAddons
        KF5::ConfigWidgets
        KF5::GuiAddons
        KF5::I18n
        KF5::IconThemes
        KF5::WindowSystem)

if(BOINGUS_HAVE_X11)
  target_link_libraries(boingusdecoration
    PUBLIC
      Qt::X11Extras
      XCB::XCB)
endif()


install(TARGETS boingusdecoration DESTINATION ${KDE_INSTALL_PLUGINDIR}/org.kde.kdecoration2)
install(FILES config/boingusdecorationconfig.desktop DESTINATION  ${KDE_INSTALL_KSERVICES5DIR})
