#include "core/decoder.hpp"
#include "core/encoder.hpp"

int main() {
  setlocale(LC_ALL, "zh_CN.UTF-8");
  toyc::Encoder::Encode();
  std::cout << "encode end" << std::endl;
  toyc::Decoder::Decode();
  std::cout << "decode end" << std::endl;
  return 0;
}