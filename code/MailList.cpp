#include "MailList.h"

MailList::MailList(MailVerifier * mailVerifier) {
  this->mailVerifier = mailVerifier;
}

MailList::~MailList() {
  delete mailVerifier;
}

std::vector<std::string> MailList::getMails(const std::string & emailAddressesString) const {
  std::vector<std::string> emailAddressesList;

  if (emailAddressesString.empty()) {
    return emailAddressesList;
  }

  auto commaPosition = emailAddressesString.find(",");

  if (commaPosition == std::string::npos) {
    emailAddressesList.push_back(emailAddressesString);
    return emailAddressesList;
  }

  auto emailAddress = emailAddressesString.substr(0, commaPosition);
  emailAddressesList.push_back(emailAddress);

  auto restOfEmailAddressesString = emailAddressesString.substr(commaPosition + 1);
  //emailAddressesList.push_back(restOfEmailAddressesString);

  commaPosition = restOfEmailAddressesString.find(",");

  if (commaPosition == std::string::npos) {
    emailAddressesList.push_back(restOfEmailAddressesString);
    return emailAddressesList;
  }

  emailAddress = restOfEmailAddressesString.substr(0, commaPosition);
  emailAddressesList.push_back(emailAddress);

  restOfEmailAddressesString = restOfEmailAddressesString.substr(commaPosition + 1);
  emailAddressesList.push_back(restOfEmailAddressesString);
  
  return emailAddressesList;
}
