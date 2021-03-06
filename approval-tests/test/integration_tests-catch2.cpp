#include <catch2/catch.hpp>
#include "run.h"
#include <sstream>

TEST_CASE("test empty input catch poc") {

  std::stringstream in;
  std::stringstream out;

  run(in, out);
  CHECK(out.str().empty());
}



// TODO: Uncomment this when proving the point

//TEST_CASE("test raw string catch poc") {
//
//  std::stringstream in;
//  std::stringstream out;
//
//  run(in, out);
//  CHECK(out.str() == R"(0: The Shawshank Redemption (1994)
//1: The Godfather (1972)
//2: The Godfather: Part II (1974)
//3: The Dark Knight (2008)
//4: Pulp Fiction (1994)
//5: The Good, the Bad and the Ugly (1966)
//6: The Lord of the Rings: The Return of the King (2003)
//7: Fight Club (1999)
//8: The Lord of the Rings: The Fellowship of the Ring (2001)
//9: Interstellar (2014)
//10: Whiplash (2014)
//11: Birdman (2014)
//12: Up (2009)
//13: WALL·E (2008)
//Enter customer name: Choose movie by number followed by rental days, just ENTER for bill:
//Rental Record for
//You owed 0.0
//You earned 0 frequent renter points
//)");
//}