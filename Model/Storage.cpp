//
// Created by Ilya on 7/31/2020.
//

#include "Storage.h"
bool Storage::addTask(TaskEntity &task_entity) {
  tasks_.insert(std::make_pair(task_entity.getTaskId(), task_entity));
  return true;
}
bool Storage::deleteTask(TaskEntity &task_entity) {
  tasks_.erase(task_entity.getTaskId());
  return true;
}
TaskEntity Storage::getTask(TaskEntity &task_entity) {
  return tasks_.find(task_entity.getTaskId())->second;
}

bool Storage::addSubTaskToParent(TaskEntity& parent, TaskEntity &task_entity) {
  auto iter=tasks_.find(parent.getTaskId());
  iter->second.addsubtask(std::make_shared<TaskEntity>(task_entity));
  return true;
}

bool Storage::postponeTask(TaskEntity& task, time_t dueDate) {
    auto iter = tasks_.find(task.getTaskId());
    if (iter != tasks_.end()) {
      Task t = Task::createTask(task.getTask().getName(),
                                dueDate + task.getTask().getDate(),
                                task.getTask().getPriority(), task.getTask().getLabel());

      TaskEntity taskEntity(t, task.getTaskId(), task.checkStatus(),
                            task.getSubtasks());

      this->deleteTask(task);
      return this->addTask(taskEntity);
    } else {
      std::cout << "task " << task.getTask().getName() << " Not found" << std::endl;
    }
  return false;
}

bool Storage::completeTask(TaskEntity& task) {
  auto iter=tasks_.find(task.getTaskId());
  iter->second.completeTask();
  auto vec = iter->second.getSubtasks();
  for (auto i = vec.begin(); i != vec.end(); i++) {
    i->get()->completeTask();
  }
  return true;
}
