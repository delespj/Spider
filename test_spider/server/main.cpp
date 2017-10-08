#include <cstdlib>

#include "network.hh"

int	main(int ac, char** av)
{
  if (ac != 2) {
    std::cout << "Usage : ./server [PORT]" << std::endl;
    return (-1);
  }
  try {
    boost::asio::io_service io_service;
    Network network(io_service, atoi(av[1]));
    io_service.run();
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
