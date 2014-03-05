#pragma once

#include <vector>
#include <string>

class MailVerifier;

class MailList
{
public:
  MailList(MailVerifier * mailVerifier);
  virtual ~MailList();

  std::vector<std::string> getMails(const std::string & emailAddressesString) const;

private:
  MailVerifier * mailVerifier;
};

