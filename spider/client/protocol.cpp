#include <string.h>

#include "protocol.hh"

Protocol::Protocol() {
}

Protocol::~Protocol() {
}

std::string	Protocol::buildMsg(Type msgType, char* msg) {
  std::string	finalMsg;

  finalMsg = std::to_string(msgType) + msg;
  return (finalMsg);
}

std::string	Protocol::buildMsg(Type msgType, EventState keyState, int key) {
  KeyboardEvent	keyboardEvent;

  keyboardEvent.msgType = msgType;
  keyboardEvent.keyState = keyState;
  keyboardEvent.key = key;

  char	buf[sizeof(struct KeyboardEvent)];

  memcpy(buf, &keyboardEvent, sizeof(struct KeyboardEvent));
  std::string	finalMsg(buf);

  return (finalMsg);
}

std::string	Protocol::buildMsg(Type msgType, EventState clickState, EventClick clickEvent, int pos[2]) {
  MouseEvent	mouseEvent;

  mouseEvent.msgType = msgType;
  mouseEvent.clickState = clickState;
  mouseEvent.clickEvent = clickEvent;
  mouseEvent.posX = pos[0];
  mouseEvent.posY = pos[1];

  char	buf[sizeof(MouseEvent)];

  memcpy(buf, &mouseEvent, sizeof(struct MouseEvent));
  std::string	finalMsg(buf);

  return (finalMsg);
}
