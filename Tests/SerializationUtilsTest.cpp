//
// Created by ilya on 01.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "SerializationUtils.h"
#include "Core/Mocks/AllDataStorageMock.h"
using testing::Eq;
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class SerializationUtilsTest : public ::testing::Test {

};

bool equal(const protoStorage::Task proto_task, const protoStorage::Task proto_task2) {
  return proto_task.name() == proto_task2.name() &&
      proto_task.date().date() == proto_task2.date().date() &&
      proto_task.priority() == proto_task2.priority() &&
      proto_task.label() == proto_task2.label();
}
TEST_F(SerializationUtilsTest, shouldConvertTaskDate) {
  boost::gregorian::date date{2000, 11, 11};
  protoStorage::TaskDate task_date;
  task_date.set_date(date.day_number());
  ASSERT_EQ(date, convertDate(task_date));
  ASSERT_EQ(task_date.date(), convertDate(date).date());
}
TEST_F(SerializationUtilsTest, shouldConvertTaskID) {
  TaskID id(1);
  coreService::TaskID task_id;
  task_id.set_id(1);
  ASSERT_EQ(id, convertTaskID(task_id));
  ASSERT_EQ(task_id.id(), convertTaskID(id).id());
}
TEST_F(SerializationUtilsTest, shouldConvertTaskDTO) {
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  TaskDTO dto = TaskDTO(task, TaskID(3), true);
  coreService::TaskID task_id;
  task_id.set_id(3);
  protoStorage::Task proto_task;
  proto_task.set_name("Lol");
  protoStorage::TaskDate date1;
  date1.set_date(boost::gregorian::date{2000, 12, 9}.day_number());
  proto_task.set_allocated_date(new protoStorage::TaskDate(date1));
  proto_task.set_priority(protoStorage::Task_Priority_FIRST);
  proto_task.set_label("label");
  coreService::TaskDTO proto_dto;
  proto_dto.set_allocated_task(new protoStorage::Task(proto_task));
  proto_dto.set_allocated_id(new coreService::TaskID(task_id));
  proto_dto.set_complete(true);
  ASSERT_EQ(dto, convertTaskDTO(proto_dto));
  ASSERT_TRUE(equal(proto_dto.task(), convertTaskDTO(dto).task()));
  ASSERT_EQ(proto_dto.id().id(),convertTaskDTO(dto).id().id());
  ASSERT_EQ(proto_dto.complete(),convertTaskDTO(dto).complete());
}



TEST_F(SerializationUtilsTest, shouldConvertTaskPriority) {
  Task::Priority first = Task::Priority::FIRST;
  auto res = protoStorage::Task_Priority_FIRST;
  ASSERT_EQ(res, convertPriority(first));
  Task::Priority sec = Task::Priority::SECOND;
  auto res2 = protoStorage::Task_Priority_SECOND;
  ASSERT_EQ(res2, convertPriority(sec));
  Task::Priority third = Task::Priority::THIRD;
  auto res3 = protoStorage::Task_Priority_THIRD;
  ASSERT_EQ(res3, convertPriority(third));
  Task::Priority none = Task::Priority::NONE;
  auto res4 = protoStorage::Task_Priority_NONE;
  ASSERT_EQ(res4, convertPriority(none));
}

TEST_F(SerializationUtilsTest, shouldConvertProtoPriority) {
  Task::Priority first = Task::Priority::FIRST;
  auto res = protoStorage::Task_Priority_FIRST;
  ASSERT_EQ(first, convertPriority(res));
  Task::Priority sec = Task::Priority::SECOND;
  auto res2 = protoStorage::Task_Priority_SECOND;
  ASSERT_EQ(sec, convertPriority(res2));
  Task::Priority third = Task::Priority::THIRD;
  auto res3 = protoStorage::Task_Priority_THIRD;
  ASSERT_EQ(third, convertPriority(res3));
  Task::Priority none = Task::Priority::NONE;
  auto res4 = protoStorage::Task_Priority_NONE;
  ASSERT_EQ(none, convertPriority(res4));
}

TEST_F(SerializationUtilsTest, shouldSerializeToTask) {
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  protoStorage::Task proto_task;
  proto_task.set_name("Lol");
  protoStorage::TaskDate date1;
  date1.set_date(boost::gregorian::date{2000, 12, 9}.day_number());
  proto_task.set_allocated_date(new protoStorage::TaskDate(date1));
  proto_task.set_priority(protoStorage::Task_Priority_FIRST);
  proto_task.set_label("label");
  auto task2 = convertTask(task);
  ASSERT_TRUE(equal(task2, proto_task));
}

