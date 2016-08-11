cmake_minimum_required(VERSION 3.0)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
project(rgss VERSION 3.0.1.1)

# Add platform-specific definitions.
if(WIN32)
    add_definitions(-DWINDOWS)
else()
    add_definitions(-DUNIX)
endif()

# Turn up warnings.
if(MSVC)
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} /W4")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()

add_subdirectory(ruby)
add_subdirectory(src/rb2c) # Must be defined first so that rb2c is available for rgss_rpg.
add_subdirectory(lib)
add_subdirectory(src)
