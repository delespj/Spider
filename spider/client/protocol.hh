#ifndef PROTOCOL_HH
#define PROTOCOL_HH

#include "message.hh"

class	Protocol {
public:
  Protocol();
  ~Protocol();

  std::string	buildMsg(Type msgType, char* msg);
  std::string	buildMsg(Type msgType, EventState keyState, int key);
  std::string	buildMsg(Type msgType, EventState clickState, EventClick clickEvent, int pos[2]);
};

#endif
