#include "server.hh"

int	main()
{
  try
    {
      boost::asio::io_service io_service;
      Server server(io_service, 4242);
      io_service.run();
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
}
