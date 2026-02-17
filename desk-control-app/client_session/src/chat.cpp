#include "chat.h"


#include <boost/asio/connect.hpp>
#include <boost/asio/error.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core/bind_handler.hpp>
#include <boost/beast/core/error.hpp>
#include <boost/beast/core/stream_traits.hpp>
#include <chrono>
#include <cstddef>
#include <exception>
#include <iostream>
#include <string>
#include <string_view>



namespace beast = boost::beast;
namespace net = boost::asio;
namespace websocket = beast::websocket;
using tcp = boost::asio::ip::tcp;

ChatSession::ChatSession(net::io_context& ioc,int r_time) : 
  retry_time(r_time),resolver_(ioc),ws_(ioc),retry_timer_(ioc) 
{}


void ChatSession::run(
    std::string host,
    std::string port,
    std::string path
){
  host_ = host;
  port_ = port;
  path_ = path;
  
  this->start();
}


void ChatSession::start(){
  resolver_.async_resolve(host_,port_,
    // автоматически склеиваем обьект и метод on_resolve 
      beast::bind_front_handler(&ChatSession::on_resolve,shared_from_this())
  );

}

void ChatSession::on_resolve(
  beast::error_code ec,
  tcp::resolver::results_type res_type 
){
  if(ec) return on_error(ec, "resolve");
  
  // если сервер не отвечает мы ждем 30 секунд
  beast::get_lowest_layer(ws_).expires_after(std::chrono::seconds(30));

  beast::get_lowest_layer(ws_).async_connect(res_type,
      beast::bind_front_handler(
        &ChatSession::connect, shared_from_this()
      )
  );
}



void ChatSession::connect(
  beast::error_code ec,
  tcp::resolver::endpoint_type ep 
){
  if(ec) return on_error(ec, "connect");
  
  beast::get_lowest_layer(ws_).expires_never();
  
  ws_.set_option(websocket::stream_base::timeout::suggested(beast::role_type::client));
  
  // handshake
  ws_.async_handshake(host_, path_,
        beast::bind_front_handler(
          &ChatSession::handshake, 
          shared_from_this()
        )
  );

}



void ChatSession::handshake(
  beast::error_code ec 
){
  if(ec) return on_error(ec, "handshake");
  
  do_read();
}




void ChatSession::do_read(){
  ws_.async_read(buffer_, 
    beast::bind_front_handler(&ChatSession::on_read, shared_from_this())
  );
}


void ChatSession::on_error(
  beast::error_code ec,
  std::string_view where 
){
  if(ec == net::error::operation_aborted) return;

  std::cerr << "error in:" << where << ':' << ec.message() << std::endl;

  
  beast::get_lowest_layer(ws_).close();
  

  retry_timer_.expires_after(std::chrono::seconds(retry_time));
  retry_timer_.async_wait([self = shared_from_this()] 
    (beast::error_code ec) {
    if(!ec) self->start();
  });

}






