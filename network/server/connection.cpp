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
  sock.close();
}

void	Connection::send_msg(std::string msg)
{
  boost::asio::async_write(sock, boost::asio::buffer(msg), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error));
}

void	Connection::read_msg()
{
  boost::asio::async_read(sock, boost::asio::buffer(buffer), boost::asio::transfer_at_least(20), boost::bind(&Connection::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
  //  timer.expires_from_now(boost::posix_time::seconds(5));
  //  timer.async_wait(boost::bind(&Connection::close, shared_from_this()));  //timer
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
      std::cout << msg << std::endl;
      //      std::cout.write(&buffer[0], number_bytes_read) << std::endl;
      read_msg();
    }
  else
    {
      std::cout << error.message() << "\npb in handle_read" << std::endl;
      close();
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
