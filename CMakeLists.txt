cmake_minimum_required(VERSION 2.4)
project(Artificial_Life)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets CONFIG REQUIRED)


add_subdirectory(src)
add_subdirectory(include)
include_directories(include)

add_executable(Artificial_Life
        src/main.cc
        src/Vector.cc include/Vector.h
        src/Window.cc include/Window.h
        src/Map.cc include/Map.h
        src/Simulation.cc include/Simulation.h
        src/Genotype.cc include/Genotype.h
        src/Organism.cc include/Organism.h
        src/Action.cc include/Action.h
        src/Needs.cc include/Needs.h
        src/Herbivore.cc include/Herbivore.h
        src/Carnivore.cc include/Carnivore.h
        src/CarnivoreAction.cc include/CarnivoreAction.h
        src/HerbivoreAction.cc include/HerbivoreAction.h
        src/Tests.cc include/Tests.h
        src/HerbivoreActionFactory.cc include/HerbivoreActionFactory.h
        src/CarnivoreActionFactory.cc include/CarnivoreActionFactory.h
        src/HerbivoreEating.cc include/HerbivoreEating.h
        src/CarnivoreHunting.cc include/CarnivoreHunting.h
        src/OrganismView.cc include/OrganismView.h
        src/SimulationView.cc include/SimulationView.h
        src/DesiredActionAdapter.cc include/DesiredActionAdapter.h)

target_link_libraries(Artificial_Life Qt5::Widgets)

