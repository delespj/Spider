#ifndef CLIENT_HH_
# define CLIENT_HH_

#include "connection.hh"

class	client
{
private:
  boost::asio::io_service &io;
public:
  client(boost::asio::io_service&, boost::asio::ip::tcp::endpoint&);
  ~client();
  void	connect(boost::asio::ip::tcp::endpoint& endpoint);
  void	handle_connect(Connection::pointer new_connection, const boost::system::error_code& error);
};

#endif
