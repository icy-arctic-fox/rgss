cmake_minimum_required(VERSION 3.0)

# Obviously need Ruby for a Ruby binding.
find_package(Ruby REQUIRED)
include_directories(${RUBY_INCLUDE_DIRS})

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
target_link_libraries(rgss rgss_impl rgss_functions "${RUBY_LIBRARY}")

install(TARGETS rgss DESTINATION .)
