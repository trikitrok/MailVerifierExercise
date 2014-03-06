#include "MailList.h"

#include "MailVerifier.h"

#include <set>

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

  std::vector<std::string> nonDuplicateEmailAddresses;
  std::set<std::string> setOfEmailAddresses;

  for (auto i = 0; i < emailAddresses.size(); ++i) {
    auto res = setOfEmailAddresses.insert(emailAddresses[i]);
    if (res.second) {
      nonDuplicateEmailAddresses.push_back(emailAddresses[i]);
    }
  }

  return nonDuplicateEmailAddresses;
}

void MailList::split(std::vector<std::string>& emailAddressesList, 
  const std::string & emailAddressesString) const {

  if (emailAddressesString.empty()) {
    return;
  }

  auto commaPosition = emailAddressesString.find(",");

  if (commaPosition == std::string::npos) {
    emailAddressesList.push_back(emailAddressesString);
    return;
  }

  auto emailAddress = emailAddressesString.substr(0, commaPosition);
  emailAddressesList.push_back(emailAddress);

  auto restOfEmailAddressesString = emailAddressesString.substr(commaPosition + 1);

  split(emailAddressesList, restOfEmailAddressesString);
}

std::vector<std::string> MailList::filterValid(const std::vector<std::string> & emailAddressesList) const {
  std::vector<std::string> validEmailAddresses;

  for (auto i = 0; i < emailAddressesList.size(); ++i) {
    if (mailVerifier->isValidEmailAddress(emailAddressesList[i])) {
      validEmailAddresses.push_back(emailAddressesList[i]);
    }
  }

  return validEmailAddresses;
}
