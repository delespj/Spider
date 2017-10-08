#include "Core.hh"

Core::Core() {
  this->network = 0;
}

Core::~Core() {
}

Core::init() {
  try {
    boost::asio::io_service io_service;
    this->network = Network(io_service, 4243);
    io_service.run();
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
