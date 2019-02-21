#include "Singleton.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//TEST(DatabaseTests, IsSingletonTest)
//{
//  auto& db = SingletonDatabase::get();
//  auto& db2 = SingletonDatabase::get();
//  ASSERT_EQ(1, db.instance_count);
//  ASSERT_EQ(1, db2.instance_count);
//}



TEST_CASE("RecordFinderTests", "SingletonTotalPopulationTest")
{
  SingletonRecordFinder rf;
  std::vector<std::string> names{ "Seoul", "Mexico City" };
  int tp = rf.total_population(names);
  EXPECT_EQ(17500000 + 17400000, tp);
}

TEST_CASE("RecordFinderTests", "DependantTotalPopulationTest")
{
  DummyDatabase db{};
  ConfigurableRecordFinder rf{ db };
  REQUIRE(4 == rf.total_population(
    std::vector<std::string>{"alpha", "gamma"}));
}

