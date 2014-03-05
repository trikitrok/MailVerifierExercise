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

TEST(AMailList, IncludesTwoValidEmailAddressesSeparatedByCommas) {
  MailList mailList(new MailVerifier);
  ASSERT_THAT(mailList.getMails("h@h.com,x@x.com"), 
    ElementsAre("h@h.com", "x@x.com"));
}