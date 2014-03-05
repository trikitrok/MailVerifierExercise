#include "MailVerifier.h"

MailVerifier::MailVerifier() {}

MailVerifier::~MailVerifier() {}

bool MailVerifier::isValidEmailAddress(const std::string & emailAddress) const {
  if (emailAddress.empty())
    return false;

  if (doesNotContainAtSymbol(emailAddress))
    return false;

  if (containsCommas(emailAddress))
    return false;

  if (emailAddress.find(" ") != std::string::npos)
    return false;

  return true;
}

bool MailVerifier::doesNotContainAtSymbol(const std::string & emailAddress) const {
  return emailAddress.find("@") == std::string::npos;
}

bool MailVerifier::containsCommas(const std::string & emailAddress) const {
  return emailAddress.find(",") != std::string::npos;
}
