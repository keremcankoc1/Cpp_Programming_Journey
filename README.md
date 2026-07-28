# Cpp_Programming_Journey 🏎️

This repository tracks my progress in C++ and software engineering, focusing on mathematical modeling and performance-oriented code.

## 🧮 Scientific Calculus Engine (`calculus_engine.cpp`)

A command-line tool built to perform numerical analysis on functions (currently x^2). This project bridges my studies in **Calculus** and **Software Engineering** at Ankara University.

### 🛠 Features
* **Numerical Integration**: Implemented using **Riemann Sums** with high sensitivity (10^7 steps).
* **Numerical Differentiation**: Calculates the instantaneous rate of change using the limit definition: [f(x+h) - f(x)] / h.
* **Limit Approximation**: Evaluates function continuity by approaching a point from both the left and right sides.

### 🔧 Technical Details
* **Language**: C++
* **Precision**: Uses `double` for high-accuracy floating-point calculations.
* **Robustness**: Includes `cin.fail()` handling to prevent crashes during invalid user input.

---

## 🔧 Polymorphic Car Diagnostics (`polymorphic_car_diagnostics.cpp`)

A diagnostic system designed to simulate pre-race hardware checks for an F1 car (RB20). This project demonstrates advanced memory management by testing different hardware components through a single unified interface.

### 🛠 Features
* **Automated Testing Loop**: Iterates through an array of vehicle components to run specific diagnostic checks (Engine RPM, Gearbox synchronizers).
* **Polymorphic Arrays**: Utilizes an array of base class pointers (`CarPart* components[]`) to store and manage dynamically allocated derived objects (`engine`, `gearBox`).
* **Strict Memory Safety**: Implements precise deletion sequences to completely eliminate memory leaks.

### 🔧 Technical Details
* **Concepts Used**: Polymorphism, Inheritance, Initializer Lists.
* **Modern C++ Practices**: Leverages `virtual` destructors and the `override` keyword to ensure safe and predictable derived class behavior.
* **Memory Allocation**: 100% Heap-based architecture using `new` and `delete`.

---

## 📡 Dynamic Sensor Board (`dynamic_sensor_board.cpp`)

An interactive telemetry dashboard simulating pit-wall data collection. It dynamically swaps and manages different types of car sensors based on real-time user input.

### 🛠 Features
* **Runtime Object Assignment**: Instantiates different sensor types (Temperature, Pressure) on the fly based on user selection.
* **Manager Class Architecture**: Employs a `telemetryBoard` class that acts as a wrapper, containing an `activeSensor` pointer to bridge the dashboard with the hardware.
* **Segfault Prevention**: Carefully allocates memory for both the container object and the nested pointer, ensuring safe memory access.

### 🔧 Technical Details
* **Dynamic Binding**: Uses `virtual` functions to resolve the correct `readData()` method at runtime.
* **Pointer Nesting**: Demonstrates safe chaining and dereferencing (`->`) from a manager object to a dynamically allocated component.
* **Cleanup Hierarchy**: Cascading memory deallocation (deleting the inner sensor before the outer board).

## 📻 F1 Radio Log System (`f1_radio_linked_list.cpp`)

A dynamic data structure implementation designed to store and manage F1 driver radio messages. This project is built from scratch to demonstrate the fundamental principles of linked lists without relying on standard C++ libraries like `<vector>` or `<list>`.

### 🛠 Features
* **Dynamic Sizing**: Implements a singly linked list to add new messages dynamically, eliminating the constraints of fixed-size arrays.
* **Node Traversal**: Uses pointer iteration to navigate through the linked nodes and display chronological radio logs.
* **Safe Memory Deallocation**: Features a custom memory cleanup algorithm that safely disconnects and deletes each node step-by-step, ensuring zero memory leaks upon program termination.

### 🔧 Technical Details
* **Data Structure**: Singly Linked List (Node-based architecture).
* **Memory Management**: Manual allocation using `new` and systematic deallocation using `delete`.
* **Pointers**: Utilizes struct/class pointers for node linking and data retrieval.

## 🏋️ Dynamic Fitness Management (`dynamic_fitness_management.cpp`)

A fitness club membership management simulation that demonstrates the use of class-level (static) variables and dynamic object arrays. The system is populated with a 21-driver F1 grid to stress-test capacity limits and memory handling.

