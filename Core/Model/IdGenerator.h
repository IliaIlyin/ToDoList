//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_IDGENERATOR_H
#define TODOLIST_IDGENERATOR_H

#include "API/TaskID.h"

/*
 * class that generates TaskIDs
 * @see TaskID
 */
class IdGenerator {

public:
  /*
   * generates TaskID object
   *
   * @return TaskID
   */
    TaskID generateId();

    IdGenerator(int id = 0);

private:
    int id;
};


#endif //TODOLIST_IDGENERATOR_H
