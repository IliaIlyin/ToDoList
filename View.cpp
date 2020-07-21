//
// Created by Ilya on 7/20/2020.
//

#include "View.h"


void View::viewTask(Task& task) {
std::cout<<"task "<<task.getName()<<" with date: "<<task.getDate()<<std::endl;
std::cout<<"Priority "<<task.getPriority()<<" label "<<task.getLabel()<<std::endl;
}