TEST_F(SerializationUtilsTest, shouldSerializeToTaskEntity) {
  //entity creation
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  Task task2 = Task::createTask("fsdfds", boost::gregorian::date{2000, 12, 9}, Task::Priority::THIRD, "label");
  Task task3 = Task::createTask("Lgdfgdfgsdf", boost::gregorian::date{2000, 12, 9}, Task::Priority::SECOND, "label");
  std::shared_ptr<TaskEntity> ptr = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task2, idGenerator));
  taskEntity.addSubTask(ptr);
  std::shared_ptr<TaskEntity>
      ptr2 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task3, idGenerator, true));
  ptr->addSubTask(ptr2);
  //proto entity creation
  protoStorage::TaskEntity result;
  auto f1 = convertTask(task);
  result.set_allocated_task(new protoStorage::Task(f1));
  result.set_complete(false);
  auto entity2 = result.add_subtasks();
  entity2->set_complete(false);
  auto f2 = convertTask(task2);
  entity2->set_allocated_task(new protoStorage::Task(f2));
  auto entity3 = entity2->add_subtasks();
  auto f3 = convertTask(task3);
  entity3->set_complete(true);
  entity3->set_allocated_task(new protoStorage::Task(f3));
  //ASSERTIONS
  auto real = serializeToTaskEntity(taskEntity);
  ASSERT_TRUE(equal(real.task(), result.task()));
  ASSERT_EQ(real.complete(), result.complete());
  ASSERT_EQ(real.subtasks_size(), 1);
  auto subtasks1 = real.subtasks(0);
  auto real2 = serializeToTaskEntity(ptr.operator*());
  ASSERT_TRUE(equal(subtasks1.task(), real2.task()));
  ASSERT_EQ(subtasks1.complete(), real2.complete());
  ASSERT_EQ(subtasks1.subtasks_size(), 1);
  auto subtasks2 = real2.subtasks(0);
  auto real3 = serializeToTaskEntity(ptr2.operator*());
  ASSERT_TRUE(equal(subtasks2.task(), real3.task()));
  ASSERT_EQ(subtasks2.complete(), real3.complete());
  ASSERT_EQ(subtasks2.subtasks_size(), 0);
}

TEST_F(SerializationUtilsTest, shouldSerializeToStorageVectorEmpty) {
  std::vector<std::shared_ptr<TaskEntity>> vec;
  ASSERT_ANY_THROW(serializeToStorage(vec));

  // ASSERT_EQ(storage.tasks_size(), 0);
}

TEST_F(SerializationUtilsTest, shouldSerializeToStorage) {
  std::vector<std::shared_ptr<TaskEntity>> vec;
  //entity creation
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  Task task2 = Task::createTask("fsdfds", boost::gregorian::date{2000, 12, 9}, Task::Priority::THIRD, "label");
  Task task3 = Task::createTask("Lgdfgdfgsdf", boost::gregorian::date{2000, 12, 9}, Task::Priority::SECOND, "label");
  std::shared_ptr<TaskEntity> ptr = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task2, idGenerator));
  taskEntity.addSubTask(ptr);
  std::shared_ptr<TaskEntity>
      ptr2 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task3, idGenerator, true));
  vec.push_back(std::make_shared<TaskEntity>(taskEntity));
  vec.push_back(ptr2);
  protoStorage::Storage storage = serializeToStorage(vec);
  ASSERT_EQ(storage.tasks_size(), 2);
  ASSERT_TRUE(equal(storage.tasks(0).task(), convertTask(task)));
  ASSERT_EQ(storage.tasks(0).complete(), false);
  ASSERT_EQ(storage.tasks(0).subtasks_size(), 1);
  ASSERT_TRUE(equal(storage.tasks(0).subtasks(0).task(), convertTask(task2)));
  ASSERT_EQ(storage.tasks(0).subtasks(0).complete(), false);
  ASSERT_EQ(storage.tasks(0).subtasks(0).subtasks_size(), 0);
  ASSERT_TRUE(equal(storage.tasks(1).task(), convertTask(task3)));
  ASSERT_EQ(storage.tasks(1).complete(), true);
  ASSERT_EQ(storage.tasks(1).subtasks_size(), 0);
}

TEST_F(SerializationUtilsTest, shouldDeserializeFromTask) {
  protoStorage::Task proto_task;
  proto_task.set_name("Lol");
  protoStorage::TaskDate date1;
  date1.set_date(boost::gregorian::date{2000, 12, 9}.day_number());
  proto_task.set_allocated_date(new protoStorage::TaskDate(date1));
  proto_task.set_priority(protoStorage::Task_Priority_FIRST);
  proto_task.set_label("label");
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  ASSERT_EQ(convertTask(proto_task), task);
}

