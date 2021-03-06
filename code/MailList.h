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

  std::vector<std::string> extractEmailAddresses(const std::string & emailAddressesString) const;
  std::vector<std::string> filterValid(const std::vector<std::string> & emailAddressesList) const;
  std::vector<std::string> removeDuplicate(const std::vector<std::string> & emailAddresses) const;
  std::vector<std::string> trimEmailAddresses(const std::vector<std::string> & emailAddresses) const;
};

