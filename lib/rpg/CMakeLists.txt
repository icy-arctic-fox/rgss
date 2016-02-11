cmake_minimum_required(VERSION 3.0)

file(GLOB_RECURSE RB_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" *.rb)

foreach(RB_FILE ${RB_FILES})
    ADD_RUBY_SCRIPT(${RB_FILE})
    SET(SRC_FILES ${SRC_FILES} ${RB_FILE}.c)
endforeach(RB_FILE)

add_library(rgss_rpg STATIC ${SRC_FILES})
