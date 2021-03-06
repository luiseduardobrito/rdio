find_package(Vala REQUIRED)
include(ValaVersion)
ensure_vala_version("0.17.5" MINIMUM)
include(ValaPrecompile)

vala_precompile(VALA_C
    config.vala
    Rdio.vala
    Settings.vala
    Window.vala
    Middleware.vala
    CustomTitleBar.vala
    OverlayLabel.vala
    KeybindingManager.vala
    MediaKeyListener.vala
    MPRIS.vala
    SoundMenuIntegration.vala
    UnityIntegration.vala
    Notifier.vala   
    Utils/Networking.vala
    
PACKAGES
    glib-2.0
    gtk+-3.0
    x11
    gdk-x11-3.0
    gio-2.0
    libsoup-2.4
    json-glib-1.0
    webkitgtk-3.0
    ${ADD_PKG}

OPTIONS
    --vapidir=${CMAKE_SOURCE_DIR}/vapi
    --target-glib=2.32
    ${ADD_OPTIONS}
)

add_executable(${CMAKE_PROJECT_NAME} ${VALA_C})
link_directories(${DEPS_LIBRARY_DIRS} ${INDICATE_LIBRARY_DIRS} ${DBUS_MENU_LIBRARY_DIRS} ${UNITY_LIBRARY_DIRS} ${LIBNOTIFY_LIBRARY_DIRS})
add_definitions(${DEPS_CFLAGS} ${INDICATE_CFLAGS} ${DBUS_MENU_CFLAGS} ${UNITY_CFLAGS} ${LIBNOTIFY_CFLAGS})
target_link_libraries(${CMAKE_PROJECT_NAME} ${DEPS_LIBRARIES} ${DBUS_MENU_LIBRARIES} ${INDICATE_LIBRARIES} ${UNITY_LIBRARIES} ${LIBNOTIFY_LIBRARIES})
install(TARGETS ${CMAKE_PROJECT_NAME} RUNTIME DESTINATION bin)
