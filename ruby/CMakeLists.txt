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
    set(STAGED_RUBY_VERSION 1.9.0)
    set(STAGED_RUBY_VERSION_NODOT 190)
else()
    set(RUBY_GIT_TAG v2_3_1)
    set(STAGED_RUBY_VERSION 2.3.0)
    set(STAGED_RUBY_VERSION_NODOT 230)
endif()

# Annoyingly, Ruby is required to be on the system already to build any Ruby after 1.9.
find_program(RUBY ruby)
if(NOT RUBY)
    message(FATAL_ERROR "Existing Ruby installation is required to compile Ruby 1.9+")
endif()

# Location of the Ruby to compiled into the engine.
set(RUBY_STAGE_DIR "${CMAKE_BINARY_DIR}/ruby-staging")

if(WIN32)
    set(PROGRAM_FILES_X86 "ProgramFiles(x86)") # Work around for CMP0053.

    # Location where some utilities are installed by default.
    set(CMAKE_PROGRAM_PATH ${CMAKE_PROGRAM_PATH}
            "$ENV{SystemDrive}/MinGW/bin"
            "$ENV{SystemDrive}/MinGW/msys/1.0/bin"
            "$ENV{${PROGRAM_FILES_X86}}/GnuWin32/bin"
            )

    # Search for programs in common Ruby installations.
    file(GLOB_RECURSE BITNAMI_PATHS "$ENV{SystemDrive}/Bitnami/rubystack-*/DevKit/bin/bison.*")
    file(GLOB_RECURSE RUBY_INST_PATHS "$ENV{SystemDrive}/Ruby*/*/bin/bison.*")
    foreach(SEARCH_PATH ${BITNAMI_PATHS} ${RUBY_INST_PATHS})
        get_filename_component(BIN_PATH "${SEARCH_PATH}" DIRECTORY)
        set(CMAKE_PROGRAM_PATH ${CMAKE_PROGRAM_PATH} "${BIN_PATH}")
    endforeach(SEARCH_PATH)

    # Required programs to compile Ruby, not included by default with MinGW or MSYS.
    find_program(BISON bison)
    if(NOT BISON)
        message(FATAL_ERROR "bison is required to build Ruby")
    endif()
    find_program(SED sed)
    if(NOT SED)
        message(FATAL_ERROR "sed is required to build Ruby")
    endif()
    get_filename_component(BISON_BIN_PATH "${BISON}" DIRECTORY)
    get_filename_component(SED_BIN_PATH "${SED}" DIRECTORY)
endif()

