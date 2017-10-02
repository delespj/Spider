#include <sstream>

#include "Protocol.hpp"

Protocol::Protocol() {
}

Protocol::~Protocol() {
}

void	Protocol::BuildHeader(int id) {
  this->header.id = id;
  this->header.offset = this->message.size();
}

void    Protocol::BuildMessage() {
  this->message.clear();

  // add TimeStamp
  this->header.messageType = GENERAL;
  this->message = "Status";
}

void	Protocol::BuildMessage(t_MouseData mouseData, e_MouseState mouseState) {
  this->message.clear();

  // add TimeStamp
  this->header.messageType = EVENT;
  this->message = "MOUSE:";
  if (mouseState == COORD)
    this->message += "COORD:";
  else {
      if (mouseData.mouseButton == RIGHT)
	this->message += "RIGHT:";
      else
	this->message += "LEFT:";
      if (mouseData.keyState == UP)
	this->message += "UP:";
      else
	this->message += "DOWN:";
  }
  std::stringstream tmp;
  tmp << mouseData.coord[0];
  this->message += tmp.str() + ":";
  tmp << mouseData.coord[1];
  this->message += tmp.str() + "\n";
}

void	Protocol::BuildMessage(t_KeyboardData keyboardData) {
  this->message.clear();

  // add TimeStamp
  this->header.messageType = EVENT;
  this->message = "Keyboard:";
  if (keyboardData.keyState == UP)
    this->message += "UP:";
  else
    this->message += "DOWN:";
  this->message += keyboardData.key + "\n";
}
