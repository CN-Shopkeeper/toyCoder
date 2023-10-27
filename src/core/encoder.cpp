#include "encoder.hpp"

namespace toyc {

Vector<CKUnit> Encoder::expandFlag(const std::string filename) {
  Vector<CKUnit> result;
  // 创建文件输入流对象
  std::ifstream inputFile(filename);

  // 检查文件是否成功打开
  if (!inputFile.is_open()) {
    throw std::runtime_error("无法打开文件 " + filename);
  }

  int flag = 0;
  const int n = 128;
  char ch;
  std::cout << "raw article:" << std::endl;
  // 逐字符读取文件内容
  while (inputFile.get(ch)) {
    std::cout << ch;
    flag += rand() % n;
    result.push({flag, ch});
  }
  std::cout << std::endl;

  // 关闭文件
  inputFile.close();

  return result;
}

void Encoder::writeBinaryFile(Vector<CKUnit>& ckUnits,
                              const std::string filename) {
  // 创建文件输出流对象，以二进制方式打开
  std::ofstream outputFile(filename, std::ios::binary);

  // 检查文件是否成功打开
  if (!outputFile.is_open()) {
    throw std::runtime_error("无法打开文件 " + filename + " 进行写入");
  }

  for (int i = 0; i < ckUnits.size(); i++) {
    auto unit = ckUnits.get(i);
    outputFile.write(&unit.value, sizeof(char));
    outputFile.write(reinterpret_cast<const char*>(&unit.flag), sizeof(int));
  }

  // 关闭文件
  outputFile.close();
}

void Encoder::Encode(const std::string filename) {
  auto ckUnits = expandFlag(filename);
  ckUnits.randomize();
  std::cout << std::endl << "randomize result: " << std::endl;
  for (int i = 0; i < ckUnits.size(); i++) {
    std::cout << ckUnits.get(i).value;
  }
  std::cout << std::endl << std::endl;
  writeBinaryFile(ckUnits);
}
}  // namespace toyc