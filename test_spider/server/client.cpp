#include "client.hh"

Client::Client(boost::asio::io_service& io_service):
  sock(io_service)
{
  this->record = new Record(this->id);
}

Client::~Client()
{
  close();
}

void	Client::close()
{
  this->sock.close();
}

void	Client::send_msg(std::string msg)
{
  this->sock.send(boost::asio::buffer(msg));
}

void	Client::setId(std::string id)
{
  this->id = id;
}

std::string	Client::getId()
{
  return (this->id);
}

void	Client::read_msg()
{
  boost::asio::async_read(this->sock, boost::asio::buffer(buffer), boost::bind(&Client::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void	Client::handle_read(const boost::system::error_code& error, size_t number_bytes_read)
{
  this->record->setId(this->id);
  if (!error)
    {
      std::string to_string(buffer.begin(), buffer.end());
      std::string msg(to_string, 0, number_bytes_read); // string contenant le message recu
      std::cout << "message : " << msg << std::endl;
      this->record->WriteMessage(msg); // record the message in the file corresponding
      boost::asio::async_read(this->sock, boost::asio::buffer(buffer), boost::bind(&Client::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    }
  else
    close();
}

boost::asio::ip::tcp::socket&	Client::get_socket()
{
  return (this->sock);
}

typedef boost::shared_ptr<Client> pointer;

pointer	Client::create(boost::asio::io_service& ios)
{
  return (pointer(new Client(ios)));
}
