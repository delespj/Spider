#ifndef SERVER_HH_
# define SERVER_HH_

#include "connection.hh"

class	Server
{
private:
  boost::asio::ip::tcp::acceptor	acceptor;

public:
  Server(boost::asio::io_service& io_service, int port);
  ~Server();
  void	accept();
  void	handle(Connection::pointer new_connection, const boost::system::error_code& error);
};

#endif
