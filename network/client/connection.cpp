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
  //  boost::asio::async_write(this->sock, boost::asio::buffer(msg), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error));
  this->sock.send(boost::asio::buffer(msg));
}

void	Connection::read()
{
  boost::asio::async_read(this->sock, boost::asio::buffer(buff), boost::bind(&Connection::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
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

void	Connection::handle_read(const boost::system::error_code& error, size_t number_bytes_read)
{
  if (!error)
    {
      std::string to_string(buff.begin(), buff.end());
      std::string msg(to_string, 0, number_bytes_read);
      if (msg != "\n")
	this->msg_receive += msg;
      else
	{
	  std::cout << this->msg_receive << std::endl;
	  this->msg_receive.clear();
	}
      read();
    }
  else
    {
      std::cout << error.message();
    }
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
