cmake_minimum_required(VERSION 3.12)
project(Artificial_Life)

set(CMAKE_CXX_STANDARD 14)

add_executable(Artificial_Life main.cc Vector.cc Vector.h Window.cc Window.h Map.cc Map.h Simulation.cc Simulation.h Genotype.cc Genotype.h Organism.cc Organism.h Action.cc Action.h Needs.cc Needs.h Herbivore.cc Herbivore.h Carnivore.cc Carnivore.h CarnivoreAction.cc CarnivoreAction.h HerbivoreAction.cc HerbivoreAction.h Tests.cc Tests.h)