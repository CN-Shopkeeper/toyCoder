#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "utils/ckunit.hpp"
#include "utils/vector.hpp"

namespace toyc {
class Encoder final {
 public:
  static void Encode(const std::string filename = "data/article.txt");

 private:
  static Vector<CKUnit> expandFlag(
      const std::string filename = "data/article.txt");
  static void writeBinaryFile(
      Vector<CKUnit>& ckUnits,
      const std::string filename = "data/binary_data.dat");
};
}  // namespace toyc
