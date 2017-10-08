#ifndef RECORD_HPP_
#define RECORD_HPP_

#include <iostream>
#include <fstream>
#include <string>

class			Record
{
  std::string		_id;
  std::fstream		_file;
public :
  Record(const std::string &id);
  ~Record();

  void			WriteMessage(const std::string &message);
  void		        PopMessage();
};

#endif
