//
// Record.hpp for spider in /home/philip_i
// 
// Made by PHILIPPE Gregory
// Login   <philip_i@epitech.net>
// 
// Started on  Mon Oct  2 20:55:56 2017 PHILIPPE Gregory
// Last update Mon Oct  2 20:55:58 2017 PHILIPPE Gregory
//

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

#endif // RECORD_HPP_
