# XeenItems

## Overview

Ever play Might & Magic's Clouds/Darkside/World/Swords of Xeen? Isn't it a pain to have to lookup whether the item you have is better than the item you just found on the lich you just killed? This is a program I wrote to help with that. Just type the name of the item in and it'll assembly, based on the nomenclature, what boosts and effects are found on that item.

## Project Structure

- **src/** – All source and header files
- **data/** – All item/modifier CSV data files
- **build/** – Build output directory (created by the build script)
- **build.sh** – Bash script to compile the project

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

Run the provided build script:

```bash
./build.sh
```

This will compile all source files from `src/` and output the binary to `build/main`.


### Running the Application

After successful compilation, you can run the program with:

```bash
build/main
```

## Data Files

All item data, modifiers, and definitions are loaded from CSV files in the `data/` directory:

- `weapons.csv`
- `armor.csv`
- `accessories.csv`
- `attributes.csv`
- `elements.csv`
- `materials.csv`

The program expects these files to be present in the `data/` directory.

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

## Todo:

Add functionality to input current party's makeup and inventory loadout. Then when querying an item, the potential change in each character's stats are shown (if they are able to use that item).

## Contributing

### Submit a pull request

If you'd like to contribute, please fork the repository and open a pull request to the `master` branch.
