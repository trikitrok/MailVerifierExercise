#include "MailList.h"

MailList::MailList(MailVerifier * mailVerifier) {
  this->mailVerifier = mailVerifier;
}

MailList::~MailList() {
  delete mailVerifier;
}

std::vector<std::string> MailList::getMails(const std::string & emailAddressesString) const {
  std::vector<std::string> emailAddressesList;

  splitMails(emailAddressesList, emailAddressesString);

  return emailAddressesList;
}

void MailList::splitMails(std::vector<std::string>& emailAddressesList, 
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

  splitMails(emailAddressesList, restOfEmailAddressesString);
}
