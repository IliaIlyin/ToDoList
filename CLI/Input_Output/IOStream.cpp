//
// Created by ilya on 19.10.20.
//

#include "IOStream.h"
void IOStream::print(const std::string &str) {
  std::cout << str << std::endl;
}
std::string IOStream::input() {
  std::string str;
  std::getline(std::cin, str);
  return str;
}
