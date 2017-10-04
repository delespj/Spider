#ifndef CONNECTION_HH_
# define CONNECTION_HH_

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

class Connection : public boost::enable_shared_from_this<Connection>
{
private:
  boost::asio::ip::tcp::socket	sock;
  boost::array<char, 1>		buff;
  std::string			msg_receive;

public:

  typedef boost::shared_ptr<Connection> pointer;
  static pointer create(boost::asio::io_service& ios);
  
  Connection(boost::asio::io_service& io_service);
  ~Connection();
  void	read();
  void	send_msg(std::string msg);
  void	handle_write(const boost::system::error_code& error);
  void	handle_read(const boost::system::error_code& error, size_t number_bytes_read);
  boost::asio::ip::tcp::socket	&get_socket();
};

#endif
