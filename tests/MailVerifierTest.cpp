#include <gmock/gmock.h>

#include "../code/MailVerifier.h"

using namespace ::testing;

TEST(ForMailVerifier, AnEmptyEmailAddressIsNotValid) {
  MailVerifier mailverifier;
  ASSERT_FALSE(mailverifier.isValidEmailAddress(""));
}

TEST(ForMailVerifier, AnEmailAddressWithoutAtLeastOneAtIsNotValid) {
  MailVerifier mailverifier;
  ASSERT_FALSE(mailverifier.isValidEmailAddress("hola"));
}