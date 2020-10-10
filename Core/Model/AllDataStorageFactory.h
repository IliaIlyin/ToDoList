//
// Created by ilya on 01.10.20.
//

#ifndef TODOLIST_CORE_MODEL_ALLDATASTORAGEFACTORY_H_
#define TODOLIST_CORE_MODEL_ALLDATASTORAGEFACTORY_H_
#include "AllDataStorage.h"
#include "AllDataStorageFactoryInterface.h"
class AllDataStorageFactory : public AllDataStorageFactoryInterface{
 public:
  std::shared_ptr<AllDataStorageInterface> create() override;
};

#endif //TODOLIST_CORE_MODEL_ALLDATASTORAGEFACTORY_H_
