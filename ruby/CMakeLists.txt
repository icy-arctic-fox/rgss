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
set(STAGED_RUBY_INCLUDE_PATH "${RUBY_STAGE_DIR}/include/${RUBY_GIT_TAG}")
set(STAGED_RUBY_LIBRARY "${RUBY_STAGE_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}ruby-static${CMAKE_STATIC_LIBRARY_SUFFIX}"
        CACHE INTERNAL "Path to static Ruby library"
        )
set(STAGED_RUBY_INCLUDE_DIR "${STAGED_RUBY_INCLUDE_PATH}" "${STAGED_RUBY_INCLUDE_PATH}/arch"
        CACHE INTERNAL "Path to staged Ruby header files"
        )

# Various options for configuring Ruby.
set(CONFIGURE_OPTIONS
        "--prefix=${RUBY_STAGE_DIR}"
        --disable-install-doc # Don't install documentation.
        --disable-install-rdoc
        --disable-install-capi
        "--with-rubyhdrdir=${STAGED_RUBY_INCLUDE_PATH}" # Install headers to paths CMake knows.
        "--with-rubyarchhdrdir=${STAGED_RUBY_INCLUDE_PATH}/arch"
        )

# Add Ruby as an external project.
ExternalProject_Add(ruby
        GIT_REPOSITORY https://github.com/ruby/ruby.git
        GIT_TAG ${RUBY_GIT_TAG}
        CONFIGURE_COMMAND "${AUTOCONF_PROGRAM}" COMMAND ./configure ${CONFIGURE_OPTIONS}
        BUILD_COMMAND "${CMAKE_MAKE_PROGRAM}"
        BUILD_IN_SOURCE TRUE
        INSTALL_COMMAND "${CMAKE_MAKE_PROGRAM}" install
    )

add_library(ruby-static STATIC IMPORTED GLOBAL)
add_dependencies(ruby-static ruby)
set_property(TARGET ruby-static PROPERTY IMPORTED_LOCATION "${STAGED_RUBY_LIBRARY}")
