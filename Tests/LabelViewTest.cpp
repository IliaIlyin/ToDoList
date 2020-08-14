//
// Created by illia.ilin on 8/12/2020.
//

#include <gtest/gtest.h>
#include "Views/LabelView.h"
using testing::Eq;

class LabelViewTest : public ::testing::Test {

};

TEST_F(LabelViewTest, shouldInsertTask) {
  LabelView view;
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  auto taskEntity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  std::shared_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  taskEntity->addSubTask(entity);
  ASSERT_EQ(view.insert(taskEntity), true);
  ASSERT_EQ(view.insert(taskEntity), false);
  ASSERT_NO_THROW(view.insert(taskEntity));
  ASSERT_EQ(view.insert(entity), true);
}

TEST_F(LabelViewTest, shouldCleanStorage) {
  LabelView view;
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  auto taskEntity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  std::shared_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  taskEntity->addSubTask(entity);
  view.insert(taskEntity);
  view.insert(entity);
  entity.reset();
  view.clean();
  auto vec = view.showAll();
  ASSERT_EQ(vec.size(), 2);
  ASSERT_EQ(vec.begin()->lock(), taskEntity);
  taskEntity.reset();
  view.clean();
  vec = view.showAll();
  ASSERT_EQ(vec.size(), 0);
}

TEST_F(LabelViewTest, shouldGetAll) {
  LabelView view;
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "labelgfd");
  Task task2 = Task::createTask("Lol", boost::gregorian::date{2020, 12, 9}, Task::Priority::SECOND, "l");
  Task task3 = Task::createTask("Lol", boost::gregorian::date{2010, 12, 9}, Task::Priority::THIRD, "label");
  Task task4 = Task::createTask("Lol", boost::gregorian::date{2010, 12, 19}, Task::Priority::NONE, "lal");
  Task task5 = Task::createTask("Lol", boost::gregorian::date{2010, 8, 9}, Task::Priority::SECOND, "lab");
  IdGenerator idGenerator;
  auto taskEntity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  auto taskEntity2 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task2, idGenerator));
  auto taskEntity3 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task3, idGenerator));
  auto taskEntity4 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task4, idGenerator));
  auto taskEntity5 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task5, idGenerator));
  view.insert(taskEntity);
  view.insert(taskEntity2);
  view.insert(taskEntity3);
  view.insert(taskEntity4);
  view.insert(taskEntity5);
  auto vec=view.showAll();
  auto iter=vec.begin();
  ASSERT_EQ(vec.size(),5);
  ASSERT_EQ(iter->lock(),taskEntity2);
  iter++;
  ASSERT_EQ(iter->lock(),taskEntity5);
  iter++;
  ASSERT_EQ(iter->lock(),taskEntity3);
  iter++;
  ASSERT_EQ(iter->lock(),taskEntity);
  iter++;
  ASSERT_EQ(iter->lock(),taskEntity4);
}
TEST_F(LabelViewTest, shouldGetToday) {
  LabelView view;
  auto tmp = boost::gregorian::day_clock::local_day();
  Task task = Task::createTask("Lol", tmp, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  auto taskEntity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  Task task2 = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  auto taskEntity2 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task2, idGenerator));
  Task task3 = Task::createTask("Lol", tmp, Task::Priority::SECOND, "lab");
  auto taskEntity3 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task3, idGenerator));
  view.insert(taskEntity);
  view.insert(taskEntity2);
  view.insert(taskEntity3);
  ASSERT_EQ(view.showToday().size(), 2);
  ASSERT_EQ(view.showToday().begin()->lock(), taskEntity3);
  auto vec=view.showToday();
  auto iter=vec.begin();
  iter++;
  ASSERT_EQ(iter->lock(),taskEntity);
}
TEST_F(LabelViewTest, shouldGetAllDueDate) {
  LabelView view;
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "labelgfd");
  Task task2 = Task::createTask("Lol", boost::gregorian::date{2020, 12, 9}, Task::Priority::SECOND, "l");
  Task task3 = Task::createTask("Lol", boost::gregorian::date{2010, 12, 9}, Task::Priority::THIRD, "label");
  Task task4 = Task::createTask("Lol", boost::gregorian::date{2010, 12, 19}, Task::Priority::NONE, "lal");
  Task task5 = Task::createTask("Lol", boost::gregorian::date{2010, 8, 9}, Task::Priority::SECOND, "lab");
  IdGenerator idGenerator;
  auto taskEntity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  auto taskEntity2 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task2, idGenerator));
  auto taskEntity3 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task3, idGenerator));
  auto taskEntity4 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task4, idGenerator));
  auto taskEntity5 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task5, idGenerator));
  view.insert(taskEntity);
  view.insert(taskEntity2);
  view.insert(taskEntity3);
  view.insert(taskEntity4);
  view.insert(taskEntity5);
  auto vec=view.showDueDate(boost::gregorian::date{2011,1,1});
  auto iter=vec.begin();
  ASSERT_EQ(vec.size(),4);
  ASSERT_EQ(iter->lock(),taskEntity5);
  iter++;
  ASSERT_EQ(iter->lock(),taskEntity3);
  iter++;
  ASSERT_EQ(iter->lock(),taskEntity);
  iter++;
  ASSERT_EQ(iter->lock(),taskEntity4);
}