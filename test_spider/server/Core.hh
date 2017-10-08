#ifndef CORE_HH_
# define CORE_HH_

#include "network.hh"

class Core {
private:
  Network	network;

public:
  Core();
  ~Core();
  void	loop();
};

#endif
