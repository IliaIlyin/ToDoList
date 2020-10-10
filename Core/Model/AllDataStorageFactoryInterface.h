//
// Created by ilya on 05.10.20.
//

#ifndef TODOLIST_CORE_MODEL_ALLDATASTORAGEFACTORYINTERFACE_H_
#define TODOLIST_CORE_MODEL_ALLDATASTORAGEFACTORYINTERFACE_H_
#include "AllDataStorageInterface.h"
/*
 * factory to create All Data Storages
 *
 * @author Ilya Ilyin
 */
class AllDataStorageFactoryInterface{
 public:
  /*
   * creates AllDataStorageObject
   *
   * @return pointer to the created object
   */
  virtual std::shared_ptr<AllDataStorageInterface> create()=0;
  virtual ~AllDataStorageFactoryInterface()=default;
};
#endif //TODOLIST_CORE_MODEL_ALLDATASTORAGEFACTORYINTERFACE_H_
