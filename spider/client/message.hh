#ifndef MESSAGE_HH
# define MESSAGE_HH

#include <string>

enum	Type
  {
    Gen,
    MLog,
    KLog
  };

enum    EventState
  {
    Pressed,
    Released
  };

enum	EventClick
  {
    Right,
    Left
  };

struct	MouseEvent
{
  Type	msgType;
  EventState	clickState;
  EventClick	clickEvent;
  int	posX;
  int	posY;
};

struct	KeyboardEvent
{
  Type	msgType;
  EventState	keyState;
  int	key;
};

struct	General
{
  Type	msgType;
  const char*	msg;
};

#endif
