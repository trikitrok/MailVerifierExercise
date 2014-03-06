#include "MailList.h"

#include "MailVerifier.h"

#include "VectorUtils.h"
#include "StringUtils.h"

#include <functional>

MailList::MailList(MailVerifier * mailVerifier) {
  this->mailVerifier = mailVerifier;
}

MailList::~MailList() {
  delete mailVerifier;
}

std::vector<std::string> MailList::getMails(const std::string & emailAddressesString) const {
  
  auto emailAddresses = extractEmailAddresses(emailAddressesString);

  emailAddresses = filterValid(emailAddresses);

  emailAddresses = removeDuplicate(emailAddresses);

  return emailAddresses;
}

std::vector<std::string> MailList::extractEmailAddresses(const std::string & emailAddressesString) const {
  std::vector<std::string> emailAddresses;

  StringUtils::split(emailAddresses, emailAddressesString, ",");

  return emailAddresses;
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