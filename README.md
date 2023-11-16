# XeenItems

## Overview
XeenItems is a comprehensive C++ project that handles various item-related functionalities for RPG gaming. It includes features like reading CSV files for items, armors, weapons, and more, and demonstrating their usage in a simulated environment.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

Before building the project, ensure you have `g++` installed on your system for compiling the C++ code.

### Cloning the Repository

First, clone the repository using Git:

```bash
git clone git@github.com:rbledsaw3/XeenItems.git
cd XeenItems
```

### Building the Project

To build the project, use the following commands:

```bash
g++ -Wall -pedantic main.cpp -o main
```


### Running the Application

After successful compilation, you can run the program with:

```bash
./main
```

## How to Use

Once the application is running, it will read data from the provided CSV files and initialize the in-game items, including weapons, armors, and accessories. The program will then simulate various functionalities like item selections, modifications, and display the results.

### Example

```bash
Enter an item with a modifier, or q/Q/exit/quit to quit: Ruby Long Sword
Name: Ruby Long Sword
Damage: 15-21
Cost: 3000
To Hit Bonus: +6
Restrictions: No Cleric Druid Ninja Sorcerer
Enter an item with a modifier, or q/Q/exit/quit to quit: Mind Ring
Name: Mind Ring
Bonus: +3 Intellect
Cost: 100
Qty Equipable: 2
Enter an item with a modifier, or q/Q/exit/quit to quit: Quartz Helm
Name: Quartz Helm
Armor Class: 7
Cost: 3000
Restrictions: None
Enter an item with a modifier, or q/Q/exit/quit to quit: Sonic Scimitar
Name: Sonic Scimitar
Damage: 2-10
Cost: 80
Elemental Damage: 5 Energy Damage
Total Damage: 7-15
Restrictions: No Cleric Druid Ninja Sorcerer
Enter an item with a modifier, or q/Q/exit/quit to quit: q
Exiting...
```
