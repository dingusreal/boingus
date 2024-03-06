find_package(KF5ConfigWidgets REQUIRED)

add_executable(boingustoboinguslight main.cpp)

target_link_libraries(boingustoboinguslight KF5::ConfigWidgets)

install(TARGETS boingustoboinguslight DESTINATION ${KDE_INSTALL_LIBDIR}/kconf_update_bin/)
install(FILES boingustoboinguslight.upd DESTINATION ${KDE_INSTALL_KCONFUPDATEDIR})
