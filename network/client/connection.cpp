#include "connection.hh"

Connection::Connection(boost::asio::io_service& io_service):
  sock(io_service)
{
}

Connection::~Connection()
{
}

void	Connection::send_msg(std::string msg)
{
  this->sock.send(boost::asio::buffer(msg));
}

void	Connection::read()
{
  boost::asio::async_read(this->sock, boost::asio::buffer(b1), boost::bind(&Connection::handle_header, shared_from_this(), boost::asio::placeholders::error));
}

void    Connection::handle_write(const boost::system::error_code& error)
{
  if (!error)
    {
      read();
    }
  else
    {
      std::cout << error.message() << std::endl;
    }
}

void	Connection::handle_header(const boost::system::error_code& code)
{
  std::cout << "header: ";
  std::cout.write(&this->b1[0], 10);
  std::cout << std::endl;
  boost::asio::async_read(this->sock, boost::asio::buffer(b2), boost::bind(&Connection::handle_message, shared_from_this(), boost::asio::placeholders::error));
}

void	Connection::handle_message(const boost::system::error_code& code)
{
  std::cout << "message: ";
  std::cout.write(&this->b2[0], 15);
  std::cout << std::endl;
  read();
}

boost::asio::ip::tcp::socket&	Connection::get_socket()
{
  return (sock);
}

typedef boost::shared_ptr<Connection> pointer;

pointer	Connection::create(boost::asio::io_service& ios)
{
  return (pointer(new Connection(ios)));
}
