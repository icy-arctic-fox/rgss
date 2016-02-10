cmake_minimum_required(VERSION 3.0)
project(rgss VERSION 3.0.1.1)

# Add platform-specific definitions.
if(WIN32)
    add_definitions(-DWINDOWS)
else()
    add_definitions(-DUNIX)
endif()

add_subdirectory(src/rb2c) # Must be defined first so that rb2c is available for rgss_rpg.
add_subdirectory(lib)
add_subdirectory(src)
