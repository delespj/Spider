#include "client.hh"

int	main()
{
  try
    {
      boost::asio::io_service io_service;
      boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 4242);
      client client(io_service, endpoint);
      io_service.run();
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
}
