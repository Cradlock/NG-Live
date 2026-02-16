#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/strand.hpp>
#include <iostream>
#include <memory>
#include <string>

#define HOST "app.localhost"
#define PORT "8070"
#define PATH "/pc/chat"

using std::cout;
using std::endl;

// Подключение пространств имен
namespace asio = boost::asio;
namespace beast = boost::beast;
namespace websocket = beast::websocket;

using tcp = asio::ip::tcp;


int main() {
  
  asio::io_context ioc;

  
  // Превращаем имя в IP адрес (резолвим)
  tcp::resolver resolver(ioc);
  auto const results = resolver.resolve(HOST,PORT);
  
  // Создаем websocket поток (умный поток для работы с обычным сокетом) 
  websocket::stream<tcp::socket> ws(ioc);
  
  // Подключаем базовый tcp сокет для первоначальных функций
  asio::connect(beast::get_lowest_layer(ws),results);
  
  // Закрытие сервера 
  ws.close(websocket::close_code::normal);

  ioc.run();
  
  return 0;
}
