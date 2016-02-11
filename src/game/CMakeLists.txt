cmake_minimum_required(VERSION 3.0)

find_package(Ruby REQUIRED)
include_directories(${RUBY_INCLUDE_DIRS})

ADD_RUBY_SCRIPT(bootstrap.rb)

set(SRC_FILES
        main.cpp
        bootstrap.rb.c
        )

include_directories("${CMAKE_CURRENT_BINARY_DIR}/../../lib/rpg") # Directory containing symbols.h.
include_directories(../../include/binding)

add_executable(Game ${SRC_FILES})
target_link_libraries(Game rgss rgss_rpg "${RUBY_LIBRARY}")

install(TARGETS Game DESTINATION .)
install(FILES "${RUBY_LIBRARY}" DESTINATION .)
