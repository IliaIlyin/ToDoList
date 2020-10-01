//
// Created by ilya on 01.10.20.
//

#ifndef TODOLIST_CORE_MODEL_ALLDATASTORAGEFACTORY_H_
#define TODOLIST_CORE_MODEL_ALLDATASTORAGEFACTORY_H_
#include "AllDataStorage.h"
class AllDataStorageFactory {
 public:
  std::shared_ptr<AllDataStorageInterface> create();
};

#endif //TODOLIST_CORE_MODEL_ALLDATASTORAGEFACTORY_H_
