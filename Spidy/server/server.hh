#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>

#include "session.hh"

class server
{
public:
  server(boost::asio::io_service& io_service, short port);

private:
  void do_accept();

  boost::asio::ip::tcp::acceptor acceptor_;
  boost::asio::ip::tcp::socket socket_;
};
