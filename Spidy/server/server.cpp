#include "server.hh"

server::server(boost::asio::io_service& io_service, short port)
  : acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
    socket_(io_service) {
  do_accept();
}

void	server::do_accept()
{
  acceptor_.async_accept(socket_,
			 [this](boost::system::error_code ec) {
			   if (!ec) {
			       std::cout << "client received\n";
			       std::make_shared<session>(std::move(socket_))->start();
			     }

			   do_accept();
			 });
}
