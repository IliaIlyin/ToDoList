//
// Created by Ilya on 5/20/2020.
//

#include "Task.h"

#include <utility>

Task::Task(std::string name, time_t date, Task::Priority priority, std::string label) : name(std::move(name)),
                                                                                        date(date), priority(priority),
                                                                                        label(std::move(label)) {

}

const std::string &Task::getName() const {
    return name;
}

time_t Task::getDate() const {
    return date;
}

Task::Priority Task::getPriority() const {
    return priority;
}

const std::string &Task::getLabel() const {
    return label;
}

Task::~Task() {
std::cout<<"Task "<<this->label<<" destroyed"<<std::endl;
}

Task Task::createTask(std::string name, time_t date, Task::Priority priority, std::string label) {
    return Task(name,date,priority,label);
}

std::ostream& operator<<(std::ostream &os, const Task::Priority &priority1) {
    switch(priority1){
        case Task::Priority::NONE :
           os<<"No priority set";
           break;
        case Task::Priority::FIRST :
            os<<"First priority";
            break;
        case Task::Priority::SECOND :
            os<<"Second priority";
            break;
        case Task::Priority::THIRD :
            os<<"Third priority";
            break;
    }
    return os;
}


