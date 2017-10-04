#include "server.hh"

Server::Server(boost::asio::io_service& io_service, int port):
  acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
  accept();
}

Server::~Server()
{
}

void	Server::accept()
{
  Connection::pointer new_connection = Connection::create(this->acceptor.get_io_service());
  acceptor.async_accept(new_connection->get_socket(), boost::bind(&Server::handle, this, new_connection, boost::asio::placeholders::error)); 
}

void	Server::handle(Connection::pointer new_connection, const boost::system::error_code& error)
  {
    if (!error)
      {
	std::cout << "Reçu un client!" << std::endl;
	new_connection->read_msg();
	new_connection->send_msg("boost overated\n");
	accept();
      }
  }
