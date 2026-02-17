find_package(asio CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

add_library(
  client_session 
  src/chat.cpp
  src/on_read.cpp 
)

target_include_directories(client_session PUBLIC include)


target_link_libraries(client_session 
    PRIVATE 
        asio::asio
        Boost::boost
        Boost::system
)

