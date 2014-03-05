#include <gmock/gmock.h>

#include "../code/MailVerifier.h"
#include "../code/MailList.h"

using namespace ::testing;

TEST(AMailList, ReturnsAnEmptyEmailAddressesListWhenPassedAnEmptyString) {
  MailList mailList(new MailVerifier);
  ASSERT_THAT(mailList.getMails(""), IsEmpty());
}

TEST(AMailList, IncludesAValidEmailAddressInTheEmailAddressesList) {
  MailList mailList(new MailVerifier);
  ASSERT_THAT(mailList.getMails("hola@hola.com"), ElementsAre("hola@hola.com"));
}