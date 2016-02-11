cmake_minimum_required(VERSION 3.0)

add_executable(rb2c rb2c.c)

function(ADD_RUBY_SCRIPT RB_FILE)
    string(REGEX REPLACE "[^A-Za-z0-9_]" "_" SYMBOL "${RB_FILE}")
    set(C_FILE "${RB_FILE}.c")
    get_filename_component(RB_FILE_PATH "${RB_FILE}" ABSOLUTE)
    get_filename_component(C_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/${C_FILE}" DIRECTORY)
    add_custom_command(OUTPUT "${C_FILE}"
            COMMAND "${CMAKE_COMMAND}" -E make_directory "${C_OUTPUT_DIR}"
            COMMAND "$<TARGET_FILE:rb2c>" "${RB_FILE_PATH}" "${C_FILE}" ${SYMBOL}
            DEPENDS rb2c "${RB_FILE}")
endfunction()
