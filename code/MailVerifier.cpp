#include "MailVerifier.h"

MailVerifier::MailVerifier() {}

MailVerifier::~MailVerifier() {}

bool MailVerifier::isValidEmailAddress(const std::string & emailAddress) const {

  if (containsMoreThanOneAtSymbols(emailAddress))
    return false;

  return ! isNotValid(emailAddress);
}

bool MailVerifier::isNotValid(const std::string & emailAddress) const {
  return emailAddress.empty() ||
    doesNotContainAtSymbol(emailAddress) ||
    containsCommas(emailAddress) ||
    containsSpaces(emailAddress);
}

bool MailVerifier::doesNotContainAtSymbol(const std::string & emailAddress) const {
  return emailAddress.find("@") == std::string::npos;
}

bool MailVerifier::containsCommas(const std::string & emailAddress) const {
  return emailAddress.find(",") != std::string::npos;
}

bool MailVerifier::containsSpaces(const std::string & emailAddress) const {
  return emailAddress.find(" ") != std::string::npos;
}

bool MailVerifier::containsMoreThanOneAtSymbols(const std::string & emailAddress) const {
  return emailAddress.find_first_of("@") != emailAddress.find_last_of("@");
}

