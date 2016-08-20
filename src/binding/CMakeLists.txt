cmake_minimum_required(VERSION 3.0)

# Obviously need Ruby for a Ruby binding.
# However, things are a bit strange here.
# The gem version of RGSS should link against the current Ruby.
# The bundled engine should link against the staged Ruby.
if(NOT SHARED_RUBY_BINDING)
    find_program(RUBY ruby)
    if(NOT RUBY)
        message(FATAL_ERROR "Existing Ruby installation is required to compile Ruby 1.9+")
    endif()
else()
    find_package(Ruby REQUIRED)
endif()
include_directories(${RUBY_INCLUDE_DIRS})

# Ignore xkeycheck.h as it conflicts.
if(MSVC)
    add_definitions(/D_XKEYCHECK_H)
endif()

# Include headers from RGSS implementation.
include_directories(../../include/rgss)

set(SRC_FILES
        Audio.cpp
        Graphics.cpp
        Input.cpp
        Bitmap.cpp
        Color.cpp
        Font.cpp
        Plane.cpp
        Rect.cpp
        Sprite.cpp
        Table.cpp
        Tilemap.cpp
        Tone.cpp
        Viewport.cpp
        Window.cpp
        RGSSError.c
        RGSSReset.c
        functions.cpp
        RGSS.cpp
        )

add_library(rgss SHARED ${SRC_FILES})

# Static link the RGSS and function implementation libraries.
target_link_libraries(rgss rgss_impl rgss_functions)

# Here we use a shared Ruby library from the system to resolve links.
# But when the game executable is created, the staged Ruby will be linked against.
if(SHARED_RUBY_BINDING)
    target_link_libraries(rgss ${RUBY_LIBRARY})
elseif(MSVC)
    target_link_libraries(rgss ruby-dynamic)
endif()

install(TARGETS rgss DESTINATION .)

# Custom "install" target for just building and installing the native extension.
add_custom_target(install.native-extension
        "${CMAKE_COMMAND}" -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_install.cmake"
        DEPENDS rgss
        COMMENT Installing Ruby native extension from ${CMAKE_CURRENT_BINARY_DIR}
        )
