#pragma once 


#include <boost/asio/io_context.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/core/error.hpp>
#include <boost/beast/core/flat_buffer.hpp>
#include <boost/beast/core/tcp_stream.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/strand.hpp>
#include <boost/beast/websocket/stream.hpp>
#include <cstddef>
#include <iostream>
#include <memory>
#include <string>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace asio = boost::asio;
using tcp = asio::ip::tcp;
using std::string;

class ClientSession : public boost::enable_shared_from_this<ClientSession> {
protected:
  websocket::stream<beast::tcp_stream> ws;
  beast::flat_buffer buffer;

public: 
  // Запрещаем неявное проебразование типов
  explicit ClientSession(asio::io_context& ioc);

  void run(string& host,string& port,string& endpoint);

private:
  void on_connect(beast::error_code ec,tcp::endpoint ep, string host,string path);

  void on_handshake(beast::error_code ec);

  void do_read();

  void on_read(beast::error_code ec, std::size_t bytes_transferred);

};
