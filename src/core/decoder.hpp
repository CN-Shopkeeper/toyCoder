#pragma once

#include <fstream>

#include "utils/ckunit.hpp"
#include "utils/vector.hpp"

namespace toyc {
class Decoder final {
 public:
  static void Decode(const std::string filename = "data/binary_data.dat");

 private:
};
}  // namespace toyc
