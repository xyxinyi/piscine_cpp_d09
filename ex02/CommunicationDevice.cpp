#include <iostream>
#include <stdexcept>
#include <sstream>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input,
                                         std::ostream &output)
  try  : _api(input, output)
{

}
catch (std::exception &e){
  std::ostringstream error;
  error << "Error: " << e.what();
  throw CommunicationError(error.str());
}
CommunicationDevice::~CommunicationDevice()
{
}

void CommunicationDevice::startMission(std::string const &missionName,
                                  std::string *users,
                                  size_t nbUsers)
{
  try{
    for (size_t i = 0; i < nbUsers; ++i)
      _api.addUser(users[i]);
    _api.startMission(missionName);
  }
  catch(std::logic_error &e)
  {
    std::ostringstream error;
    error << "LogicError: " << e.what();
    throw CommunicationError(error.str());
  }
  catch(std::runtime_error &e)
  {
    std::ostringstream error;
    error << "RuntimeError: " << e.what();
    throw CommunicationError(error.str());
  }
  catch(std::exception &e)
  {
    std::ostringstream error;
    error << "Error: " << e.what();
    throw CommunicationError(error.str());
  }
}

void CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
  try{
    _api.sendMessage(user, message);
  }catch(std::exception &e){
    std::cerr << e.what() << std::endl;
  }
}

void CommunicationDevice::receive(std::string const &user,
                             std::string &message) const
{
  try{
    _api.receiveMessage(user, message);
  }catch(std::exception &e){
    std::cerr << e.what() << std::endl;
    std::cerr << "INVALID MESSAGE" << std::endl;
  }
}
