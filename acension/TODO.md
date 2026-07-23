# Gravebound: Ascension — Build Todo

## Project Goal

Create a terminal-based C++ fantasy game where a weak dungeon runner becomes a necromancer. The player fights enemy factions, gains experience, raises selected defeated enemies into an undead army, and saves progress to files.

## Keep Version 1 Simple

- [ ] Use terminal menus only — no graphics or GUI.
- [ ] Use one player, one dungeon at a time, and turn-based combat.
- [ ] Start with Ice Elves and Red Orcs only.
- [ ] List Dwarves, Dragons, and Shadow Knights as future content.
- [ ] Do not build multiplayer, a large map, crafting, or complex AI in version 1.

## 1. Set Up the Project

- [ ] Create `src/` for C++ source files.
- [ ] Create `data/` for saved game files.
- [ ] Create `tests/` for simple test data.
- [ ] Add a `README.md` with build and run instructions.
- [ ] Add a `Makefile` or simple build command.

## 2. Create the Core Data Types

- [ ] Create a `Player` class: name, level, health, mana, soul fragments, and command capacity.
- [ ] Create a `Unit` class: name, race, role, rank, health, attack, and command cost.
- [ ] Create enums for `Race`, `Role`, and `Rank`.
- [ ] Create an `Army` class that stores the player's raised units.
- [ ] Create an `Enemy` or `DungeonEncounter` class for battles.

## 3. Build the Main Menu

- [ ] Start Game
- [ ] Load Game
- [ ] Enter Dungeon
- [ ] View Player Stats
- [ ] View Undead Army
- [ ] Save Game
- [ ] Exit

## 4. Build Basic Combat

- [ ] Let the player choose attack, defend, use a healing item, or command a raised unit.
- [ ] Give enemies health, attack, and a simple turn.
- [ ] Award experience and soul fragments after a win.
- [ ] End the run if the player's health reaches zero.

## 5. Build the Necromancy System

- [ ] After a battle, create remains for a defeated enemy.
- [ ] Let the player choose Raise, Sacrifice, or Leave.
- [ ] Raising costs mana and soul fragments.
- [ ] Check command capacity before adding a unit to the army.
- [ ] Give raised units a role: Vanguard, Ranger, Guard, or Ritualist.
- [ ] Make higher-rank units cost more command capacity.
- [ ] Let sacrifice give resources instead of a unit.

## 6. Add Factions

### Ice Elves

- [ ] Add tank, archer, mage, healer, and melee soldier roles.
- [ ] Keep the total soldier cap at 200.
- [ ] Add 3 princes, 3 princesses, a king, and a queen as elite encounters.

### Red Orcs

- [ ] Add 100 tribals and 10 chieftains.
- [ ] Add 3 apprentices and 1 seer.
- [ ] Add 500 regular Orc soldiers, 20 commanders, and 5 generals.
- [ ] Add the 100-member King's Guard.
- [ ] Add the king, queen, two Queen's Guards, and Balrog as late-game encounters.

## 7. Add Long-Term Storage

- [ ] Save player stats and dungeon progress in `data/save_game.txt`.
- [ ] Save raised units in `data/army.txt`.
- [ ] Save resources in `data/inventory.txt`.
- [ ] Load all saved data when the player selects Load Game.
- [ ] Test that saving, closing, and loading restores the same player and army.

## 8. Test Before Calling It Done

- [ ] Compile with warnings enabled.
- [ ] Test a new game with no save file.
- [ ] Test winning and losing a battle.
- [ ] Test Raise, Sacrifice, and Leave choices.
- [ ] Test an army at maximum command capacity.
- [ ] Test save and load after making progress.
- [ ] Check that invalid menu input does not crash the program.

## Definition of Done for Version 1

- [ ] The game runs completely in the terminal.
- [ ] The player can fight at least one Ice Elf and one Red Orc encounter.
- [ ] The player can raise or sacrifice enemies.
- [ ] The player can save and load progress.
- [ ] The project has clear source, data, and README files.
