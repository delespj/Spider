#include "connection.hh"

Connection::Connection(boost::asio::io_service& io_service):
  sock(io_service) {
}

Connection::~Connection() {
}

void	Connection::send_msg(std::string msg) {
  this->sock.send(boost::asio::buffer(msg));
}

void	Connection::read() {
  boost::asio::async_read(this->sock, boost::asio::buffer(buf), boost::bind(&Connection::handle_read, shared_from_this(), boost::asio::placeholders::error));
}

void	Connection::handle_read(const boost::system::error_code& code) {
  std::cout << "message: ";
  std::cout.write(&this->buf[0], 15);
  std::cout << std::endl;
  read();
}

boost::asio::ip::tcp::socket&	Connection::get_socket() {
  return (sock);
}

typedef boost::shared_ptr<Connection> pointer;

pointer	Connection::create(boost::asio::io_service& ios) {
  return (pointer(new Connection(ios)));
}
