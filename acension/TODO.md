# Gravebound: Ascension — Build Todo

## Project Goal

Create a terminal-based C++ fantasy game where a weak dungeon runner becomes a necromancer. The player fights enemy factions, gains experience, raises defeated enemies into an undead army, and saves progress to files.

## Keep Version 1 Simple

- [ ] Use terminal menus only — no graphics or GUI.
- [ ] Use one player, one dungeon at a time, and turn-based combat.
- [ ] Start with Ice Elves and Red Orcs only.
- [ ] List Dwarves, Dragons, and Shadow Knights as future content.
- [ ] Do not build multiplayer, a large map, crafting, or complex AI in version 1.

## 1. Set Up the Project

- [x] Create `src/` for C++ source files.
- [ ] Create `data/` for saved game files.
- [ ] Add a `README.md` with build and run instructions (using direct `g++` compile commands).

## 2. Create the Core Data Types

- [ ] Create a base `Creature` class: name, health, mana, level, attack, defense, and core methods.
- [ ] Create a `Player` class derived from `Creature` (or incorporating base stats: Strength, Agility, Perception, Vitality, Intelligence) and command capacity.
- [ ] Create `IceElf` and `RedOrc` classes inheriting from `Creature`.
- [ ] Create enums for `Race`, `Role`, and `Rank`.
- [ ] Create an `Army` class that stores the player's raised units.
- [ ] Create a `Dungeon` / `DungeonEncounter` class for dungeon exploration and battles.

## 3. Build the Main Menu

- [ ] Start Game
- [ ] Load Game
- [ ] Enter Dungeon
- [ ] View Player Stats
- [ ] View Undead Army
- [ ] Save Game
- [ ] Exit

## 4. Work Out Turn-Based Combat System

- [ ] Implement basic turn-based combat framework.
- [ ] Let the player choose actions (Attack, Defend, Use Item, Command Raised Unit).
- [ ] Give enemies turns and combat logic using `Creature` methods.
- [ ] Award experience after winning encounters.
- [ ] End the run if the player's health reaches zero.

## 5. Build the Necromancy System

- [ ] After a battle, create remains for a defeated enemy.
- [ ] Let the player choose Raise, Sacrifice, or Leave.
- [ ] Raising costs mana (no soul fragments).
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

- [ ] Compile with warnings enabled using direct `g++` commands.
- [ ] Test a new game with no save file.
- [ ] Test winning and losing a battle.
- [ ] Test Raise, Sacrifice, and Leave choices.
- [ ] Test an army at maximum command capacity.
- [ ] Test save and load after making progress.
- [ ] Check that invalid menu input does not crash the program.
