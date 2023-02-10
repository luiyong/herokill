execute_process(COMMAND date "-u" "+%F %H:%M" OUTPUT_VARIABLE build_time OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND echo "const char* herokill_server_version =" \"${build_time}\" ";"
          OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/ServerVersion.cc
            )
add_executable(herokill_server main.cpp
        CardPool.cpp
        )
