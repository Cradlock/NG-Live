cmake_minimum_required(VERSION 3.15)

project(WsClient)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Включаем CMakeLists в client-session
add_subdirectory(client_session)


add_executable(app app.cpp)



# Подключаем свою мини библиотеку
target_link_libraries(app PRIVATE client_session)

# Подключение nvim
if(CMAKE_EXPORT_COMPILE_COMMANDS)
set(SOURCE_FILE "${CMAKE_BINARY_DIR}/compile_commands.json")
set(DESTINATION_FILE "${CMAKE_SOURCE_DIR}/compile_commands.json")

if(NOT EXISTS ${DESTINATION_FILE})
    execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${SOURCE_FILE} ${DESTINATION_FILE})
endif()
endif()
