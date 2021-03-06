#include "session.hh"
#include "protocol.hh"

session::session(boost::asio::ip::tcp::socket socket)
  : socket_(std::move(socket)) {
  this->id = this->socket_.remote_endpoint().address().to_string();
}

void	session::start() {
  this->record = new Record(std::string(this->id));
  do_read();
}

void	session::do_read() {
  auto self(shared_from_this());
  socket_.async_read_some(boost::asio::buffer(data_, max_length),
			  [this, self](boost::system::error_code ec, std::size_t length) {
			    if (!ec) {
			      Protocol	protocol;
			      std::string message = protocol.unbuildMsg(data_);
			      std::cout << "message : " << message << std::endl;
			      this->record->WriteMessage(message.c_str(), length);
			      memset(this->data_, 0, max_length);
			      do_read();
			    }
			  });
}

void	session::do_write(std::size_t length) {
  auto self(shared_from_this());
  boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
			   [this, self](boost::system::error_code ec, std::size_t) {
			     if (!ec) {
				 do_read();
			       }
			   });
}
