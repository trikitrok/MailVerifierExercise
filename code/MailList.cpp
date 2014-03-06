#include "MailList.h"

#include "MailVerifier.h"

#include "VectorUtils.h"

#include <functional>

MailList::MailList(MailVerifier * mailVerifier) {
  this->mailVerifier = mailVerifier;
}

MailList::~MailList() {
  delete mailVerifier;
}

std::vector<std::string> MailList::getMails(const std::string & emailAddressesString) const {
  
  std::vector<std::string> emailAddresses;

  split(emailAddresses, emailAddressesString);

  emailAddresses = filterValid(emailAddresses);

  emailAddresses = removeDuplicate(emailAddresses);

  return emailAddresses;
}

void MailList::split(std::vector<std::string>& emailAddresses, 
  const std::string & emailAddressesString) const {

  if (emailAddressesString.empty()) {
    return;
  }

  auto commaPosition = emailAddressesString.find(",");

  if (commaPosition == std::string::npos) {
    emailAddresses.push_back(emailAddressesString);
    return;
  }

  auto emailAddress = emailAddressesString.substr(0, commaPosition);
  emailAddresses.push_back(emailAddress);

  auto restOfEmailAddressesString = emailAddressesString.substr(commaPosition + 1);

  split(emailAddresses, restOfEmailAddressesString);
}

std::vector<std::string> MailList::filterValid(const std::vector<std::string> & emailAddresses) const {
  return VectorUtils::filter(emailAddresses,
    std::bind1st(std::mem_fun(&MailList::isValid), this));
}

bool MailList::isValid(const std::string emailAddress) const {
  return mailVerifier->isValidEmailAddress(emailAddress);
}

std::vector<std::string> MailList::removeDuplicate(const std::vector<std::string> & emailAddresses) const {
  return VectorUtils::removeDuplicate<std::string>(emailAddresses);
}