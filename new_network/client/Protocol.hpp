#ifndef PROTOCOL_HPP_
#define PROTOCOL_HPP_

#include <string>

#include "Event.hpp"

enum e_MessageType {
  EVENT,
  GENERAL
};

typedef struct s_header {
  int	id;
  int	offset;
  e_MessageType	messageType;
} t_header;

class Protocol {
 private:
  std::string	message;
  t_header	header;

 public:
  Protocol();
  ~Protocol();

  void	BuildHeader(int id);
  void	BuildMessage(); // General msg
  void	BuildMessage(t_MouseData mouseData, e_MouseState mouseState); // Mouse msg
  void	BuildMessage(t_KeyboardData keyboardData); // Keyboard msg
};

#endif
