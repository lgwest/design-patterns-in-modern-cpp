#include <vector>
#include <string>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"



struct Person {
    int id;
    std::string name;
};

class PersonFactory {
    int id{0};
public:
    Person create_person(const std::string &name) {
        return {id++, name};
    }
};

TEST_CASE("Evaluate", "[factory]") {

    PersonFactory pf;

    auto p1 = pf.create_person("Chris");
    REQUIRE("Chris" == p1.name);

    // Expected the second created person's id to be = 1
    auto p2 = pf.create_person("Sarah");
    REQUIRE(1 == p2.id);
}

