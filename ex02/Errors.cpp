#include "Errors.hpp"

NasaError::NasaError(const std::string &message, const std::string &component) {
  this->_message = message;
  this->_component = component;
}

std::string const &NasaError::getComponent() const {
  return this->_component;
}

std::string const &NasaError::getMessage() const {
  return this->_message;
}

MissionCriticalError::MissionCriticalError(std::string const &message,
					   const std::string &component)
  : NasaError(message, component) {

}

LifeCriticalError::LifeCriticalError(std::string const &message,
				     const std::string &component) : NasaError(
  message, component) {

}

UserError::UserError(std::string const &message, const std::string &component)
  : NasaError(message, component) {

}

CommunicationError::CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice") {

}
