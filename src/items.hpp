#ifndef HEADER_ITEMS_HPP
#define HEADER_ITEMS_HPP

#include <string>
#include <cstdint>

struct Weapon {
    std::string name;
    uint8_t minDamage;
    uint8_t maxDamage;
    uint16_t baseCost;
    std::string restrictions;
};

struct Armor {
    std::string name;
    uint16_t baseCost;
    uint8_t armorClass;
    std::string equipable;
    std::string restrictions;
};

struct Accessory {
    std::string name;
    uint16_t baseCost;
    std::string qtyEquipable;
};

struct AttributeModifier {
    std::string name;
    std::string type;
    uint8_t bonus;
};

struct ElementalModifier {
    std::string type;
    std::string name;
    uint8_t resistance;
    uint8_t damage;
};

struct MaterialModifier {
    std::string quality;
    std::string material;
    int toHitBonus;
    int damageBonus;
    int armorClassBonus;
    float costMultiplier;
};

#endif // HEADER_ITEMS_HPP
