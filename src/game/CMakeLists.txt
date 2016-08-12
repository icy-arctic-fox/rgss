cmake_minimum_required(VERSION 3.0)

# We used the staged (ExternalProject) copy of Ruby here.
# The game should have Ruby statically linked (included) in the resulting executable.
include_directories(${STAGED_RUBY_INCLUDE_DIR})

ADD_RUBY_SCRIPT(bootstrap.rb)
ADD_RUBY_SCRIPT(inifile.rb)

set(SRC_FILES
        main.cpp
        bootstrap.rb.c
        inifile.rb.c
        )

include_directories("${CMAKE_CURRENT_BINARY_DIR}/../../lib/rpg") # Directory containing symbols.h.
include_directories(../../include/binding)

add_executable(Game ${SRC_FILES})
target_link_libraries(Game rgss rgss_rpg ruby-static)

if(UNIX)
    target_link_libraries(Game pthread gmp dl crypt)
endif()

# Look for shared libraries in current directory.
set_target_properties(Game PROPERTIES INSTALL_RPATH .)
install(TARGETS Game DESTINATION .)

# Install the Ruby library along-side the game.
file(GLOB RUBY_LIBS "${RUBY_LIBRARY}.*")
install(FILES ${RUBY_LIBS} DESTINATION .)
