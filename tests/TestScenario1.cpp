#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Agency/Agency.h"

using testing::Eq;

/*

   /
 1

 */

TEST(scenario1, scenario11)
{
    Agency agency("../data/test.txt");
    vector<int> path = {1, 2, 4, 6};

    EXPECT_EQ(agency.scenario11(), path);

}