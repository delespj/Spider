#ifndef SESSION_HH_
#define SESSION_HH_

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>

#include "Record.hh"

class session : public std::enable_shared_from_this<session>
{
public:
  session(boost::asio::ip::tcp::socket socket);

  void	start();

private:
  void	do_read();
  void	do_write(std::size_t length);
 
  boost::asio::ip::tcp::socket	socket_;
  enum { max_length = 1024 };
  char	data_[max_length];
  Record	*record;
  std::string	id;
};

#endif
