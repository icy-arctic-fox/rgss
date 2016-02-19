cmake_minimum_required(VERSION 3.0)

include_directories(../../include/rgss)

set(SRC_FILES
        Color.cpp
        Rect.cpp
        Table.cpp
        Tone.cpp
        )

add_library(rgss_impl STATIC ${SRC_FILES})
LINK_SFML(rgss_impl)
