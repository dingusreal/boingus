# In this CMakeLists.txt we define which files
# are used to compile the application
set(kde4boingus_SRCS
   #application.cpp
   main.cpp
 )

# Set the name of the application
add_executable(kde4boingus ${kde4boingus_SRCS})

# Select which libraries we need to link to
target_link_libraries(kde4boingus Qt::Widgets KF5::CoreAddons KF5::ConfigCore)

# Tell cmake to install the application binary
install(TARGETS kde4boingus DESTINATION ${KDE_INSTALL_LIBDIR}/kconf_update_bin/)
install(FILES kde4boingus.upd DESTINATION ${KDE_INSTALL_KCONFUPDATEDIR})

# Install the color scheme

