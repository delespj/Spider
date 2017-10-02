#ifndef CORE_HPP_
#define CORE_HPP_

#include <vector>

#include "Event.hpp"
#include "Protocol.hpp"
#include "Network.hpp"

class Core
{
private:
  std::vector<IEvent*>	events;
  Protocol*	protocol;
  Network*	network;
  bool		connect;

public:
  Core();
  ~Core();

  void	Loop();
};

#endif
