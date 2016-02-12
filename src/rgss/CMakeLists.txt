cmake_minimum_required(VERSION 3.0)
include(ExternalProject)

add_definitions(-DUNICODE)

# SFML is used for the underlying implementation.

set(STATIC_SFML_LIB true) # Static link SFML.
set(SFML_VERSION 2.2) # Version/tag of SFML.
set(SFML_REPO https://github.com/SFML/SFML.git) # URL to the SFML repository.

set(SFML_EXT_DIR "${CMAKE_CURRENT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/sfml") # Directory to checkout SFML to.
set(SFML_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/sfml") # Directory to install SFML in.
set(SFML_CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${SFML_INSTALL_DIR}") # Tell SFML's CMake where to install.

if(STATIC_SFML_LIB)
    # Compile SFML for static linking.
    set(SFML_CMAKE_ARGS ${SFML_CMAKE_ARGS} "-DBUILD_SHARED_LIBS=false")
    add_definitions(-DSFML_STATIC -DGLEW_STATIC)
endif()

if(UNIX)
    # Make symbols in SFML libraries position independent, required on Linux.
    set(SFML_CMAKE_ARGS ${SFML_CMAKE_ARGS} "-DCMAKE_C_FLAGS=-fPIC" "-DCMAKE_CXX_FLAGS=-fPIC")
endif()

# Include SFML as an external project.
ExternalProject_Add(sfml
        PREFIX "${SFML_EXT_DIR}"
        GIT_REPOSITORY ${SFML_REPO}
        GIT_TAG ${SFML_VERSION}
        CMAKE_ARGS ${SFML_CMAKE_ARGS}
        )

# Paths to installed SFML components.
set(SFML_INCLUDE_DIR "${SFML_INSTALL_DIR}/include")
set(SFML_LIB_DIR     "${SFML_INSTALL_DIR}/lib")
include_directories("${SFML_INCLUDE_DIR}")

# The following is for the RGSS implementation library.

include_directories(../../include/rgss)

set(SRC_FILES
        Color.cpp
        )

add_library(rgss_impl STATIC ${SRC_FILES})
add_dependencies(rgss_impl sfml)
