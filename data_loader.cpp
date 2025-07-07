#include <iostream>
#include <fstream>
#include <sstream>

#include "data_loader.hpp"

int parseInt(const std::string& str, const char* fileName) {
    try {
        return std::stoi(str);
    } catch (const std::invalid_argument& e) {
      std::cout << RED << "Error: invalid argument in " << fileName << ": " << e.what() << RESET << "\n";
      exit(1);
    }
}


float parseFloat(const std::string& str, const char* fileName) {
    try {
        return std::stof(str);
    } catch (const std::invalid_argument& e) {
      std::cout << RED << "Error: invalid argument in " << fileName << ": " << e.what() << RESET << "\n";
      exit(1);
    }
}

std::unordered_map<std::string, Weapon> loadWeapons(const char* fileName) {
  std::ifstream file(fileName);
  std::string line;
  std::unordered_map<std::string, Weapon> weapons;
  std::getline(file, line);
  while (std::getline(file, line)) {
    std::stringstream strStream(line);
    std::string name;
    std::string minDamage;
    std::string maxDamage;
    std::string baseCost;
    std::string restrictions;
    std::getline(strStream, name, ',');
    std::getline(strStream, minDamage, ',');
    std::getline(strStream, maxDamage, ',');
    std::getline(strStream, baseCost, ',');
    std::getline(strStream, restrictions);
    Weapon weapon = {
            name,
            parseUnsignedInt<uint8_t>(minDamage, fileName),
            parseUnsignedInt<uint8_t>(maxDamage, fileName),
            parseUnsignedInt<uint16_t>(baseCost, fileName),
            restrictions
        };
    weapons[name] = weapon;
  }
  return weapons;
}

std::unordered_map<std::string, Armor> loadArmors(const char* fileName) {
  std::ifstream file(fileName);
  std::unordered_map<std::string, Armor> armors;
  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    std::stringstream strStream(line);
    std::string name;
    std::string baseCost;
    std::string armorClass;
    std::string equipable;
    std::string restrictions;
    std::getline(strStream, name, ',');
    std::getline(strStream, baseCost, ',');
    std::getline(strStream, armorClass, ',');
    std::getline(strStream, equipable, ',');
    std::getline(strStream, restrictions);
    Armor armor = {
            name,
            parseUnsignedInt<uint16_t>(baseCost, fileName),
            parseUnsignedInt<uint8_t>(armorClass, fileName),
            equipable,
            restrictions
        };
    armors[name] = armor;
  }
  return armors;
}

std::unordered_map<std::string, Accessory> loadAccessories(const char* fileName) {
  std::ifstream file(fileName);
  std::unordered_map<std::string, Accessory> accessories;
  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    std::stringstream strStream(line);
    std::string name;
    std::string baseCost;
    std::string qtyEquipable;
    std::getline(strStream, name, ',');
    std::getline(strStream, baseCost, ',');
    std::getline(strStream, qtyEquipable);
    Accessory accessory = {
            name,
            parseUnsignedInt<uint16_t>(baseCost, fileName),
            qtyEquipable
        };
    accessories[name] = accessory;
  }
  return accessories;
}

std::unordered_map<std::string, AttributeModifier> loadAttributeModifiers(const char* fileName) {
  std::ifstream file(fileName);
  std::unordered_map<std::string, AttributeModifier> attributeModifiers;
  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    std::stringstream strStream(line);
    std::string name;
    std::string type;
    std::string bonus;
    std::getline(strStream, name, ',');
    std::getline(strStream, type, ',');
    std::getline(strStream, bonus);
    AttributeModifier attributeModifier = {
            name,
            type,
            parseUnsignedInt<uint8_t>(bonus, fileName)
        };
    attributeModifiers[name] = attributeModifier;
  }
  return attributeModifiers;
}

std::unordered_map<std::string, ElementalModifier> loadElementalModifiers(const char* fileName) {
  std::ifstream file(fileName);
  std::string line;
  std::unordered_map<std::string, ElementalModifier> elementalModifiers;
  std::getline(file, line);
  while (std::getline(file, line)) {
    std::stringstream strStream(line);
    std::string type;
    std::string name;
    std::string resistance;
    std::string damage;
    std::getline(strStream, type, ',');
    std::getline(strStream, name, ',');
    std::getline(strStream, resistance, ',');
    std::getline(strStream, damage);
    ElementalModifier elementalModifier = {
            type,
            name,
            parseUnsignedInt<uint8_t>(resistance, fileName),
            parseUnsignedInt<uint8_t>(damage, fileName)
        };
    elementalModifiers[name] = elementalModifier;
  }
  return elementalModifiers;
}

std::unordered_map<std::string, MaterialModifier> loadMaterialModifiers(const char* fileName) {
  std::ifstream file(fileName);
  std::unordered_map<std::string, MaterialModifier> materialModifiers;
  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    std::stringstream strStream(line);
    std::string quality;
    std::string material;
    std::string toHitBonus;
    std::string damageBonus;
    std::string armorClassBonus;
    std::string costMultiplier;
    std::getline(strStream, quality, ',');
    std::getline(strStream, material, ',');
    std::getline(strStream, toHitBonus, ',');
    std::getline(strStream, damageBonus, ',');
    std::getline(strStream, armorClassBonus, ',');
    std::getline(strStream, costMultiplier);
    MaterialModifier materialModifier = { quality,
                                          material,
                                          parseInt(toHitBonus, fileName),
                                          parseInt(damageBonus, fileName),
                                          parseInt(armorClassBonus, fileName),
                                          parseFloat(costMultiplier, fileName) };
    materialModifiers[material] = materialModifier;
  }
  return materialModifiers;
}
