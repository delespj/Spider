#include <sstream>
#include <string.h>
#include <cstdlib>

#include "protocol.hh"

Protocol::Protocol() {
}

Protocol::~Protocol() {
}

std::string	Protocol::unbuildMsg(char* data) {
  General	general;
  KeyboardEvent	kbe;
  MouseEvent	me;

  if (data[0] == Gen)
    return (NULL); //return (this->unbuildMsg(Gen, data));
  else if (data[0] == KLog)
    return (this->unbuildMsg(kbe, data));
  else
    return (this->unbuildMsg(me, data));
  return (NULL);
}

std::string	Protocol::unbuildMsg(Type type, char* data) {
  std::string	msg;

  msg = data;
  return (msg);
}

std::string	Protocol::unbuildMsg(KeyboardEvent kbe, char* data) {
  memcpy(&kbe, data, sizeof(struct KeyboardEvent));
  std::string	msg;

  msg = std::to_string(kbe.msgType) + " ";
  msg += std::to_string(kbe.keyState) + " " + std::to_string(kbe.key);
  return (msg);
}

std::string	Protocol::unbuildMsg(MouseEvent me, char* data) {
  memcpy(&me, data, sizeof(struct MouseEvent));
  std::string	msg;

  msg = std::to_string(me.msgType) + " " + std::to_string(me.clickState) + " ";
  msg += std::to_string(me.clickEvent) + " " + std::to_string(me.posX);
  msg += " " + std::to_string(me.posY);
  return (msg);
}
