//
// Created by Ilya on 7/20/2020.
//

#include "Display.h"

void Display::viewEntity(TaskEntity &entity) {
  Task t = entity.getTask();
  viewTask(t);
  std::cout << "status " << entity.checkStatus() << " ; " << std::endl;
  auto vec = entity.getSubtasks();
  for (auto i = vec.begin(); i != vec.end(); i++)
    viewEntity(i->operator*());
}

void Display::viewTask(Task &task) {
  std::cout << "task " << task.getName() << " with date: " << task.getDate() << std::endl;
  std::cout << "Priority " << task.getPriority() << " label " << task.getLabel() << std::endl;
}
