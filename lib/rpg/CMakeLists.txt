cmake_minimum_required(VERSION 3.0)

file(GLOB_RECURSE RB_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" *.rb)

foreach(RB_FILE ${RB_FILES})
    ADD_RUBY_SCRIPT(${RB_FILE} SYMBOL)
    set(SRC_FILES ${SRC_FILES} ${RB_FILE}.c)
    set(EXTERNS "${EXTERNS}extern const char ${SYMBOL}[];\n")
    set(SYMBOLS "${SYMBOLS}    ${SYMBOL},\n")
endforeach(RB_FILE)

configure_file(symbols.h.in symbols.h)
add_library(rgss_rpg STATIC ${SRC_FILES})
