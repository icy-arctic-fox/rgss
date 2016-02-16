cmake_minimum_required(VERSION 3.0)

ADD_RUBY_SCRIPT(functions.rb)
add_library(rgss_functions STATIC functions.rb.c)

add_subdirectory(rpg)
