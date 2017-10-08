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

  void			WriteMessage(const std::string &message);
  void		        PopMessage();
  void	setId(std::string id);
};

#endif
