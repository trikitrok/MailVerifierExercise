#include "MailList.h"

#include "MailVerifier.h"

#include "VectorUtils.h"
#include "StringUtils.h"

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
  auto emailAddresses = StringUtils::split(emailAddressesString, ",");
  return trimEmailAddresses(emailAddresses);
}

std::vector<std::string> MailList::trimEmailAddresses(const std::vector<std::string> & emailAddresses) const {
  return VectorUtils::map<std::string, std::string>(emailAddresses, StringUtils::trim);
}

std::vector<std::string> MailList::filterValid(const std::vector<std::string> & emailAddresses) const {
  return VectorUtils::filter(emailAddresses, [this](const std::string emailAddress) {
    return mailVerifier->isValidEmailAddress(emailAddress);
  });
}

std::vector<std::string> MailList::removeDuplicate(const std::vector<std::string> & emailAddresses) const {
  return VectorUtils::removeDuplicate<std::string>(emailAddresses);
}