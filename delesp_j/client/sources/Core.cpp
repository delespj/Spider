#include "Core.hpp"

Core::Core() {
  this->events.push_back(new MouseEvent());
  this->events.push_back(new KeyboardEvent());
  this->protocol = new Protocol();
  this->network = new Network();
  this->connect = false;
}

Core::~Core() {
  this->events.clear();
  delete this->protocol;
  delete this->network;
}

void	Core::Loop() {
}
