#pragma once

#include <string>

class MailVerifier
{
public:
  MailVerifier();
  virtual ~MailVerifier();

  bool isValidEmailAddress(const std::string & emailAddress) const;

private:
  bool doesNotContainAtSymbol(const std::string & emailAdreess) const;
  bool containsCommas(const std::string & emailAddress) const;
};

