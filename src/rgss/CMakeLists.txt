cmake_minimum_required(VERSION 3.0)

include_directories(../../include/rgss)

set(SRC_FILES
        Color.cpp
        Rect.cpp
        Tone.cpp
        )

add_library(rgss_impl STATIC ${SRC_FILES})
add_dependencies(rgss_impl sfml)

# Include SFML static libraries in this library.
set(MODULE_PREFIX lib)
set(MODULE_SUFFIX .a)
if(STATIC_SFML_LIB)
    # SFML was compiled statically, which produces a different "-s" library.
    set(MODULE_SUFFIX "-s${MODULE_SUFFIX}")
endif()

foreach(MODULE IN ITEMS audio graphics network window system)
    set(MODULE_FULL_PATH "${SFML_LIB_DIR}/${MODULE_PREFIX}sfml-${MODULE}${MODULE_SUFFIX}")
    target_link_libraries(rgss_impl "${MODULE_FULL_PATH}")
endforeach()

# Link against SFML dependencies.
if(WIN32)
    foreach(LIB_NAME IN ITEMS openal32 sndfile glew jpeg freetype)
        target_link_libraries(rgss_impl "${SFML_LIB_DIR}/lib${LIB_NAME}.a")
    endforeach()
    target_link_libraries(rgss_impl opengl32 ws2_32 gdi32 winmm)
else()
    target_link_libraries(rgss_impl openal sndfile jpeg freetype GLEW GLU GL Xrandr udev)
endif()
