//
// Created by illia.ilin on 8/17/2020.
//


#include <gtest/gtest.h>

#include "Model/dtoConvertor.h"
using testing::Eq;

class ConvertorTest : public ::testing::Test {

};
TEST_F(ConvertorTest, shouldConvertToTaskDTO) {
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  auto taskEntity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  TaskDTO dto = dtoConvertor::convert(taskEntity.operator*());
  ASSERT_EQ(dto.getTask(), task);
  ASSERT_EQ(dto.getTaskId(), TaskID(0));
}
TEST_F(ConvertorTest, shouldConvertToTaskEntity) {
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskDTO dto(task, idGenerator.generateId(), false);
  TaskEntity entity = dtoConvertor::convert(dto);
  ASSERT_EQ(TaskID(0), entity.getTaskId());
  ASSERT_EQ(entity.getTask(), task);
  ASSERT_EQ(entity.getSubTasks(), std::vector<std::shared_ptr<TaskEntity>>());
  ASSERT_EQ(entity.checkStatus(), false);
}
TEST_F(ConvertorTest, shouldConvertWeakPtrsToTaskEntity) {
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
  taskEntity2->addSubTask(taskEntity3);
  std::vector<std::weak_ptr<TaskEntity>> vec;
  vec.push_back(taskEntity);
  vec.push_back(taskEntity2);
  vec.push_back(taskEntity3);
  vec.push_back(taskEntity4);
  vec.push_back(taskEntity5);
  std::vector<TaskDTO> res = dtoConvertor::convert(vec);
  ASSERT_EQ(res.size(), 5);
  ASSERT_EQ(res[0], TaskDTO(task, TaskID(0), false));
  ASSERT_EQ(res[1], TaskDTO(task2, TaskID(1), false));
  ASSERT_EQ(res[2], TaskDTO(task3, TaskID(2), false));
  ASSERT_EQ(res[3], TaskDTO(task3, TaskID(3), false));
  ASSERT_EQ(res[4], TaskDTO(task4, TaskID(4), false));
}

TEST_F(ConvertorTest, shouldConvertSharedPtrsToTaskEntity) {
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
  taskEntity2->addSubTask(taskEntity3);
  std::vector<std::weak_ptr<TaskEntity>> vec;
  vec.push_back(taskEntity);
  vec.push_back(taskEntity2);
  vec.push_back(taskEntity3);
  vec.push_back(taskEntity4);
  vec.push_back(taskEntity5);
  std::vector<TaskDTO> res = dtoConvertor::convert(vec);
  ASSERT_EQ(res.size(), 5);
  ASSERT_EQ(res[0], TaskDTO(task, TaskID(0), false));
  ASSERT_EQ(res[1], TaskDTO(task2, TaskID(1), false));
  ASSERT_EQ(res[2], TaskDTO(task3, TaskID(2), false));
  ASSERT_EQ(res[3], TaskDTO(task3, TaskID(3), false));
  ASSERT_EQ(res[4], TaskDTO(task4, TaskID(4), false));
}