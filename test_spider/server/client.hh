#ifndef CLIENT_HH_
# define CLIENT_HH_

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "crypt.hh"
#include "Record.hpp"

class Client : public boost::enable_shared_from_this<Client>
{
private:
  std::string	id;
  boost::asio::ip::tcp::socket	sock;
  boost::array<char, 60>		buffer;
  Record*	record;

public:
  Client(boost::asio::io_service& io_service);
  ~Client();
  void	send_msg(std::string msg);
  void	read_msg();
  void	handle_read(const boost::system::error_code& error, size_t number_bytes_read);
  void	close();
  void	setId(std::string id);
  std::string	getId();
  boost::asio::ip::tcp::socket& get_socket();
  
  typedef boost::shared_ptr<Client> pointer;
  static pointer create(boost::asio::io_service& ios);
};

#endif
