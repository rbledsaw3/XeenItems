#include <iostream>

#include "party.hpp"


Character createCharacter() {
    std::string name;
    CharacterClass characterClass = CharacterClass::ARCHER;
    uint8_t level = 0;
    uint16_t hitPoints = 0;
    uint16_t spellPoints = 0;
    uint16_t armorClass = 0;
    int meleeAttack = 0;
    int rangedAttack = 0;
    uint8_t meleeDamage = 0;
    uint8_t rangedDamage = 0;
    Stats stats{};
    Resistances resistances{};
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

    std::cout << "Enter character name: ";
    std::getline(std::cin, name);
    std::cout << "Enter character class (1-10): ";
    uint8_t classInput = 0;
    std::cin >> classInput;
    if (classInput < 1 || classInput > NUM_CLASSES) {
        std::cerr << "Invalid character class. Defaulting to ARCHER." << '\n';
        characterClass = CharacterClass::ARCHER;
    } else {
        characterClass = static_cast<CharacterClass>(classInput);
    }
    std::cout << "Enter character level: ";
    std::cin >> level;
    std::cout << "Enter character HP: ";
    std::cin >> hitPoints;
    std::cout << "Enter character SP: ";
    std::cin >> spellPoints;
    std::cout << "Enter character AC: ";
    std::cin >> armorClass;
    std::cout << "Enter character melee attack: ";
    std::cin >> meleeAttack;
    std::cout << "Enter character ranged attack: ";
    std::cin >> rangedAttack;
    std::cout << "Enter character melee damage: ";
    std::cin >> meleeDamage;
    std::cout << "Enter character ranged damage: ";
    std::cin >> rangedDamage;
    std::cout << "Enter character stats (Mgt, Int, Per, End, Spd, Acy, Lck): ";
    std::cin >> stats.might >> stats.intellect >> stats.personality
                >> stats.endurance >> stats.speed >> stats.accuracy >> stats.luck;
    std::cout << "Enter character resistances (Fire, Elec, Cold, Poison, Energy, Magic): ";
    std::cin >> resistances.fire >> resistances.electric >> resistances.cold
                >> resistances.poison >> resistances.energy >> resistances.magic;
    std::cout << "Enter character melee weapon name: ";
    std::cin.ignore(); // Clear the newline character from the input buffer
    std::getline(std::cin, meleeWeapon.name);
    std::cout << "Enter character ranged weapon name: ";
    std::getline(std::cin, rangedWeapon.name);
    std::cout << "Enter character head armor name: ";
    std::getline(std::cin, headSlot.name);
    std::cout << "Enter character chest armor name: ";
    std::getline(std::cin, chestSlot.name);
    std::cout << "Enter character arms armor name: ";
    std::getline(std::cin, armsSlot.name);
    std::cout << "Enter character legs armor name: ";
    std::getline(std::cin, legsSlot.name);
    std::cout << "Enter character feet armor name: ";
    std::getline(std::cin, feetSlot.name);
    std::cout << "Enter character hands armor name: ";
    std::getline(std::cin, handsSlot.name);
    std::cout << "Enter character shield armor name: ";
    std::getline(std::cin, shieldSlot.name);
    std::cout << "Enter character necklace accessory name: ";
    std::getline(std::cin, necklaceSlot.name);
    std::cout << "Enter character ring accessory name 1: ";
    std::getline(std::cin, ringSlot1.name);
    std::cout << "Enter character ring accessory name 2: ";
    std::getline(std::cin, ringSlot2.name);
    std::cout << "Enter character trinket accessory name 1: ";
    std::getline(std::cin, trinketSlot1.name);
    std::cout << "Enter character trinket accessory name 2: ";
    std::getline(std::cin, trinketSlot2.name);
    std::cout << "Enter character trinket accessory name 3: ";
    std::getline(std::cin, trinketSlot3.name);
    std::cout << "Enter character trinket accessory name 4: ";
    std::getline(std::cin, trinketSlot4.name);
    return Character{
        name,
        characterClass,
        level,
        hitPoints,
        spellPoints,
        armorClass,
        meleeAttack,
        rangedAttack,
        meleeDamage,
        rangedDamage,
        stats,
        resistances,
        weapons,
        armors,
        accessories,
        meleeWeapon,
        rangedWeapon,
        headSlot,
        chestSlot,
        armsSlot,
        legsSlot,
        feetSlot,
        handsSlot,
        shieldSlot,
        necklaceSlot,
        ringSlot1,
        ringSlot2,
        trinketSlot1,
        trinketSlot2,
        trinketSlot3,
        trinketSlot4
    };
}

Party createParty(const std::unordered_map<std::string, Weapon>& weapons,
                     const std::unordered_map<std::string, Armor>& armors,
                        const std::unordered_map<std::string, Accessory>& accessories) {
    Party party;
    party.characters.fill(Character{});
    std::size_t idx = 0;
    for (auto& character : party.characters) {
        std::cout << "Creating character " << (idx + 1) << ":\n";
        character = createCharacter();
        idx++;
    }
    party.weapons = weapons;
    party.armors = armors;
    party.accessories = accessories;
    return party;
}
