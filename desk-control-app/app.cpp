#include <iostream>
#include <memory>
#include <string>

#include "chat.h"

#define HOST "app.localhost"
#define PORT "8070"
#define PATH "/pc/chat"

int main() {
  boost::asio::io_context ioc;

  auto main = std::make_shared<ChatSession>(ioc,5);
  
  main->run(HOST,PORT,PATH);

  ioc.run();
  return 0;
}
