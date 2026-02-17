#include "chat.h"


#include <boost/asio/connect.hpp>
#include <boost/asio/error.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core/bind_handler.hpp>
#include <boost/beast/core/error.hpp>
#include <boost/beast/core/stream_traits.hpp>
#include <cstddef>
#include <iostream>
#include <string_view>



namespace beast = boost::beast;
using tcp = boost::asio::ip::tcp;





void ChatSession::on_read(
  beast::error_code ec,
  std::size_t bytes_transferred
){
  if (ec) return on_error(ec, "read");

  std::cout << "Msg: " << beast::make_printable(buffer_.data()) << std::endl;
  buffer_.consume(bytes_transferred);

  do_read();
}


