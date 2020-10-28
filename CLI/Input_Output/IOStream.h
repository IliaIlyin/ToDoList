//
// Created by ilya on 19.10.20.
//

#ifndef TODOLIST_CLI_IOSTREAM_H_
#define TODOLIST_CLI_IOSTREAM_H_
#include <iostream>
#include <string>
#include <sstream>
#include "IOStreamInterface.h"
class IOStream : public IOStreamInterface {
 public:
  std::string input() override;
  void print(const std::string &str) override;
};

#endif //TODOLIST_CLI_IOSTREAM_H_
