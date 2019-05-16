cmake_minimum_required(VERSION 2.4)
project(Artificial_Life)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(PROJECT_CODE
        src/Vector.cc                   include/Alife/Vector.h
        src/Window.cc                   include/Alife/Window.h
        src/Map.cc                      include/Alife/Map.h
        src/Simulation.cc               include/Alife/Simulation.h
        src/Genotype.cc                 include/Alife/Genotype.h
        src/Organism.cc                 include/Alife/Organism.h
        src/Action.cc                   include/Alife/Action.h
        src/Needs.cc                    include/Alife/Needs.h
        src/Herbivore.cc                include/Alife/Herbivore.h
        src/Carnivore.cc                include/Alife/Carnivore.h
        src/CarnivoreAction.cc          include/Alife/CarnivoreAction.h
        src/HerbivoreAction.cc          include/Alife/HerbivoreAction.h
        src/HerbivoreActionFactory.cc   include/Alife/HerbivoreActionFactory.h
        src/CarnivoreActionFactory.cc   include/Alife/CarnivoreActionFactory.h
        src/HerbivoreEating.cc          include/Alife/HerbivoreEating.h
        src/CarnivoreHunting.cc         include/Alife/CarnivoreHunting.h
        src/OrganismView.cc             include/Alife/OrganismView.h
        src/SimulationView.cc           include/Alife/SimulationView.h
        src/CarnivoreView.cc            include/ALife/CarnivoreView.h
        src/HerbivoreView.cc            include/ALife/HerbivoreView.h
        src/DesiredActionAdapter.cc     include/Alife/DesiredActionAdapter.h
        )

find_package(Qt5Widgets CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(include/Alife)
add_subdirectory(include/googletest)
add_subdirectory(tests)
include_directories(include/Alife)
include_directories(include/googletest)

add_executable(Artificial_Life
        src/main.cc
        ${PROJECT_CODE})

add_executable(A_Tests
        tests/main_test.cc
        tests/Tests.cc tests/Tests.h
        ${PROJECT_CODE}
        )

target_link_libraries(Artificial_Life   Qt5::Widgets)
target_link_libraries(A_Tests           Qt5::Widgets gtest gtest_main)

