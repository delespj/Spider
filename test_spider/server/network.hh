#ifndef NETWORK_HH_
# define NETWORK_HH_

#include "client.hh"

class   Network
{
private:
  boost::asio::ip::tcp::acceptor	acceptor;

public:
  Network(boost::asio::io_service& io_service, int port);
  ~Network();
  void	accept();
  void	handle(Client::pointer new_client, const boost::system::error_code& error);
};

#endif
