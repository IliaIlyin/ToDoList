//
// Created by ilya on 30.09.20.
//

#ifndef TODOLIST_PERSISTOR_H
#define TODOLIST_PERSISTOR_H

#include "Serializer.h"
#include "PersistorUtils.h"
#include <vector>
#include "Model/AllDataStorageInterface.h"
#include "Model/AllDataStorageFactory.h"
#include "Model/AllDataStorage.h"
#include "StorageModel.pb.h"
#include <iostream>
#include <fstream>
#include <string>

class Persistor : public Serializer {
 public:
  Persistor(std::shared_ptr<std::iostream> stream,
            std::shared_ptr<AllDataStorageInterface> storage,
            std::shared_ptr<AllDataStorageFactory> factory);

 public:
  bool Save() override;
  bool Load() override;

 private:
  void serializeSubTasks(const serializer::TaskEntity &entity,
                         const TaskID &id,
                         std::shared_ptr<AllDataStorageInterface> ptr);
  void serializeTaskEntities(const serializer::Storage &storage, std::shared_ptr<AllDataStorageInterface> ptr);

 private:
  std::shared_ptr<std::iostream> stream_;
  std::shared_ptr<AllDataStorageInterface> storage_;
  std::shared_ptr<AllDataStorageFactory> factory_;
};

#endif //TODOLIST_PERSISTOR_H
