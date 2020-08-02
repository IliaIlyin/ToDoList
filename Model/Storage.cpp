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

bool Storage::addSubTaskToParent(std::shared_ptr<TaskEntity> parent, TaskEntity &task_entity) {
  parent->addsubtask(std::make_shared<TaskEntity>(task_entity));
  return true;
}
bool Storage::postponeTask(std::shared_ptr<TaskEntity> task, time_t dueDate) {
    auto iter = tasks_.find(task->getTaskId());
    if (iter != tasks_.end()) {
      Task t = Task::createTask(task.operator*().getTask().getName(),
                                dueDate + task.operator*().getTask().getDate(),
                                task.operator*().getTask().getPriority(), task.operator*().getTask().getLabel());

      TaskEntity taskEntity(t, task.operator*().getTaskId(), task.operator*().checkStatus(),
                            task.operator*().getSubtasks());

      this->deleteTask(task.operator*());
      return this->addTask(taskEntity);
    } else {
      std::cout << "task " << task.operator*().getTask().getName() << " Not found" << std::endl;
    }
  return false;
}
bool Storage::completeTask(std::shared_ptr<TaskEntity> task) {
  task.operator*().completeTask();
  auto vec = task.operator*().getSubtasks();
  for (auto i = vec.begin(); i != vec.end(); i++) {
    i->get()->completeTask();
  }
  return true;
}
