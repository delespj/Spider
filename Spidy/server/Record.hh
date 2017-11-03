#ifndef RECORD_HPP_
#define RECORD_HPP_

#include <iostream>
#include <fstream>
#include <string>

class			Record
{
  std::string		_id;
  std::fstream		_file;
  std::ofstream		out;
public :
  Record(const std::string &id);
  ~Record();

  void			WriteMessage(const char *message, std::size_t length);
  void		        PopMessage();
};

#endif
