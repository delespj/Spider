#include "Record.hh"

Record::Record(const std::string &id)
{
  _id = "recorded_sources/" + id;
  this->_file.open(this->_id.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
}

Record::~Record()
{
  _file.close();
}

void		Record::WriteMessage(const char* message, std::size_t length)
{
  this->_file << message << std::endl;
}

void		Record::PopMessage()
{
  size_t	l;
  char		*buffer;
  std::string	tmp;
  
  _file.seekg(0, _file.end);
  l = _file.tellg();
  buffer = new char[l];
  _file.seekg(0, _file.beg);
  _file.read(buffer, l);
  _file.close();
  tmp = buffer;
  delete buffer;
  tmp = tmp.substr(tmp.find("\n") + 1);
  _file.open(_id.c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc);
  _file.write(tmp.c_str(), tmp.size());
}
