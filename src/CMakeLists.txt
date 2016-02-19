cmake_minimum_required(VERSION 3.0)
include(sfml)

add_subdirectory(rgss)
add_subdirectory(binding)
add_subdirectory(game)
# rb2c is included one directory up, since it is needed for rgss_rpg and that is needed for game.
