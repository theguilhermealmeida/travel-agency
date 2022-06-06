#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Agency/Agency.h"

using testing::Eq;

TEST(scenario1, scenario11)
{
    Agency agency("../data/test.txt");
    vector<int> path = {1, 2, 4, 6};

    vector<Trip> result = agency.scenario11(1, 6).getTrips();

    for (int i = 0; i < result.size(); i++) {
        EXPECT_EQ(result[i].src, path[i]);
    }
}
