//
// Created by Ilya on 5/20/2020
//

#ifndef TODOLIST_TASKID_H
#define TODOLIST_TASKID_H

#include"Task.h"

class TaskID {

public:

    explicit TaskID(int id);

    int getId() const;

private:
    int id;
};


#endif //TODOLIST_TASKID_H
