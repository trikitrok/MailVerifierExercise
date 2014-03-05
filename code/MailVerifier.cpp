#include "MailVerifier.h"

MailVerifier::MailVerifier() {}

MailVerifier::~MailVerifier() {}

bool MailVerifier::isValidEmailAddress(const std::string & emailAddress) const {
  if (emailAddress.empty())
    return false;

  if (emailAddress.find("@") == std::string::npos)
    return false;

  return true;
}
