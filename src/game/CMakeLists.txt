cmake_minimum_required(VERSION 3.0)

set(SRC_FILES
        )

add_executable(Game ${SRC_FILES})
target_link_libraries(Game rgss rgss_rpg)
