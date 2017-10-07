#include "connection.hh"

Connection::Connection(boost::asio::io_service& io_service):
  sock(io_service), timer(io_service, boost::posix_time::seconds(5))
{
}

Connection::~Connection()
{
  close();
}

void	Connection::close()
{
  this->sock.close();
}

void	Connection::send_msg(std::string msg)
{
  this->sock.send(boost::asio::buffer(msg));
}

void	Connection::read_msg()
{
  boost::asio::async_read(this->sock, boost::asio::buffer(buffer), boost::bind(&Connection::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void	Connection::handle_write(const boost::system::error_code& error)
{
  if (!error)
    {
      read_msg();
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
      std::string to_string(buffer.begin(), buffer.end());
      std::string msg(to_string, 0, number_bytes_read);
      std::cout.write(&this->buffer[0], 48);
      read_msg();
    }
  else
    {
      close();
    }
}

boost::asio::ip::tcp::socket&	Connection::get_socket()
{
  return (this->sock);
}

typedef boost::shared_ptr<Connection> pointer;

pointer	Connection::create(boost::asio::io_service& ios)
{
  return (pointer(new Connection(ios)));
}
