#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>

// Difference between simple coord message and click event
enum e_MouseState {
  COORD,
  CLICK
};

enum e_MouseButton {
  RIGHT,
  LEFT
};

enum e_KeyState {
  UP,
  DOWN
};

typedef struct s_KeyboardData {
  e_KeyState	keyState;
  std::string	key;
} t_KeyboardData;

typedef struct s_MouseData {
  e_MouseButton	mouseButton;
  e_KeyState	keyState;
  int	coord[2]; // [0] = y, [1] = x
} t_MouseData;

class IEvent
{
public:
  virtual void CheckEvent() = 0;
  virtual void KeyState() = 0;
  virtual void SetKey() = 0;
};

class	Event : public IEvent
{
public:
  virtual void CheckEvent();
  virtual void KeyState();
  virtual void SetKey();
};

class MouseEvent : public Event
{
private:
  t_MouseData	mouseData;

public:
  MouseEvent();
  ~MouseEvent();

  void	CheckMouse();
  void	SetCoord();
};

class KeyboardEvent : public Event
{
private:
  t_KeyboardData	keyboardData;
  
public:
  KeyboardEvent();
  ~KeyboardEvent();

  void	SetKeyState();
};

#endif
