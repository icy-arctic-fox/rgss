cmake_minimum_required(VERSION 3.0)

set(SRC_FILES
        )

add_library(rgss ${SRC_FILES})
target_link_libraries(rgss rgss_impl)
