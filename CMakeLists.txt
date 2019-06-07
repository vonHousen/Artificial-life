cmake_minimum_required(VERSION 2.4)
project(Artificial_Life)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(PROJECT_CODE
                                        include/ALife/LeadingDesire.h
        src/Vector.cc                   include/ALife/Vector.h
        src/RandomGenerator.cc          include/ALife/RandomGenerator.h
        src/Window.cc                   include/ALife/Window.h
        src/Map.cc                      include/ALife/Map.h
        src/MapTile.cc                  include/ALife/MapTile.h
        src/Simulation.cc               include/ALife/Simulation.h
        src/Genotype.cc                 include/ALife/Genotype.h
        src/Organism.cc                 include/ALife/Organism.h
        src/Action.cc                   include/ALife/Action.h
        src/Needs.cc                    include/ALife/Needs.h
        src/Herbivore.cc                include/ALife/Herbivore.h
        src/Carnivore.cc                include/ALife/Carnivore.h
        src/CarnivoreAction.cc          include/ALife/CarnivoreAction.h
        src/HerbivoreAction.cc          include/ALife/HerbivoreAction.h
        src/HerbivoreActionFactory.cc   include/ALife/HerbivoreActionFactory.h
        src/CarnivoreActionFactory.cc   include/ALife/CarnivoreActionFactory.h
        src/HerbivoreEating.cc          include/ALife/HerbivoreEating.h
        src/CarnivoreHunting.cc         include/ALife/CarnivoreHunting.h
        src/SimulationView.cc           include/ALife/SimulationView.h
        src/MapTileView.cc              include/ALife/MapTileView.h
        src/OrganismView.cc             include/ALife/OrganismView.h
        src/CarnivoreView.cc            include/ALife/CarnivoreView.h
        src/HerbivoreView.cc            include/ALife/HerbivoreView.h
        src/CarnivoreSleeping.cc        include/ALife/CarnivoreSleeping.h
        src/HerbivoreSleeping.cc        include/ALife/HerbivoreSleeping.h
        src/CarnivoreReproduction.cc    include/ALife/CarnivoreReproduction.h
        src/HerbivoreReproduction.cc    include/ALife/HerbivoreReproduction.h
        )

find_package(Qt5Widgets CONFIG REQUIRED)

add_subdirectory(include/googletest)
add_subdirectory(tests)
add_subdirectory(src)
add_subdirectory(include/ALife)
include_directories(include/ALife)
include_directories(include/googletest)

if(COMMAND cmake_policy)
        cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

add_executable(Artificial_Life
        src/main.cc
        ${PROJECT_CODE})

add_executable(A_Tests
        tests/main_test.cc
        ${PROJECT_CODE}
        tests/HuntingTestSuite.cc
        tests/BasicTestSuite.cc
        tests/SleepingTestSuite.cc
        tests/ReproductionTestSuite.cc
        )

target_link_libraries(Artificial_Life   Qt5::Widgets)
target_link_libraries(A_Tests           Qt5::Widgets gtest gtest_main)

