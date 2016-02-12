cmake_minimum_required(VERSION 3.0)

# The following is for the RGSS implementation library.

include_directories(../../include/rgss)

set(SRC_FILES
        Color.cpp
        )

add_library(rgss_impl STATIC ${SRC_FILES})
add_dependencies(rgss_impl sfml)
