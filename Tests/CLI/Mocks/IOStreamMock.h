//
// Created by ilya on 20.10.20.
//

#ifndef TODOLIST_TESTS_CLI_MOCKS_IOSTREAMMOCK_H_
#define TODOLIST_TESTS_CLI_MOCKS_IOSTREAMMOCK_H_
#include <gmock/gmock.h>
#include "Input_Output/IOStreamInterface.h"

class IOStreamMock : public IOStreamInterface {
 public:
  MOCK_METHOD(std::string, input, (), (override));
  MOCK_METHOD(void, print, (const std::string& str), (override));
};
#endif //TODOLIST_TESTS_CLI_MOCKS_IOSTREAMMOCK_H_
