################# dependencies #################
### Qt/KDE
find_package(Qt5 REQUIRED CONFIG COMPONENTS Widgets)

################# boingusstyle target #################
set(boinguscommon_LIB_SRCS
    boingusboxshadowrenderer.cpp
)

add_library(boinguscommon5 ${boinguscommon_LIB_SRCS})

generate_export_header(boinguscommon5
    BASE_NAME boinguscommon
    EXPORT_FILE_NAME boinguscommon_export.h)

target_link_libraries(boinguscommon5
    PUBLIC
        Qt::Core
        Qt::Gui)

set_target_properties(boinguscommon5 PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR})

install(TARGETS boinguscommon5 ${KDE_INSTALL_TARGETS_DEFAULT_ARGS} LIBRARY NAMELINK_SKIP)
