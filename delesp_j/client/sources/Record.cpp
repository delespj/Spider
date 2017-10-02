//
// Record.cpp for spider in /home/philip_i
// 
// Made by PHILIPPE Gregory
// Login   <philip_i@epitech.net>
// 
// Started on  Mon Oct  2 20:55:35 2017 PHILIPPE Gregory
// Last update Mon Oct  2 20:55:38 2017 PHILIPPE Gregory
//

#include "Record.hpp"

Record::Record(const std::string &id)
{
  _id = id;
  _file.open(id, std::fstream::in | std::fstream::out | std::fstream::app);
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
  _file.open(_id, std::fstream::in | std::fstream::out | std::fstream::trunc);
  _file.write(tmp.c_str(), tmp.size());
}
