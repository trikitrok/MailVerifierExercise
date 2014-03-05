#include <gmock/gmock.h>

#include "../code/MailVerifier.h"

using namespace ::testing;

class ForMailVerifier : public Test {
public:
  MailVerifier mailverifier;
};

TEST_F(ForMailVerifier, AnEmptyEmailAddressIsNotValid) {
  ASSERT_FALSE(mailverifier.isValidEmailAddress(""));
}

TEST_F(ForMailVerifier, AnEmailAddressWithoutAtLeastOneAtIsNotValid) {
  ASSERT_FALSE(mailverifier.isValidEmailAddress("hola"));
}

TEST_F(ForMailVerifier, AnEmailAddressContainingACommaIsNotValid) {
  ASSERT_FALSE(mailverifier.isValidEmailAddress("@,"));
}

TEST_F(ForMailVerifier, AnEmailAddressContainingSpacesIsNotValid) {
  ASSERT_FALSE(mailverifier.isValidEmailAddress("@ "));
}

TEST_F(ForMailVerifier, AnEmailAddressWitMoreThanOneAtIsNotValid) {
  ASSERT_FALSE(mailverifier.isValidEmailAddress("@@"));
}