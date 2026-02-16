cmake_minimum_required(VERSION 3.15)

project(WsClient)

set(CMAKE_CXX_STANDART 17)

# 1. Находим Asio
find_package(asio CONFIG REQUIRED)

# 2. Находим Beast (через пакет Boost)
find_package(Boost REQUIRED COMPONENTS system) 
# Примечание: Beast — это header-only, но ему часто нужен boost_system

add_executable(app app.cpp)

# 3. Линкуем
# Нам нужно явно указать путь к заголовкам Boost, если мы используем Beast
target_link_libraries(app PRIVATE asio::asio)
target_include_directories(app PRIVATE ${Boost_INCLUDE_DIRS})

# 4. Подключаем кастомные файлы


