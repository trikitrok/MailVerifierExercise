#pragma once

#include <string>

class MailVerifier
{
public:
  MailVerifier();
  virtual ~MailVerifier();

  bool isValidEmailAddress(const std::string & emailAddress) const;

private:
  bool isNotValid(const std::string & emailAddress) const;
  bool doesNotContainAtSymbol(const std::string & emailAdreess) const;
  bool containsCommas(const std::string & emailAddress) const;
  bool containsSpaces(const std::string & emailAddress) const;
  bool containsMoreThanOneAtSymbols(const std::string & emailAddress) const;
  bool doesNotContainsDotAfterAtSymbol(const std::string & emailAddress) const;
};

