//
// Created by ilya on 19.10.20.
//

#ifndef TODOLIST_CLI_IOSTREAMINTERFACE_H_
#define TODOLIST_CLI_IOSTREAMINTERFACE_H_
#include <string>
#include <sstream>
/*
 * class to input and output information
 *
 * @author Ilya Ilyin
 */
class IOStreamInterface {
 public:
  virtual std::string input() = 0;
  virtual void print(const std::string &str) = 0;
  virtual ~IOStreamInterface() = default;
};
#endif //TODOLIST_CLI_IOSTREAMINTERFACE_H_
