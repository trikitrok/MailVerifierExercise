#include <gmock/gmock.h>

#include "../code/MailVerifier.h"
#include "../code/MailList.h"

using namespace ::testing;

TEST(AMailList, ReturnsAnEmptyListWhenPassedAnEmptyString) {
  MailList mailList(new MailVerifier);
  ASSERT_THAT(mailList.getMails(""), IsEmpty());
}

TEST(AMailList, IncludesAValidEmailAddress) {
  MailList mailList(new MailVerifier);
  ASSERT_THAT(mailList.getMails("hola@hola.com"), ElementsAre("hola@hola.com"));
}

TEST(AMailList, IncludesSeveralValidEmailAddressesSeparatedByCommas) {
  MailList mailList(new MailVerifier);
  ASSERT_THAT(mailList.getMails("h@h.com,x@x.com,a@a.com"),
    ElementsAre("h@h.com", "x@x.com", "a@a.com"));
}

TEST(AMailList, IgnoresInvalidEmailAddresses) {
  MailList mailList(new MailVerifier);
  ASSERT_THAT(mailList.getMails("h@h.com,x@com,a@a.com"),
    ElementsAre("h@h.com", "a@a.com"));
}

TEST(AMailList, RemovesDuplicateValidEmailAddressesSeparatedByCommas) {
  MailList mailList(new MailVerifier);
  ASSERT_THAT(mailList.getMails("h@h.com,x@x.com,a@a.com,h@h.com"),
    ElementsAre("h@h.com", "x@x.com", "a@a.com"));
}

TEST(AMailList, IgnoresSpacesAroundValidEmailAddress) {
  MailList mailList(new MailVerifier);
  ASSERT_THAT(mailList.getMails("  h@h.com  , x@x.com,a@a.com  "),
    ElementsAre("h@h.com", "x@x.com", "a@a.com"));
}