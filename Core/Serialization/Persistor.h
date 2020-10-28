//
// Created by ilya on 30.09.20.
//

#ifndef TODOLIST_PERSISTOR_H
#define TODOLIST_PERSISTOR_H

#include "Serialization/Serializer.h"
#include "SerializationUtils.h"
#include <vector>
#include "Model/AllDataStorageInterface.h"
#include "Model/AllDataStorageFactoryInterface.h"
#include "Model/AllDataStorage.h"
#include "StorageModel.pb.h"
#include <iostream>
#include <fstream>
#include <string>

class Persistor : public Serializer {

 public:
  Persistor(std::shared_ptr<std::iostream> stream,
            std::shared_ptr<AllDataStorageInterface> storage,
            std::shared_ptr<AllDataStorageFactoryInterface> factory);

 public:
  bool Save() override;
  bool Load() override;

 private:
  std::shared_ptr<std::iostream> stream_;
  std::shared_ptr<AllDataStorageInterface> storage_;
  std::shared_ptr<AllDataStorageFactoryInterface> factory_;
};

#endif //TODOLIST_PERSISTOR_H
