#include "movie_utilities.h"

#include <iostream>

#include <ghc/filesystem.hpp>
namespace fs = ghc::filesystem;

// Find the movies data file, by looking relative to the location
// of the library source code.
std::string getMovieFileLocation() {
  // Calculate the location of the file of movies, in the
  // folder containing this source file:
  fs::path p{__FILE__};
  ghc::filesystem::path moviePath = p.parent_path() / "movies.csv";
  if (!fs::exists(moviePath)) {
    std::string errorMessage =
        "\n\n>> ERROR: Movie file not found: " + moviePath.string() +
        "\n"
        ">> __FILE__ is '" __FILE__ +
        "'\n"
        ">> __FILE__ in this working directory does not find this source file.\n"
        ">> If you are using the Ninja generator, your build tree \n"
        ">> will need to be outside the source tree.\n"
        ">> See "
        "https://github.com/approvals/ApprovalTests.cpp/blob/master/doc/"
        "TroubleshootingMisconfiguredBuild.md\n\n";
    std::cerr << errorMessage << std::endl;
    throw std::runtime_error(errorMessage);
  }
  return moviePath.string();
}