### 🛠 Features
* **Shared Class State**: Utilizes `static` variables (`personLimit`, `priceForMonth`) to manage global facility rules independently from individual customer objects.
* **Automated Object Generation**: Replaces manual instantiation with a dynamic pointer array (`Customer* grid[21]`), instantiating objects iteratively via a `for` loop.
* **Input Validation & Logic**: Includes a robust `while(true)` loop to handle incorrect membership durations and calculate precise payment differences (under/overpayments).

### 🔧 Technical Details
* **Memory Management**: Prevents memory leaks by cleanly iterating through the pointer array with `delete` upon program exit.
* **Data Initialization**: Prevents garbage value errors by strictly initializing default states (e.g., `membershipTime = 0`) within the constructor.
* **Boundary Testing**: Implements strict `<` boundary checks to accurately enforce maximum capacity limits without off-by-one errors.

---

## 📡 Live Telemetry Logger & Gear Simulator (`Telemetry Logger`)

A real-time telemetry recording system designed to simulate an F1 car's sequential gear shifts during a race stint. This project focuses on safe file handling, resource management, and state-machine logic to generate and log race data.

### 🛠 Features
* **Sequential Gear Simulation**: Utilizes a constrained `switch-case` state machine to simulate realistic upshifts and downshifts (Gears 1-8), preventing impossible mechanical jumps.
* **High-Frequency Telemetry Loop**: Runs a continuous simulation representing 40 consecutive moments of a single lap, calculating and logging dynamic gearbox telemetry for each specific snapshot.
* **Safe File I/O Management**: Automatically creates and manages a dedicated `race.txt` log file, outputting system success/failure states directly to the terminal.

### 🔧 Technical Details
* **Concepts Used**: File Handling (`std::fstream`), Object-Oriented Encapsulation, State Machines, Random Number Generation logic.
* **Modern C++ Practices**: Implements strong RAII (Resource Acquisition Is Initialization) principles. The file stream is safely opened in the constructor and strictly closed in the destructor (`~telemetryLogger`), ensuring zero resource leaks even if the program terminates unexpectedly.
* **Data Formatting**: Converts raw integer-based mechanical states into formatted string outputs for clean, readable log files.

---

## 🚗 Garage Management System

A simple C++ console application created as part of my **C++ Learning Journey**.

This project focuses on practicing object-oriented programming and modern C++ fundamentals by implementing a small garage management system where drivers and cars can be stored and queried.

---

### Features

- ➕ Add new drivers
- 🚘 Add new cars
- 📋 List all drivers
- 📋 List all cars
- 🔍 Display all cars belonging to a selected driver
- 🖥️ Console-based menu system

---

### Concepts Practiced

This project was written to reinforce the following C++ topics:

- Classes & Objects
- Constructors
- Encapsulation
- Getter functions
- `const` member functions
- `std::vector`
- `using` aliases
- Static class members
- Range-based `for`
- `getline()`
- Input buffer management (`std::cin.ignore`)
- Function decomposition
- Basic object relationships

---

### Project Structure

```
Garage
│
├── Driver
│     ├── id
│     ├── name
│     ├── team
│     └── age
│
├── Car
│     ├── ownerId
│     ├── model
│     ├── plate
│     └── year
│
└── Menu
      ├── Add Driver
      ├── Add Car
      ├── List Drivers
      ├── List Cars
      └── Show Driver's Cars
```

---

### Example

```
=============================================
1. Add Driver
2. Add Car
3. List All Drivers
4. List All Cars
5. List One Driver's Cars
6. Exit
=============================================
```

---

### Purpose

This is **not intended to be a production-ready project.**

The main goal is to gain hands-on experience with C++ syntax, object-oriented programming, and writing cleaner, more modular code before moving on to larger projects.

---

### Future Improvements

- [ ] Driver deletion
- [ ] Car deletion
- [ ] Driver editing
- [ ] Car editing
- [ ] File saving/loading
- [ ] Unique ID validation
- [ ] Error handling for invalid input
- [ ] Split into header/source files
- [ ] Use enums where appropriate
- [ ] Refactor into a larger Garage class

---

### Learning Journey

This project is part of my **Cpp_Learning_Journey** repository, where I document my progress while learning Modern C++ through small projects and exercises.

---

*Future goal: Adapting these algorithms and OOP structures for real-time F1 telemetry and simulation data.* 🏁