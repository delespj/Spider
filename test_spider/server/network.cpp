#include "network.hh"

Network::Network(boost::asio::io_service& io_service, int port):
  acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
  accept();
}

Network::~Network()
{
}

void	Network::accept()
{
  Client::pointer new_client = Client::create(this->acceptor.get_io_service());
  this->acceptor.async_accept(new_client->get_socket(), boost::bind(&Network::handle, this, new_client, boost::asio::placeholders::error));
}

void	Network::handle(Client::pointer new_client, const boost::system::error_code& error)
{
  if (!error)
    {
      std::cout << "New client received" << std::endl;
      std::cout << "IP: " << new_client->get_socket().remote_endpoint().address().to_string() << std::endl;
      new_client->setId(new_client->get_socket().remote_endpoint().address().to_string());
      new_client->read_msg();
      accept();
    }
}
