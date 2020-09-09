//
// Created by illia.ilin on 8/21/2020.
//

#include "States/AddTaskState.h"
#include "TaskDateState.h"
template<typename T_NEXT, typename T_EXIT>
void AddTaskState<T_NEXT, T_EXIT>::read() {

}
template<typename T_NEXT, typename T_EXIT>
std::unique_ptr<State> AddTaskState<T_NEXT, T_EXIT>::changeState() {
  return TaskNameState<TaskDateState
}
template<typename T_NEXT, typename T_EXIT>
void AddTaskState<T_NEXT, T_EXIT>::execute(Context &context) {
  std::shared_ptr<Ad
                  StateMachine machine(std::make_unique<TaskNameState>(),);
  machine.run();
  auto context = machine.GetContext();
  dtos[0];
}
template<typename T_NEXT, typename T_EXIT>
void AddTaskState<T_NEXT, T_EXIT>::print() {
  std::cout << "Adding Task" << std::endl;
}
