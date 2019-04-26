cmake_minimum_required(VERSION 2.4)
project(Artificial_Life)

set(CMAKE_CXX_STANDARD 11)

add_executable(Artificial_Life main.cc Location.cc Location.h Window.cc Window.h Map.cc Map.h Simulation.cc Simulation.h Genotype.cc Genotype.h Organism.cc Organism.h Behaviour.cc Behaviour.h Needs.cc Needs.h Herbivore.cc Herbivore.h Carnivore.cc Carnivore.h)