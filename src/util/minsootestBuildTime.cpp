#include "minsootestBuildTime.h"

minsootestBuildTime::minsootestBuildTime()
: dateTime(__DATE__ " " __TIME__)
{
}

minsootestBuildTime::~minsootestBuildTime()
{
}

const char* minsootestBuildTime::GetDateTime()
{
    return dateTime;
}

