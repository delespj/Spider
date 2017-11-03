#include <cstdlib>

#include "client.hh"

int	main(int ac, char** av)
{
  if (ac != 3) {
    std::cout << "Usage : ./client [IP] [PORT]" << std::endl;
    return (-1);
  }
  boost::asio::io_service io_service;
  boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(av[1]), atoi(av[2]));
  client client(io_service, endpoint);
  io_service.run();;
  return (0);
}
