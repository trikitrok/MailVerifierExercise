#pragma once

#include <string>

class MailVerifier
{
public:
  MailVerifier();
  virtual ~MailVerifier();

  bool isValidEmailAddress(const std::string & emailAddress) const;
};

