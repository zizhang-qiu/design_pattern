cmake_minimum_required(VERSION 3.30)
project(design_pattern)

set(CMAKE_CXX_STANDARD 17)

add_executable(factory src/factory.cc)
add_executable(abstract_factory src/abstract_factory.cc)
add_executable(builder src/builder.cc)
add_executable(prototype src/prorotype.cc)
add_executable(singleton src/singleton.cc)
add_executable(adapter src/adapter.cc)
add_executable(bridge src/bridge.cc)
add_executable(composite src/composite.cc)
add_executable(decorator src/decorator.cc)
add_executable(facade src/facade.cc)
add_executable(fly_weight src/fly_weight.cc)
add_executable(proxy src/proxy.cc)
add_executable(interpreter src/interpreter.cc)
add_executable(template src/template.cc)
add_executable(chain_of_responsibility src/chain_of_responsibility.cc)
add_executable(command src/command.cc)
add_executable(iterator src/iterator.cc)
add_executable(mediator src/mediator.cc)
add_executable(memento src/memento.cc)
add_executable(observer src/observer.cc)
add_executable(state src/state.cc)
add_executable(strategy src/strategy.cc)
add_executable(visitor src/visitor.cc)
