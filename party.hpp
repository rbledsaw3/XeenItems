#ifndef HEADER_PARTY_HPP
#define HEADER_PARTY_HPP

#include <cstdint>
#include <string>
#include <unordered_map>
#include <array>
#include <cstdlib>

#include "items.hpp"

constexpr std::size_t MAX_CHARACTERS = 6;
constexpr std::size_t NUM_CLASSES = 10;

struct Stats {
    uint8_t might;
    uint8_t intellect;
    uint8_t personality;
    uint8_t endurance;
    uint8_t speed;
    uint8_t accuracy;
    uint8_t luck;
};

struct Resistances {
    uint8_t fire;
    uint8_t electric;
    uint8_t cold;
    uint8_t poison;
    uint8_t energy;
    uint8_t magic;
};

enum class CharacterClass : uint8_t {
    ARCHER,
    BARBARIAN,
    CLERIC,
    DRUID,
    KNIGHT,
    NINJA,
    PALADIN,
    RANGER,
    ROBBER,
    SORCERER,
};

struct Character {
    std::string name;
    CharacterClass characterClass;
    uint8_t level;
    uint16_t hp;
    uint16_t sp;
    uint16_t ac;
    int meleeAttack;
    int rangedAttack;
    uint8_t meleeDamage;
    uint8_t rangedDamage;
    Stats stats;
    Resistances resistances;
    std::unordered_map<std::string, Weapon> weapons;
    std::unordered_map<std::string, Armor> armors;
    std::unordered_map<std::string, Accessory> accessories;
    Weapon meleeWeapon;
    Weapon rangedWeapon;
    Armor headSlot;
    Armor chestSlot;
    Armor armsSlot;
    Armor legsSlot;
    Armor feetSlot;
    Armor handsSlot;
    Armor shieldSlot;
    Accessory necklaceSlot;
    Accessory ringSlot1;
    Accessory ringSlot2;
    Accessory trinketSlot1;
    Accessory trinketSlot2;
    Accessory trinketSlot3;
    Accessory trinketSlot4;
};

struct Party {
    std::array<Character, MAX_CHARACTERS> characters;
    std::unordered_map<std::string, Weapon> weapons;
    std::unordered_map<std::string, Armor> armors;
    std::unordered_map<std::string, Accessory> accessories;
};

Party createParty(const std::unordered_map<std::string, Weapon>& weapons,
                    const std::unordered_map<std::string, Armor>& armors,
                    const std::unordered_map<std::string, Accessory>& accessories);

Character createCharacter();

#endif // HEADER_PARTY_HPP
