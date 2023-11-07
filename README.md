# POO-tp
Attack and Conquest Game| Empire Builder (comand line game)

## Description

Empire Builder is a text-based single-player strategy game implemented in C/C++. In this game, you take on the role of a ruler who aims to conquer and expand their empire. You'll manage resources, make strategic decisions, and acquire technologies to build a powerful empire. The game is turn-based, with each turn consisting of multiple phases.

## Features

- Conquer territories to expand your empire.
- Manage resources: products and gold.
- Acquire technologies to enhance your empire's capabilities.
- Face random events like resource discoveries, invasions, and diplomatic alliances.
- Calculate your final score based on the territories, technologies, and achievements.

## How to Play

1. Clone or download this repository to your local machine.
2. Compile the C++ source code using a C++ compiler (e.g., g++).
   ```
   g++ main.cpp -o empire_builder
   ```
3. Run the game:
   ```
   ./empire_builder
   ```
4. Follow the on-screen instructions and use the provided commands to control your empire.
5. Start by uploading the **territorios.txt** file

## Commands

- `carrega <nomeFicheiro>`: Upload inicial territories from a file.
- `cria <tipo> <n>`: Add n territories of a specific type to the world.
  - tipo: this can be at **"Territories Details"** below
- `conquista <nome>`: Conquer a territory with the given name.
- `passa`: Skip conquering in this turn.
- `maisouro`: Exchange 2 products for 1 gold.
- `maisprod`: Exchange 2 gold for 1 product.
- `maismilitar`: Purchase an additional military unit.
- `adquire <tipo>`: Purchase a specific technology.
- `lista <nome>`: View game information, globally or for a specific territory.
- `avanca`: Advance to the next phase of the turn.
- `grava <nome>`: Save the current game state. (Not implemented)
- `ativa <nome>`: Load a previously saved game state. (Not implemented)
- `apaga <nome>`: Delete a saved game state. (Not implemented)
- `toma <qual> <nome>`: Instantly acquire a territory or technology (for debugging).
- `modifica <ouro|prod> N`: Modify the empire's gold or product quantities (for debugging).
- `fevento <nome-evento>`: Force the occurrence of a specific event (for debugging).

## Territories Details

### Initial Territory

- **Resistance:** 9
- **Victory Points:** None
- **Production:**
  - First-year: 1 unit of products and 1 unit of gold per turn
  - Second-year: 2 units of products and 1 unit of gold per turn

### Continents

Continents consist of various types of territories, each with unique characteristics. These territories are always available for conquest by the player.

### Plain

- **Resistance:** 5
- **Production:**
  - First-year: 1 unit of products and 1 unit of gold per turn
  - Second-year: 2 units of products and 1 unit of gold per turn

### Mountain

- **Resistance:** 6
- **Production:**
  - No production in the first 2 turns after conquest
  - Subsequent production: 1 unit of products per turn

### Fortress

- **Resistance:** 8
- **Production:** None (no products or gold)

### Mine

- **Resistance:** 5
- **Production:**
  - First-year: 1 unit of gold in the first 3 turns
  - Second-year: 2 units of gold in the second 3 turns

### Dune

- **Resistance:** 4
- **Production:** 1 unit of products per turn

### Castle

- **Resistance:** 7
- **Production:**
  - 1 unit of gold per turn
  - 3 units of products in the first 2 turns of each year

### Islands

Islands are less accessible territories that can only be targeted for conquest if the player has acquired the "Mísseis Teleguiados" technology and has at least 5 territories. There are two types of islands:

### Refúgio dos Piratas (Pirate's Haven)

- **Resistance:** 9
- **Production:** 1 unit of gold per turn

### Pescaria (Fishing Ground)

- **Resistance:** 9
- **Production:**
  - First-year: 2 units of products per turn
  - Second-year: 4 units of products per turn

These territories have distinct characteristics and production values, which impact the player's strategy in the game.



## Implementation Details

- Territories, resources, and technologies are represented using object-oriented programming concepts.
- The program has been organized into separate .h and .cpp files for clarity and modularity.

## Acknowledgments

This game was developed as a programming project for the "Object-Oriented Programming" course in the academic year 2020/2021.

## Authors

- Pedro Pedrosa
