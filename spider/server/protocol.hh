#ifndef PROTOCOL_HH
#define PROTOCOL_HH

#include "message.hh"

class	Protocol {
public:
  Protocol();
  ~Protocol();

  std::string	unbuildMsg(char* data);
  std::string	unbuildMsg(Type type, char* data);
  std::string	unbuildMsg(KeyboardEvent kbe, char* data);
  std::string	unbuildMsg(MouseEvent me, char* data);
};

#endif
