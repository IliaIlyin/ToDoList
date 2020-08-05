//
// Created by Ilya on 5/20/2020.
//

#include "IdGenerator.h"

TaskID IdGenerator::generateId() {
    return TaskID((this->id)++);
}

IdGenerator::IdGenerator(int id) : id(id){}

