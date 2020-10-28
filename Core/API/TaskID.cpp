//
// Created by Ilya on 5/20/2020
//

#include "API/TaskID.h"

TaskID::TaskID(const int id) : id(id) {}

int TaskID::getId() const {
  return this->id;
}

bool operator==(const TaskID &id, const TaskID &id2) {
  return id2.getId() == id.getId();
}

bool operator<(const TaskID &id, const TaskID &id2) {
  return id.getId() < id2.getId();
}
