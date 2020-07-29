//
// Created by Ilya on 5/20/2020
//

#include "TaskID.h"

TaskID::TaskID(const int id) : id(id) {}

int TaskID::getId() const {
    return this->id;
}
