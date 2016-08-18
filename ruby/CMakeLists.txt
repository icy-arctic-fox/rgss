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

# Location of the Ruby to compiled into the engine.
set(RUBY_STAGE_DIR "${CMAKE_BINARY_DIR}/ruby-staging")
set(STAGED_RUBY_INCLUDE_PATH "${RUBY_STAGE_DIR}/include/${RUBY_GIT_TAG}")
set(STAGED_RUBY_LIBRARY "${RUBY_STAGE_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}ruby-static${CMAKE_STATIC_LIBRARY_SUFFIX}"
        CACHE INTERNAL "Path to static Ruby library"
        )
set(STAGED_RUBY_INCLUDE_DIR "${STAGED_RUBY_INCLUDE_PATH}" "${STAGED_RUBY_INCLUDE_PATH}/arch"
        CACHE INTERNAL "Path to staged Ruby header files"
        )

if(WIN32)
    # Window-specifics for compiling Ruby.

    # Compile Ruby for 64-bit if we're using 64-bit Visual Studio.
    if(CMAKE_GENERATOR MATCHES "Win64" OR "$ENV{Platform}" STREQUAL "X64")
        set(RUBY_TARGET x64-mswin64)
    else()
        set(RUBY_TARGET i386-mswin32)
    endif()

    # Search for bison and sed in common Ruby installations.
    file(GLOB_RECURSE BITNAMI_PATHS "$ENV{SystemDrive}/Bitnami/rubystack-*/DevKit/bin/bison.*")
    file(GLOB_RECURSE RUBY_INST_PATHS "$ENV{SystemDrive}/Ruby*/*/bin/bison.*")
    foreach(SEARCH_PATH ${BITNAMI_PATHS} ${RUBY_INST_PATHS})
        get_filename_component(BIN_PATH "${SEARCH_PATH}" DIRECTORY)
        set(CMAKE_PROGRAM_PATH ${CMAKE_PROGRAM_PATH} "${BIN_PATH}")
    endforeach(SEARCH_PATH)
    set(PROGRAM_FILES_X86 "ProgramFiles(x86)") # Work around for CMP0053.
    # Location where bison and sed setup packages install by default.
    set(CMAKE_PROGRAM_PATH ${CMAKE_PROGRAM_PATH} "$ENV{${PROGRAM_FILES_X86}}/GnuWin32/bin")

    # Required programs to compile Ruby.
    find_program(BISON_PROGRAM bison)
    if(BISON_PROGRAM STREQUAL "BISON_PROGRAM-NOTFOUND")
        message(FATAL_ERROR "bison is required to build Ruby")
    endif()
    find_program(SED_PROGRAM sed)
    if(SED_PROGRAM STREQUAL "SED_PROGRAM-NOTFOUND")
        message(FATAL_ERROR "sed is required to build Ruby")
    endif()

    # Modification of PATH for Ruby compilation.
    get_filename_component(BISON_BIN_PATH "${BISON_PROGRAM}" DIRECTORY)
    get_filename_component(SED_BIN_PATH "${SED_PROGRAM}" DIRECTORY)
    set(NEW_PATH_ENV "%PATH%$<SEMICOLON>${BISON_BIN_PATH}$<SEMICOLON>${SED_BIN_PATH}")

    # Various options for configuring Ruby.
    set(CONFIGURE_SCRIPT "win32/configure.bat")
    set(CONFIGURE_OPTIONS
            --target=${RUBY_TARGET}
            "--prefix=${RUBY_STAGE_DIR}"
            )

    set(RUBY_CONFIGURE "${CONFIGURE_SCRIPT}" ${CONFIGURE_OPTIONS})
    set(RUBY_BUILD
            set "PATH=${NEW_PATH_ENV}" # Add bison and sed to path.
            COMMAND nmake)
    set(RUBY_INSTALL nmake install)
else()
    # Linux-specifics for compiling Ruby.

    # Autoconf is needed to build Ruby.
    find_program(AUTOCONF_PROGRAM autoconf)
    if(AUTOCONF_PROGRAM STREQUAL "AUTOCONF_PROGRAM-NOTFOUND")
        message(FATAL_ERROR "autoconf is required to build Ruby")
    endif()

    # Various options for configuring Ruby.
    set(CONFIGURE_OPTIONS
            "--prefix=${RUBY_STAGE_DIR}"
            --disable-install-doc # Don't install documentation.
            --disable-install-rdoc
            --disable-install-capi
            "--with-rubyhdrdir=${STAGED_RUBY_INCLUDE_PATH}" # Install headers to paths CMake knows.
            "--with-rubyarchhdrdir=${STAGED_RUBY_INCLUDE_PATH}/arch"
            )

    set(RUBY_CONFIGURE "${AUTOCONF_PROGRAM}" COMMAND ./configure ${CONFIGURE_OPTIONS})
    set(RUBY_BUILD "${CMAKE_MAKE_PROGRAM}")
    set(RUBY_INSTALL "${CMAKE_MAKE_PROGRAM}" install)
endif()

# Add Ruby as an external project.
ExternalProject_Add(ruby
        GIT_REPOSITORY https://github.com/ruby/ruby.git
        GIT_TAG ${RUBY_GIT_TAG}
        CONFIGURE_COMMAND ${RUBY_CONFIGURE}
        BUILD_COMMAND ${RUBY_BUILD}
        BUILD_IN_SOURCE TRUE
        INSTALL_COMMAND ${RUBY_INSTALL}
    )

add_library(ruby-static STATIC IMPORTED GLOBAL)
add_dependencies(ruby-static ruby)
set_property(TARGET ruby-static PROPERTY IMPORTED_LOCATION "${STAGED_RUBY_LIBRARY}")
