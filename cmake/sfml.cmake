cmake_minimum_required(VERSION 3.0)
include(ExternalProject)

add_definitions(-DUNICODE)

# Varous SFML options.
set(STATIC_SFML_LIB true) # Static link SFML.
set(SFML_VERSION 2.2) # Version/tag of SFML.
set(SFML_REPO https://github.com/SFML/SFML.git) # URL to the SFML repository.

set(SFML_EXT_DIR     "${CMAKE_CURRENT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/sfml") # Directory to checkout SFML to.
set(SFML_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/sfml") # Directory to install SFML in.
set(SFML_CMAKE_ARGS  "-DCMAKE_INSTALL_PREFIX=${SFML_INSTALL_DIR}") # Tell SFML's CMake where to install.

if(STATIC_SFML_LIB)
    # Compile SFML for static linking.
    set(SFML_CMAKE_ARGS ${SFML_CMAKE_ARGS} "-DBUILD_SHARED_LIBS=false")
    add_definitions(-DSFML_STATIC -DGLEW_STATIC)
endif()

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    if(UNIX)
        # Make symbols in SFML libraries position independent, required on Linux.
        set(SFML_CMAKE_ARGS ${SFML_CMAKE_ARGS} "-DCMAKE_C_FLAGS=-fPIC" "-DCMAKE_CXX_FLAGS=-fPIC")
        set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -fPIC")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    endif()
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

# Utility function for linking against SFML properly.
function(LINK_SFML TARGET)
    add_dependencies(${TARGET} sfml)

    # Include SFML static libraries in this library.
    if(STATIC_SFML_LIB)
        set(PREFIX ${CMAKE_STATIC_LIBRARY_PREFIX})
        set(SUFFIX ${CMAKE_STATIC_LIBRARY_SUFFIX})
        # SFML was compiled statically, which produces a different "-s" library.
        set(MODULE_SUFFIX -s)
    else()
        set(PREFIX ${CMAKE_SHARED_LIBRARY_PREFIX})
        set(SUFFIX ${CMAKE_SHARED_LIBRARY_SUFFIX})
    endif()

    foreach(MODULE IN ITEMS audio graphics network window system)
        set(MODULE_FULL_PATH "${SFML_LIB_DIR}/${PREFIX}sfml-${MODULE}${MODULE_SUFFIX}${SUFFIX}")
        target_link_libraries(${TARGET} "${MODULE_FULL_PATH}")
    endforeach()

    # Link against SFML dependencies.
    if(WIN32)
        foreach(LIB_NAME IN ITEMS openal32 sndfile glew jpeg freetype)
            target_link_libraries(${TARGET} "${SFML_LIB_DIR}/${PREFIX}${LIB_NAME}${SUFFIX}")
        endforeach()
        target_link_libraries(${TARGET} opengl32 ws2_32 gdi32 winmm)
    else()
        target_link_libraries(${TARGET} openal sndfile jpeg freetype GLEW GLU GL Xrandr udev)
    endif()
endfunction()
