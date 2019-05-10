cmake_minimum_required(VERSION 2.4)
project(Artificial_Life)

set(CMAKE_CXX_STANDARD 14)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets CONFIG REQUIRED)

add_executable(Artificial_Life main.cc Vector.cc Vector.h Window.cc Window.h Map.cc Map.h Simulation.cc Simulation.h Genotype.cc Genotype.h Organism.cc Organism.h Action.cc Action.h Needs.cc Needs.h Herbivore.cc Herbivore.h Carnivore.cc Carnivore.h CarnivoreAction.cc CarnivoreAction.h HerbivoreAction.cc HerbivoreAction.h Tests.cc Tests.h HerbivoreActionFactory.cc HerbivoreActionFactory.h CarnivoreActionFactory.cc CarnivoreActionFactory.h HerbivoreEating.cc HerbivoreEating.h CarnivoreHunting.cc CarnivoreHunting.h OrganismView.cc OrganismView.h CarnivoreView.cc CarnivoreView.h HerbivoreView.cc HerbivoreView.h SimulationView.cc SimulationView.h DesiredActionAdapter.cc DesiredActionAdapter.h)

target_link_libraries(Artificial_Life Qt5::Widgets)

