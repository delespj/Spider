#include "client.hh"

client::client(boost::asio::io_service& io_service, boost::asio::ip::tcp::endpoint& endpoint):
  io(io_service)
{
  connect(endpoint);
}

client::~client()
{
}

void	client::connect(boost::asio::ip::tcp::endpoint& endpoint)
{
  Connection::pointer new_connection = Connection::create(this->io);
  boost::asio::ip::tcp::socket& socket = new_connection->get_socket();
  socket.async_connect(endpoint, boost::bind(&client::handle_connect, this, new_connection, boost::asio::placeholders::error));
}

void	client::handle_connect(Connection::pointer new_connection, const boost::system::error_code& error)
{
  if (!error)
    {
      new_connection->read();
      new_connection->send_msg("Status\n");
      new_connection->send_msg("boost overrated\n");;;
    }
}
