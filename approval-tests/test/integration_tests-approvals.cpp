#include <catch2/catch.hpp>
#include "run.h"
#include "ApprovalTests.hpp"
#include <random>

using namespace ApprovalTests;

TEST_CASE("test empty input approvals poc") {

  std::stringstream in;
  std::stringstream out;

  run(in, out);
  Approvals::verify(42);
  //  Approvals::verify(out.str());
}

TEST_CASE("test scrubber poc") {

  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(1,1000);

  std::stringstream os;
  os << "Hello " << distribution(generator) << " World";
  Approvals::verify(os.str(),
                    Options(Scrubbers::createRegexScrubber(R"(\d+)", "[number]")));
}