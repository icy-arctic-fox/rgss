cmake_minimum_required(VERSION 3.0)
include(ExternalProject)

# This CMake file is to build a static version of Ruby.
# A static copy is linked to remove the need for end-users installing Ruby themselves.
# Most end-users will be gamers, not developers that can figure out how to install Ruby.

# If this is set to true, then Ruby 1.9.3 will be used, which is the same version released with RPG Maker VX.
# If this is set to false, then a newer version or Ruby will be used (> 2.0).
set(USE_LEGACY_RUBY FALSE)

if(USE_LEGACY_RUBY)
    set(RUBY_GIT_TAG ruby_1_9_3)
else()
    set(RUBY_GIT_TAG v2_3_1)
endif()

# Annoyingly, Ruby is required to be on the system already to build any Ruby after 1.9.
find_package(Ruby REQUIRED)

# Autoconf is needed to build Ruby.
find_program(AUTOCONF_PROGRAM autoconf)
if(AUTOCONF_PROGRAM STREQUAL "AUTOCONF_PROGRAM-NOTFOUND")
    message(FATAL_ERROR "autoconf is required to build Ruby")
endif()

# Location of the Ruby to compiled into the engine.
set(RUBY_STAGE_DIR "${CMAKE_BINARY_DIR}/ruby-staging")

# Add Ruby as an external project.
ExternalProject_Add(ruby
        GIT_REPOSITORY https://github.com/ruby/ruby.git
        GIT_TAG ${RUBY_GIT_TAG}
        CONFIGURE_COMMAND "${AUTOCONF_PROGRAM}" COMMAND ./configure "--prefix=${RUBY_STAGE_DIR}"
        BUILD_COMMAND "${CMAKE_MAKE_PROGRAM}"
        BUILD_IN_SOURCE TRUE
        INSTALL_COMMAND "${CMAKE_MAKE_PROGRAM}" install
    )

set(STAGED_RUBY_INCLUDE_DIR "${RUBY_STAGE_DIR}/include"
        CACHE INTERNAL "Path to staged Ruby header files"
    )
set(STAGED_RUBY_LIBRARY "${RUBY_STAGE_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}ruby-static.${CMAKE_STATIC_LIBRARY_SUFFIX}"
        CACHE INTERNAL "Path to static Ruby library"
    )

add_library(ruby-static STATIC IMPORTED)
add_dependencies(ruby-static ruby)
set_property(TARGET ruby-static PROPERTY IMPORTED_LOCATION "${STAGED_RUBY_LIBRARY}")
