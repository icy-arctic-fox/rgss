cmake_minimum_required(VERSION 3.0)

# Shared base source files.
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
        )

# Include Ruby headers.
include_directories(${RUBY_INCLUDE_DIRS})

# Include headers from RGSS implementation.
include_directories(../../include/rgss)

# Ignore xkeycheck.h as it conflicts with Ruby internals.
if(MSVC)
    add_definitions(/D_XKEYCHECK_H)
endif()

# Shared base library for binding and engine.
add_library(rgss_base STATIC ${SRC_FILES})
target_link_libraries(rgss_base rgss_impl rgss_functions)

if(SHARED_RUBY_BINDING)
    # Find and use the system Ruby.
    find_package(Ruby REQUIRED)

    # This library is for Ruby to invoke as part of a gem (native extension).
    add_library(rgss SHARED binding.cpp)
    target_link_libraries(rgss ${RUBY_LIBRARY})

    # Custom "install" target for just building and installing the native extension.
    install(TARGETS rgss DESTINATION .)
    add_custom_target(install.native-extension
            "${CMAKE_COMMAND}" -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_install.cmake"
            DEPENDS rgss
            COMMENT Installing Ruby native extension from ${CMAKE_CURRENT_BINARY_DIR}
            )
endif()

# Set name of engine library to match original.
set(RGSS_ENGINE RGSS${PROJECT_VERSION_MAJOR}${PROJECT_VERSION_MINOR}${PROJECT_VERSION_PATCH}
        CACHE STRING "Name of RGSS engine library"
        )

# Include Ruby, Ruby binding, RPG namespace, and engine entry-point.
add_library(${RGSS_ENGINE} SHARED binding.cpp RGSS.cpp)
target_link_libraries(${RGSS_ENGINE} rgss_base rgss_rpg ruby-static)

# Linkages needed for Ruby.
if(UNIX)
    target_link_libraries(${RGSS_ENGINE} pthread gmp dl crypt)
elseif(MSVC)
    target_link_libraries(${RGSS_ENGINE} iphlpapi dbghelp shlwapi)
endif()

# Header for exporting symbols from dynamic libraries.
include(GenerateExportHeader)
generate_export_header(${RGSS_ENGINE}
        BASE_NAME rgss
        EXPORT_MACRO_NAME RGSS_EXPORT
        EXPORT_FILE_NAME rgss_export.h
        STATIC_DEFINE RGSS_STATIC
        )
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# Make library be accessible side-by-side with game executable.
install(TARGETS ${RGSS_ENGINE} DESTINATION .)
