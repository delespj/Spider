#include "Record.hpp"

Record::Record(const std::string &id)
{
  _id = id;
  _file.open(id.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
}

Record::~Record()
{
  _file.close();
}

void		Record::WriteMessage(const std::string &message)
{
  _file.write(message.c_str(), message.size());
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
