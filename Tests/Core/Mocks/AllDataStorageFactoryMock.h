//
// Created by ilya on 11.10.20.
//

#ifndef TODOLIST_TESTS_CORE_MOCKS_ALLDATASTORAGEFACTORYMOCK_H_
#define TODOLIST_TESTS_CORE_MOCKS_ALLDATASTORAGEFACTORYMOCK_H_
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Model/AllDataStorageInterface.h"
#include "Model/AllDataStorageFactoryInterface.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class AllDataStorageFactoryMock : public AllDataStorageFactoryInterface {
 public:
  MOCK_METHOD(std::shared_ptr<AllDataStorageInterface>, create, (), (override));
};
#endif //TODOLIST_TESTS_CORE_MOCKS_ALLDATASTORAGEFACTORYMOCK_H_
