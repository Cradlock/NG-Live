#pragma once 

#include <boost/asio/io_context.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/beast/core/flat_buffer.hpp>
#include <boost/beast/core/tcp_stream.hpp>
#include <boost/beast/websocket/stream.hpp>
#include <cstddef>
#include <memory>
#include <string>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/strand.hpp>
#include <string_view>



class ChatSession : public std::enable_shared_from_this<ChatSession>{
protected:
  boost::asio::ip::tcp::resolver resolver_;
  boost::beast::websocket::stream<boost::beast::tcp_stream> ws_;
  boost::asio::steady_timer retry_timer_;
  boost::beast::flat_buffer buffer_;

  std::string host_,port_,path_;
  
  int retry_time; 
  
public:
  explicit ChatSession(boost::asio::io_context& ioc,int r_time);
  
  // инициация
  void run(std::string,std::string,std::string);
  
  // Запуск основных функци 
  void start();
  
  // Резолвер
  void on_resolve(
      boost::beast::error_code ec,
      boost::asio::ip::tcp::resolver::results_type res_type 
  );


  // Базовое соединение tcp 
  void connect(
    boost::beast::error_code ec,
    boost::asio::ip::tcp::resolver::endpoint_type ep 
  );  

  // handshake 
  void handshake(
    boost::beast::error_code ec 
  );  


  // Ждем ответа 
  void do_read();
  
  // Если есть ответ от сервера
  void on_read(
    boost::beast::error_code ec,
    std::size_t bytes_t_size
  );

  // Если ошибка
  void on_error(boost::beast::error_code ec,std::string_view where);
  
};
