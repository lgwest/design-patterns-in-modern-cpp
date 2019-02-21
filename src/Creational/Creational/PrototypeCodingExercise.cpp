#define CATCH_CONFIG_MAIN
#include "catch.hpp"

struct Point
{
  int x{ 0 }, y{ 0 };

  Point(){}
  
  Point(const int x, const int y) : x{x}, y{y} {}
};

struct Line
{
  Point *start, *end;
  
  Line(Point* const start, Point* const end)
    : start(start), end(end)
  {
  }

  ~Line()
  {
    delete start;
    delete end;
  }

  Line deep_copy() const
  {
    return Line{
      new Point(start->x, start->y),
      new Point(end->x, end->y)
    };
  }
};


TEST_CASE("", "") {
Line line1{
        new Point{3, 3},
        new Point{10, 10}
};

auto line2 = line1.deep_copy();
line1.start->
x = line1.start->y =
    line1.end->y = line1.end->y = 0;

REQUIRE(3 == line2.start->x);
REQUIRE(3 == line2.start->y);
REQUIRE(10 == line2.end->x);
REQUIRE(10 == line2.end->y);
}