if(MSVC)
    # Windows (Visual Studio) specifics for compiling Ruby.

    # Compile Ruby for 64-bit if we're using 64-bit Visual Studio.
    if(CMAKE_GENERATOR MATCHES "Win64" OR "$ENV{Platform}" STREQUAL "X64")
        set(RUBY_TARGET x64-mswin64)
    else()
        set(RUBY_TARGET i386-mswin32)
    endif()

    # Modification of PATH for Ruby compilation.
    set(NEW_ENV_PATH $ENV{PATH} "${BISON_BIN_PATH}" "${SED_BIN_PATH}")
    set(BUILD_RUBY_SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/build-ruby.bat")
    file(GENERATE OUTPUT "${BUILD_RUBY_SCRIPT}"
            CONTENT "set PATH=%PATH%;${BISON_BIN_PATH};${SED_BIN_PATH}
            nmake /nologo %1"
            )

    # Various options for configuring Ruby.
    set(CONFIGURE_SCRIPT "win32/configure.bat")
    set(CONFIGURE_OPTIONS
            "--prefix=${RUBY_STAGE_DIR}"
            --target=${RUBY_TARGET}
            --disable-install-doc # Don't install documentation.
            --disable-install-rdoc
            --disable-install-capi
            )

    set(RUBY_CONFIGURE "${CONFIGURE_SCRIPT}" ${CONFIGURE_OPTIONS})
    set(RUBY_BUILD "${BUILD_RUBY_SCRIPT}")
    set(RUBY_INSTALL "${BUILD_RUBY_SCRIPT}" install)

    # Figure out some things about which names Ruby will use.
    string(REPLACE . "" VS_VERSION_NODOT "$ENV{VisualStudioVersion}")
    set(STAGED_RUBY_INCLUDE_PATH "${RUBY_STAGE_DIR}/include/ruby-${STAGED_RUBY_VERSION}")
    set(RUBY_PLATFORM_INCLUDE ${RUBY_TARGET}_${VS_VERSION_NODOT})
    set(STAGED_RUBY_INCLUDE_DIR "${STAGED_RUBY_INCLUDE_PATH}" "${STAGED_RUBY_INCLUDE_PATH}/${RUBY_PLATFORM_INCLUDE}"
            CACHE INTERNAL "Path to staged Ruby header files"
            )
    # Since Ruby compiles itself with NMake and Visual Studio, this will always be a LIB.
    set(STAGED_RUBY_SHARED_LIBRARY msvcr${VS_VERSION_NODOT}-ruby${STAGED_RUBY_VERSION_NODOT})
    set(STAGED_RUBY_STATIC_LIBRARY ${STAGED_RUBY_SHARED_LIBRARY}-static)
    set(STAGED_RUBY_LIBRARY "${RUBY_STAGE_DIR}/lib/${STAGED_RUBY_STATIC_LIBRARY}"
            CACHE INTERNAL "Path to static Ruby library"
            )
    set(STAGED_RUBY_SHARED_LIBRARY_FULL "${RUBY_STAGE_DIR}/bin/${CMAKE_SHARED_LIBRARY_PREFIX}${STAGED_RUBY_SHARED_LIBRARY}${CMAKE_SHARED_LIBRARY_SUFFIX}")
    set(STAGED_RUBY_IMP_LIBRARY_FULL    "${RUBY_STAGE_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}${STAGED_RUBY_SHARED_LIBRARY}${CMAKE_STATIC_LIBRARY_SUFFIX}")
    set(STAGED_RUBY_STATIC_LIBRARY_FULL "${RUBY_STAGE_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}${STAGED_RUBY_STATIC_LIBRARY}${CMAKE_STATIC_LIBRARY_SUFFIX}")
    set(STAGED_DYNAMIC_RUBY_LIBRARY
            "${STAGED_RUBY_STATIC_LIBRARY_FULL}" "${STAGED_RUBY_SHARED_LIBRARY_FULL}"
            CACHE INTERNAL "Path to Ruby library needed for dynamic linking"
            )
else()
    # Linux (or MinGW) specifics for compiling Ruby.

    # Autoconf is needed to build Ruby.
    find_program(AUTOCONF_PROGRAM autoconf)
    if(NOT AUTOCONF_PROGRAM)
        message(FATAL_ERROR "autoconf is required to build Ruby")
    endif()

    # Various options for configuring Ruby.
    set(STAGED_RUBY_INCLUDE_PATH "${RUBY_STAGE_DIR}/include/${RUBY_GIT_TAG}")
    set(STAGED_RUBY_ARCH_INCLUDE_PATH "${STAGED_RUBY_INCLUDE_PATH}/arch")
    set(CONFIGURE_OPTIONS
            "--prefix=${RUBY_STAGE_DIR}"
            --disable-install-doc # Don't install documentation.
            --disable-install-rdoc
            --disable-install-capi
            "--with-rubyhdrdir=${STAGED_RUBY_INCLUDE_PATH}" # Install headers to paths CMake knows.
            "--with-rubyarchhdrdir=${STAGED_RUBY_ARCH_INCLUDE_PATH}"
            )

    if(MINGW)
        # autoconf is shipped as a shell script on Windows.
        find_program(SHELL_PROGRAM sh bash)
        # Need to use a *nix shell to build properly.
        if(NOT SHELL_PROGRAM)
            message(FATAL_ERROR "A Linux-based shell is required for autoconf")
        endif()
        get_filename_component(SHELL_PATH "${SHELL_PROGRAM}" DIRECTORY)
        set(BUILD_RUBY_SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/build-ruby-env.bat")
        file(GENERATE OUTPUT "${BUILD_RUBY_SCRIPT}"
                CONTENT "set PATH=${SHELL_PATH};%PATH%;${BISON_BIN_PATH};${SED_BIN_PATH}
                ${SHELL_PROGRAM} %*"
                )
        set(RUBY_CONFIGURE "${BUILD_RUBY_SCRIPT}" "${AUTOCONF_PROGRAM}" COMMAND "${BUILD_RUBY_SCRIPT}" ./configure ${CONFIGURE_OPTIONS})
        set(RUBY_BUILD "${BUILD_RUBY_SCRIPT}" make)
        set(RUBY_INSTALL "${BUILD_RUBY_SCRIPT}" make install)
    else()
        set(RUBY_CONFIGURE "${AUTOCONF_PROGRAM}" COMMAND ./configure ${CONFIGURE_OPTIONS})
        set(RUBY_BUILD "${CMAKE_MAKE_PROGRAM}")
        set(RUBY_INSTALL "${CMAKE_MAKE_PROGRAM}" install)
    endif()

    set(STAGED_RUBY_INCLUDE_DIR "${STAGED_RUBY_INCLUDE_PATH}" "${STAGED_RUBY_ARCH_INCLUDE_PATH}"
            CACHE INTERNAL "Path to staged Ruby header files"
            )
    set(STAGED_RUBY_SHARED_LIBRARY_FULL "${RUBY_STAGE_DIR}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}ruby${CMAKE_SHARED_LIBRARY_SUFFIX}")
    set(STAGED_RUBY_STATIC_LIBRARY_FULL "${RUBY_STAGE_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}ruby-static${CMAKE_STATIC_LIBRARY_SUFFIX}")
    set(STAGED_RUBY_LIBRARY "${STAGED_RUBY_STATIC_LIBRARY_FULL}"
            CACHE INTERNAL "Path to static Ruby library"
            )
    set(STAGED_DYNAMIC_RUBY_LIBRARY "${STAGED_RUBY_SHARED_LIBRARY_FULL}"
            CACHE INTERNAL "Path to shared Ruby library"
            )
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

# Expose staged Ruby libraries.
add_library(ruby-static STATIC IMPORTED GLOBAL)
add_dependencies(ruby-static ruby)
set_property(TARGET ruby-static PROPERTY IMPORTED_LOCATION "${STAGED_RUBY_LIBRARY}")
add_library(ruby-dynamic SHARED IMPORTED GLOBAL)
add_dependencies(ruby-dynamic ruby)
set_property(TARGET ruby-dynamic PROPERTY IMPORTED_LOCATION "${STAGED_RUBY_SHARED_LIBRARY_FULL}")
if(STAGED_RUBY_IMP_LIBRARY_FULL)
    set_property(TARGET ruby-dynamic PROPERTY IMPORTED_IMPLIB "${STAGED_RUBY_IMP_LIBRARY_FULL}")
endif()

# Make staged Ruby available for other components.
if(NOT SHARED_RUBY_BINDING)
    set(RUBY_INCLUDE_DIRS ${STAGED_RUBY_INCLUDE_DIR} CACHE INTERNAL "Paths to Ruby include directories")
    set(RUBY_LIBRARY ${STAGED_RUBY_LIBRARY} CACHE INTERNAL "Ruby libraries to link against")
endif()
