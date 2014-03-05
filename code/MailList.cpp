#include "MailList.h"

MailList::MailList(MailVerifier * mailVerifier) {
  this->mailVerifier = mailVerifier;
}

MailList::~MailList() {
  delete mailVerifier;
}

std::vector<std::string> MailList::getMails(const std::string & emailAddressesString) const {
  std::vector<std::string> emailAddressesList;

  if (!emailAddressesString.empty()) {
    emailAddressesList.push_back(emailAddressesString);
  }

  return emailAddressesList;
}
