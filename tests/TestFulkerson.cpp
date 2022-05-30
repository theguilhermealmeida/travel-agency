#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Agency/Graph.h"

using testing::Eq;

TEST(Fulkerson, testGraph)
{
    Graph graph("../data/test.txt");

    EXPECT_EQ(graph.maxFlow(1, 6), 8);
}
