#include "MailVerifier.h"

MailVerifier::MailVerifier() {}

MailVerifier::~MailVerifier() {}

bool MailVerifier::isValidEmailAddress(const std::string & emailAddress) const {

  bool isValid = ! isNotValid(emailAddress);

  if (isValid) {
    if (doesNotContainsDotAfterAtSymbol(emailAddress))
      return false;
  }

  return isValid;
}

bool MailVerifier::isNotValid(const std::string & emailAddress) const {
  return emailAddress.empty() ||
    doesNotContainAtSymbol(emailAddress) ||
    containsCommas(emailAddress) ||
    containsSpaces(emailAddress) ||
    containsMoreThanOneAtSymbols(emailAddress);
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

bool MailVerifier::doesNotContainsDotAfterAtSymbol(const std::string & emailAddress) const {
  auto atPosition = emailAddress.find("@");
  auto stringAfterAt = emailAddress.substr(atPosition + 1);
  return stringAfterAt.find(".") == std::string::npos;
}

