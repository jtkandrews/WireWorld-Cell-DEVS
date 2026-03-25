# WireWorld Cadmium

## Overview
This project simulates electronic logic elements using the WireWorld cellular automaton, implemented as a Cell-DEVS model in the cadmium v2 Simulation framework. 

*It is adapted from a previous Cell-DEVS WireWorld implementation originally developed by Abdulealh Al-Sanad (2005) in CD++*

Individual cells are modeled on a 2D grid using a Moore neighborhood. Electrons travel across conductive paths to simulate logic gates, and digital circuits. 

Each cell tracks a single state variable:
- 0: Background
- 1: Electron Head
- 2: Electron Tail
- 3: Wire Cell

## File Structure
```
WireWorld-Cell-DEVS/
├── src/
│   └── main.cpp                        # Simulation entry point
├── include/
│   └── wireworld_cell.hpp              # wireworld_cell class, wireworld_state struct, JSON parsing, and local computation function
├── config/
│   ├── or_gate_config.json             # Example config file
├── logs/
│   ├── or_gate_config_log.csv          #  Example log file
├── bin/
│   └── wireworld                       # Compiled simulation executable
├── build/                              # CMake build artifacts
├── videos/                             # Videos of Simulation results
├── CMakeLists.txt                      # CMake build configuration
├── build.sh                            # Build script
└── README.md
```

## Prerequisites
* **C++17** complier
* **CMake** 3.16 or higher
* **Cadmium v2** - DEVS simulation library

This project is configured to have `WireWorld-Cell-Devs` inside the `cadmium_v2` folder. Change include paths if you have cloned it elsewhere

## Compliation Intructions
```bash
source build.sh
```
This will:
* Remove any previous `bin/` and `build/` directories
* Run `cmake`
* Run `make` to compile the `wireworld` executable 

## Testing instructions
Run a scenario by passing a config file path
```bash
./bin/wireworld config/<scenario_config>.json
```

## Configuration files
* `clock_generator_config.json` - Demontrates a continous pulse generator. A closed loop of wire creates a repeating signal that emits electrons down an attached output path.
* `diode_blocked_config.json` - Shows a diode successfully blocking a reverse signal
* `diode_config.json` - Shows the same diode allowing a forward signal to pass.
* `or_gate_config.json` - Simulates a logical OR gate. Two input wires merge into a single wire, demonstrating that a signal from either inputs will continue down the path. 
* `signal_splitter.json` - Demonstrates a single signal duplicating into multiple outputs. 

## Visualizing the Results
Visualize the simulation using the [Cell-DEVS Web Viewer](https://devssim.carleton.ca/cell-devs-viewer/)
* Load the scenario config file (`.json`) and its corresponding log file (`.csv`)
* View animation or step through to view electron activity

Color Coding for the WireWorld elements:
| State             | Color  |
| ----------------- | ------ |
| 0 (Empty)         | Black  |
| 1 (Electron Head) | Blue   |
| 2 (Electron Tail) | Red    |
| 3 (Wire Cell)   | Yellow |

