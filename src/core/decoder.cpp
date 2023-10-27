#include "decoder.hpp"

namespace toyc {

void Decoder::Decode(const std::string filename) {
  Vector<CKUnit> ckUnits;
  std::ifstream inputFile(filename, std::ios::binary);

  // 检查文件是否成功打开
  if (!inputFile.is_open()) {
    throw std::runtime_error("无法打开文件 " + filename);
  }

  char value;
  int flag;
  bool b1, b2;
  while (inputFile.read(&value, sizeof(char)) &&
         inputFile.read(reinterpret_cast<char*>(&flag), sizeof(int))) {
    ckUnits.push({flag, value});
  }

  ckUnits.sort(
      [](const CKUnit& a, const CKUnit& b) { return a.flag < b.flag; });

  std::cout << std::endl << "decode result:" << std::endl;
  for (int i = 0; i < ckUnits.size(); i++) {
    std::cout << ckUnits.get(i).value;
  }
  std::cout << std::endl;
}

}  // namespace toyc