#include <iostream>
#include <stdexcept>
#include <sstream>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input,
                                         std::ostream &output)
   try : _api(input, output)
{
}
catch(std::exception &e) {
std::stringstream out;

out << "Error: " << e.what();
throw CommunicationError(out.str());
}

CommunicationDevice::~CommunicationDevice()
{
}

void CommunicationDevice::startMission(std::string const &missionName,
                                  std::string *users,
                                  size_t nbUsers)
{
  std::stringstream out;

  try {
    for (size_t i = 0; i < nbUsers; ++i)
      _api.addUser(users[i]);
    _api.startMission(missionName);
  }
  catch(std::logic_error &e) {
    out << "LogicError: " << e.what();
    throw CommunicationError(out.str());
  }
  catch(std::runtime_error &e) {
    out << "RuntimeError: " << e.what();
    throw CommunicationError(out.str());
  }
  catch(std::exception &e) {
    out << "Error: " << e.what();
    throw CommunicationError(out.str());
  }
}

void CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
  try {
    _api.sendMessage(user, message);
  }
  catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void CommunicationDevice::receive(std::string const &user,
                             std::string &message) const
{
  try {
    _api.receiveMessage(user, message);
  }
  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    std::cerr << "INVALID MESSAGE" << std::endl;
  }
}
