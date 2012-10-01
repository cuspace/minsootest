#include "CppUTest/TestHarness.h"
#include "minsootestBuildTime.h"

TEST_GROUP(minsootestBuildTime)
{
  minsootestBuildTime* projectBuildTime;

  void setup()
  {
    projectBuildTime = new minsootestBuildTime();
  }
  void teardown()
  {
    delete projectBuildTime;
  }
};

TEST(minsootestBuildTime, Create)
{
  CHECK(0 != projectBuildTime->GetDateTime());
}