TEST_F(SerializationUtilsTest, shouldSerializeSubTasks) {
  protoStorage::Task task1;
  task1.set_name("Lol");
  protoStorage::TaskDate date1;
  date1.set_date(boost::gregorian::date{2000, 12, 9}.day_number());
  task1.set_allocated_date(new protoStorage::TaskDate(date1));
  task1.set_priority(protoStorage::Task_Priority_FIRST);
  task1.set_label("label");
  protoStorage::Task task2;
  task2.set_name("Lollipop");
  protoStorage::TaskDate date2;
  date2.set_date(boost::gregorian::date{2030, 12, 9}.day_number());
  task2.set_allocated_date(new protoStorage::TaskDate(date2));
  task2.set_priority(protoStorage::Task_Priority_SECOND);
  task2.set_label("AAAA");
  protoStorage::Task task3;
  task3.set_name("NoName");
  protoStorage::TaskDate date3;
  date3.set_date(boost::gregorian::date{2000, 5, 9}.day_number());
  task3.set_allocated_date(new protoStorage::TaskDate(date3));
  task3.set_priority(protoStorage::Task_Priority_NONE);
  task3.set_label("fdsfsd");
  protoStorage::TaskEntity entity1;
  entity1.set_allocated_task(new protoStorage::Task(task1));
  entity1.set_complete(false);
  auto sub1 = entity1.add_subtasks();
  sub1->set_complete(true);
  sub1->set_allocated_task(new protoStorage::Task(task2));
  auto sub2 = sub1->add_subtasks();
  sub2->set_allocated_task(new protoStorage::Task(task3));
  sub2->set_complete(false);
  Task t1 = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  Task t2 = Task::createTask("Lollipop", boost::gregorian::date{2030, 12, 9}, Task::Priority::SECOND, "AAAA");
  Task t3 = Task::createTask("NoName", boost::gregorian::date{2000, 5, 9}, Task::Priority::NONE, "fdsfsd");
  auto mock = std::make_shared<AllDataStorageMock>();
  EXPECT_CALL(mock.operator*(), addSubTaskToParent(TaskID(0), t2, true)).Times(1).WillOnce(Return(TaskID(1)));
  EXPECT_CALL(mock.operator*(), addSubTaskToParent(TaskID(1), t3, false)).Times(1).WillOnce(Return(TaskID(2)));
  serializeSubTasks(entity1, TaskID(0), mock);
}
TEST_F(SerializationUtilsTest, shouldSerializeTaskEntities) {
  protoStorage::Storage storage;
  protoStorage::Task task1;
  task1.set_name("Lol");
  protoStorage::TaskDate date1;
  date1.set_date(boost::gregorian::date{2000, 12, 9}.day_number());
  task1.set_allocated_date(new protoStorage::TaskDate(date1));
  task1.set_priority(protoStorage::Task_Priority_FIRST);
  task1.set_label("label");
  protoStorage::Task task2;
  task2.set_name("Lollipop");
  protoStorage::TaskDate date2;
  date2.set_date(boost::gregorian::date{2030, 12, 9}.day_number());
  task2.set_allocated_date(new protoStorage::TaskDate(date2));
  task2.set_priority(protoStorage::Task_Priority_SECOND);
  task2.set_label("AAAA");
  protoStorage::Task task3;
  task3.set_name("NoName");
  protoStorage::TaskDate date3;
  date3.set_date(boost::gregorian::date{2000, 5, 9}.day_number());
  task3.set_allocated_date(new protoStorage::TaskDate(date3));
  task3.set_priority(protoStorage::Task_Priority_NONE);
  task3.set_label("fdsfsd");
  protoStorage::TaskEntity entity1;
  entity1.set_allocated_task(new protoStorage::Task(task1));
  entity1.set_complete(false);
  auto sub1 = entity1.add_subtasks();
  sub1->set_complete(true);
  sub1->set_allocated_task(new protoStorage::Task(task2));
  auto sub2 = sub1->add_subtasks();
  sub2->set_allocated_task(new protoStorage::Task(task3));
  sub2->set_complete(false);
  auto vec = storage.add_tasks();
  vec->CopyFrom(entity1);
  Task t1 = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  Task t2 = Task::createTask("Lollipop", boost::gregorian::date{2030, 12, 9}, Task::Priority::SECOND, "AAAA");
  Task t3 = Task::createTask("NoName", boost::gregorian::date{2000, 5, 9}, Task::Priority::NONE, "fdsfsd");
  auto mock = std::make_shared<AllDataStorageMock>();
  EXPECT_CALL(mock.operator*(), addTask(t1, false)).Times(1).WillOnce(Return(TaskID(1)));
  EXPECT_CALL(mock.operator*(), addSubTaskToParent(TaskID(1), t2, true)).Times(1).WillOnce(Return(TaskID(2)));
  EXPECT_CALL(mock.operator*(), addSubTaskToParent(TaskID(2), t3, false)).Times(1).WillOnce(Return(TaskID(3)));
  serializeTaskEntities(storage, mock);
}