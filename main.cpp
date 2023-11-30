#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

const char* const RED = "\033[31m";      // Red
const char* const GREEN = "\033[32m";    // Green
const char* const YELLOW = "\033[33m";   // Yellow
const char* const BLUE = "\033[34m";     // Blue
const char* const MAGENTA = "\033[35m";  // Magenta
const char* const CYAN = "\033[36m";     // Cyan
const char* const RESET = "\033[0m";     // Reset to default color

struct Weapon {
    std::string name;
    int minDamage;
    int maxDamage;
    int baseCost;
    std::string restrictions;
};

struct Armor {
    std::string name;
    int baseCost;
    int armorClass;
    std::string equipable;
    std::string restrictions;
};

struct Accessories {
    std::string name;
    int baseCost;
    std::string qtyEquipable;
};

struct AttributeModifier {
    std::string name;
    std::string type;
    int bonus;
};

struct ElementalModifier {
    std::string type;
    std::string name;
    int resistance;
    int damage;
};

struct MaterialModifier {
    std::string quality;
    std::string material;
    int toHitBonus;
    int damageBonus;
    int armorClassBonus;
    float costMultiplier;
};

std::unordered_map<std::string, Weapon> loadWeapons() {
  std::ifstream file("weapons.csv");
  std::string line;
  std::unordered_map<std::string, Weapon> weapons;
  std::getline(file, line);  // skip header line
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
    try {
      std::stoi(minDamage);
      std::stoi(maxDamage);
      std::stoi(baseCost);
    } catch (const std::invalid_argument& e) {
      std::cout << RED << "Error: invalid argument in weapons.csv" << e.what() << RESET << std::endl;
      exit(1);
    }
    Weapon weapon = { name, std::stoi(minDamage), std::stoi(maxDamage), std::stoi(baseCost), restrictions };
    weapons[name] = weapon;
  }
  return weapons;
}

std::unordered_map<std::string, Armor> loadArmors() {
  std::ifstream file("armor.csv");
  std::unordered_map<std::string, Armor> armors;
  std::string line;
  std::getline(file, line);  // skip header line
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
    try {
      std::stoi(baseCost);
      std::stoi(armorClass);
    } catch (const std::invalid_argument& e) {
      std::cout << RED << "Error: invalid argument in armor.csv" << e.what() << RESET << std::endl;
      exit(1);
    }
    Armor armor = { name, std::stoi(baseCost), std::stoi(armorClass), equipable, restrictions };
    armors[name] = armor;
  }
  return armors;
}

std::unordered_map<std::string, Accessories> loadAccessories() {
  std::ifstream file("accessories.csv");
  std::unordered_map<std::string, Accessories> accessories;
  std::string line;
  std::getline(file, line);  // skip header line
  while (std::getline(file, line)) {
    std::stringstream strStream(line);
    std::string name;
    std::string baseCost;
    std::string qtyEquipable;
    std::getline(strStream, name, ',');
    std::getline(strStream, baseCost, ',');
    std::getline(strStream, qtyEquipable);
    try {
      std::stoi(baseCost);
    } catch (const std::invalid_argument& e) {
      std::cout << RED << "Error: invalid argument in accessories.csv" << e.what() << RESET << std::endl;
      exit(1);
    }
    Accessories accessory = { name, std::stoi(baseCost), qtyEquipable };
    accessories[name] = accessory;
  }
  return accessories;
}

std::unordered_map<std::string, AttributeModifier> loadAttributeModifiers() {
  std::ifstream file("attributes.csv");
  std::unordered_map<std::string, AttributeModifier> attributeModifiers;
  std::string line;
  std::getline(file, line);  // skip header line
  while (std::getline(file, line)) {
    std::stringstream strStream(line);
    std::string name;
    std::string type;
    std::string bonus;
    std::getline(strStream, name, ',');
    std::getline(strStream, type, ',');
    std::getline(strStream, bonus);
    try {
      std::stoi(bonus);
    } catch (const std::invalid_argument& e) {
      std::cout << RED << "Error: invalid argument in attributes.csv" << e.what() << RESET << std::endl;
      exit(1);
    }
    AttributeModifier attributeModifier = { name, type, std::stoi(bonus) };
    attributeModifiers[name] = attributeModifier;
  }
  return attributeModifiers;
}

std::unordered_map<std::string, ElementalModifier> loadElementalModifiers() {
  std::ifstream file("elements.csv");
  std::string line;
  std::unordered_map<std::string, ElementalModifier> elementalModifiers;
  std::getline(file, line);  // skip header line
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
    try {
      std::stoi(resistance);
      std::stoi(damage);
    } catch (const std::invalid_argument& e) {
      std::cout << RED << "Error: invalid argument in elements.csv" << e.what() << RESET << std::endl;
      exit(1);
    }
    ElementalModifier elementalModifier = { type, name, std::stoi(resistance), std::stoi(damage) };
    elementalModifiers[name] = elementalModifier;
  }
  return elementalModifiers;
}

std::unordered_map<std::string, MaterialModifier> loadMaterialModifiers() {
  std::ifstream file("materials.csv");
  std::unordered_map<std::string, MaterialModifier> materialModifiers;
  std::string line;
  std::getline(file, line);  // skip header line
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
    try {
      std::stoi(toHitBonus);
      std::stoi(damageBonus);
      std::stoi(armorClassBonus);
      std::stof(costMultiplier);
    } catch (const std::invalid_argument& e) {
      std::cout << RED << "Error: invalid argument in materials.csv" << e.what() << RESET << std::endl;
      exit(1);
    }
    MaterialModifier materialModifier = { quality,
                                          material,
                                          std::stoi(toHitBonus),
                                          std::stoi(damageBonus),
                                          std::stoi(armorClassBonus),
                                          std::stof(costMultiplier) };
    materialModifiers[material] = materialModifier;
  }
  return materialModifiers;
}

void printMaterialWeapon(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                         const std::string& material,
                         const std::unordered_map<std::string, Weapon>& weapons,
                         const std::string& weaponName) {
  auto weaponIt = weapons.find(weaponName);
  if (weaponIt == weapons.end()) {
    std::cout << RED << "Error: weapon " << weaponName << " not found" << RESET << std::endl;
    return;
  }
  const Weapon& weapon = weaponIt->second;

  auto materialIt = materialModifiers.find(material);
  if (materialIt == materialModifiers.end()) {
    std::cout << RED << "Error: material " << material << " not found" << RESET << std::endl;
    return;
  }
  const MaterialModifier& materialModifier = materialIt->second;

  std::cout << GREEN << "Name: " << materialModifier.material << " " << weapon.name << RESET << std::endl;
  std::cout << "Damage: " << weapon.minDamage + materialModifier.damageBonus << "-"
            << weapon.maxDamage + materialModifier.damageBonus << std::endl;
  std::cout << "Cost: "
            << static_cast<int>(std::round(static_cast<float>(weapon.baseCost) * materialModifier.costMultiplier))
            << std::endl;
  std::cout << "To Hit Bonus: +" << materialModifier.toHitBonus << std::endl;
  std::cout << "Restrictions: " << weapon.restrictions << std::endl;
}

void printElementalWeapon(const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                          const std::string& elemental,
                          const std::unordered_map<std::string, Weapon>& weapons,
                          const std::string& weaponName) {
  auto weaponIt = weapons.find(weaponName);
  if (weaponIt == weapons.end()) {
    std::cout << RED << "Error: weapon " << weaponName << " not found" << RESET << std::endl;
    return;
  }
  const Weapon& weapon = weaponIt->second;

  auto elementalIt = elementalModifiers.find(elemental);
  if (elementalIt == elementalModifiers.end()) {
    std::cout << RED << "Error: elemental " << elemental << " not found" << RESET << std::endl;
    return;
  }
  const ElementalModifier& elementalModifier = elementalIt->second;
  std::cout << GREEN << "Name: " << elementalModifier.name << " " << weapon.name << RESET << std::endl;
  std::cout << "Damage: " << weapon.minDamage << "-" << weapon.maxDamage << std::endl;
  std::cout << "Cost: " << weapon.baseCost << std::endl;
  std::cout << "Elemental Damage: " << elementalModifier.damage << " " << elementalModifier.type << " Damage"
            << std::endl;
  std::cout << "Total Damage: " << weapon.minDamage + elementalModifier.damage << "-"
            << weapon.maxDamage + elementalModifier.damage << std::endl;
  std::cout << "Restrictions: " << weapon.restrictions << std::endl;
}

void printAttributeWeapon(const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                          const std::string& attribute,
                          const std::unordered_map<std::string, Weapon>& weapons,
                          const std::string& weaponName) {
  auto weaponIt = weapons.find(weaponName);
  if (weaponIt == weapons.end()) {
    std::cout << RED << "Error: weapon " << weaponName << " not found" << RESET << std::endl;
    return;
  }
  const Weapon& weapon = weaponIt->second;

  auto attributeIt = attributeModifiers.find(attribute);
  if (attributeIt == attributeModifiers.end()) {
    std::cout << RED << "Error: attribute " << attribute << " not found" << RESET << std::endl;
    return;
  }
  const AttributeModifier& attributeModifier = attributeIt->second;
  std::cout << GREEN << "Name: " << attributeModifier.name << " " << weapon.name << RESET << std::endl;
  std::cout << "Damage: " << weapon.minDamage << "-" << weapon.maxDamage << std::endl;
  std::cout << "Cost: " << weapon.baseCost << std::endl;
  std::cout << "Attribute Bonus: +" << attributeModifier.bonus << " " << attributeModifier.type << std::endl;
  std::cout << "Restrictions: " << weapon.restrictions << std::endl;
}

void printMaterialArmor(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                        const std::string& material,
                        const std::unordered_map<std::string, Armor>& armors,
                        const std::string& armorName) {
  auto armorIt = armors.find(armorName);
  if (armorIt == armors.end()) {
    std::cout << RED << "Error: armor " << armorName << " not found" << RESET << std::endl;
    return;
  }
  const Armor& armor = armorIt->second;

  auto materialIt = materialModifiers.find(material);
  if (materialIt == materialModifiers.end()) {
    std::cout << RED << "Error: material " << material << " not found" << RESET << std::endl;
    return;
  }
  const MaterialModifier& materialModifier = materialIt->second;
  std::cout << GREEN << "Name: " << materialModifier.material << " " << armor.name << RESET << std::endl;
  std::cout << "Armor Class: " << armor.armorClass + materialModifier.armorClassBonus << std::endl;
  std::cout << "Cost: "
            << static_cast<int>(std::round(static_cast<float>(armor.baseCost) * materialModifier.costMultiplier))
            << std::endl;
  std::cout << "Restrictions: " << armor.restrictions << std::endl;
}

void printElementalArmor(const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                         const std::string& elemental,
                         const std::unordered_map<std::string, Armor>& armors,
                         const std::string& armorName) {
  auto armorIt = armors.find(armorName);
  if (armorIt == armors.end()) {
    std::cout << RED << "Error: armor " << armorName << " not found" << RESET << std::endl;
    return;
  }
  const Armor& armor = armorIt->second;

  auto elementalIt = elementalModifiers.find(elemental);
  if (elementalIt == elementalModifiers.end()) {
    std::cout << RED << "Error: elemental " << elemental << " not found" << RESET << std::endl;
    return;
  }
  const ElementalModifier& elementalModifier = elementalIt->second;
  std::cout << GREEN << "Name: " << elementalModifier.name << " " << armor.name << RESET << std::endl;
  std::cout << "Resistance: " << elementalModifier.resistance << "% " << elementalModifier.type << std::endl;
  std::cout << "Armor Class: " << armor.armorClass << std::endl;
  std::cout << "Cost: " << armor.baseCost << std::endl;
  std::cout << "Restrictions: " << armor.restrictions << std::endl;
}

void printAttributeArmor(const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                         const std::string& attribute,
                         const std::unordered_map<std::string, Armor>& armors,
                         const std::string& armorName) {
  auto armorIt = armors.find(armorName);
  if (armorIt == armors.end()) {
    std::cout << RED << "Error: armor " << armorName << " not found" << RESET << std::endl;
    return;
  }
  const Armor& armor = armorIt->second;

  auto attributeIt = attributeModifiers.find(attribute);
  if (attributeIt == attributeModifiers.end()) {
    std::cout << RED << "Error: attribute " << attribute << " not found" << RESET << std::endl;
    return;
  }
  const AttributeModifier& attributeModifier = attributeIt->second;
  std::cout << GREEN << "Name: " << attributeModifier.name << " " << armor.name << RESET << std::endl;
  std::cout << "Bonus: +" << attributeModifier.bonus << " " << attributeModifier.type << std::endl;
  attributeModifier.type == "AC"
    ? std::cout << "Armor Class: " << armor.armorClass + attributeModifier.bonus << std::endl
    : std::cout << "Armor Class: " << armor.armorClass << std::endl;
  std::cout << "Cost: " << armor.baseCost << std::endl;
  std::cout << "Restrictions: " << armor.restrictions << std::endl;
}

void printMaterialAccessory(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                            const std::string& material,
                            const std::unordered_map<std::string, Accessories>& accessories,
                            const std::string& accessoryName) {
  auto accessoryIt = accessories.find(accessoryName);
  if (accessoryIt == accessories.end()) {
    std::cout << RED << "Error: accessory " << accessoryName << " not found" << RESET << std::endl;
    return;
  }
  const Accessories& accessory = accessoryIt->second;

  auto materialIt = materialModifiers.find(material);
  if (materialIt == materialModifiers.end()) {
    std::cout << RED << "Error: material " << material << " not found" << RESET << std::endl;
    return;
  }
  const MaterialModifier& materialModifier = materialIt->second;
  std::cout << GREEN << "Name: " << materialModifier.quality << " " << materialModifier.material << " "
            << accessory.name << RESET << std::endl;
  std::cout << "Cost: " << (float) accessory.baseCost * materialModifier.costMultiplier << std::endl;
  std::cout << "Cost: "
            << static_cast<int>(std::round(static_cast<float>(accessory.baseCost) * materialModifier.costMultiplier))
            << std::endl;
  std::cout << "Qty Equipable: " << accessory.qtyEquipable << std::endl;
}

void printElementalAccessory(const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                             const std::string& elemental,
                             const std::unordered_map<std::string, Accessories>& accessories,
                             const std::string& accessoryName) {
  auto accessoryIt = accessories.find(accessoryName);
  if (accessoryIt == accessories.end()) {
    std::cout << RED << "Error: accessory " << accessoryName << " not found" << RESET << std::endl;
    return;
  }
  const Accessories& accessory = accessoryIt->second;

  auto elementalIt = elementalModifiers.find(elemental);
  if (elementalIt == elementalModifiers.end()) {
    std::cout << RED << "Error: elemental " << elemental << " not found" << RESET << std::endl;
    return;
  }
  const ElementalModifier& elementalModifier = elementalIt->second;
  std::cout << GREEN << "Name: " << elementalModifier.name << " " << accessory.name << RESET << std::endl;
  std::cout << "Bonus: +" << elementalModifier.resistance << " " << elementalModifier.type << std::endl;
  std::cout << "Cost: " << accessory.baseCost << std::endl;
  std::cout << "Qty Equipable: " << accessory.qtyEquipable << std::endl;
}

void printAttributeAccessory(const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                             const std::string& attribute,
                             const std::unordered_map<std::string, Accessories>& accessories,
                             const std::string& accessoryName) {
  auto accessoryIt = accessories.find(accessoryName);
  if (accessoryIt == accessories.end()) {
    std::cout << RED << "Error: accessory " << accessoryName << " not found" << RESET << std::endl;
    return;
  }
  const Accessories& accessory = accessoryIt->second;

  auto attributeIt = attributeModifiers.find(attribute);
  if (attributeIt == attributeModifiers.end()) {
    std::cout << RED << "Error: attribute " << attribute << " not found" << RESET << std::endl;
    return;
  }
  const AttributeModifier& attributeModifier = attributeIt->second;
  std::cout << GREEN << "Name: " << attributeModifier.name << " " << accessory.name << RESET << std::endl;
  std::cout << "Bonus: +" << attributeModifier.bonus << " " << attributeModifier.type << std::endl;
  std::cout << "Cost: " << accessory.baseCost << std::endl;
  std::cout << "Qty Equipable: " << accessory.qtyEquipable << std::endl;
}

void trim(std::string& str) {
  str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char glyph) {
              return std::isspace(glyph) == 0;
            }));
  str.erase(std::find_if(str.rbegin(),
                         str.rend(),
                         [](unsigned char glyph) {
                           return std::isspace(glyph) == 0;
                         })
              .base(),
            str.end());
}

void printWeapon(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                 const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                 const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                 const std::string& modifier,
                 const std::unordered_map<std::string, Weapon>& weapons,
                 const std::string& itemName) {
  if (materialModifiers.find(modifier) != materialModifiers.end()) {
    printMaterialWeapon(materialModifiers, modifier, weapons, itemName);
  } else if (elementalModifiers.find(modifier) != elementalModifiers.end()) {
    printElementalWeapon(elementalModifiers, modifier, weapons, itemName);
  } else if (attributeModifiers.find(modifier) != attributeModifiers.end()) {
    printAttributeWeapon(attributeModifiers, modifier, weapons, itemName);
  } else {
    std::cout << "Modifier not found." << std::endl;
  }
}

void printArmor(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                const std::string& modifier,
                const std::unordered_map<std::string, Armor>& armors,
                const std::string& itemName) {
  if (materialModifiers.find(modifier) != materialModifiers.end()) {
    printMaterialArmor(materialModifiers, modifier, armors, itemName);
  } else if (elementalModifiers.find(modifier) != elementalModifiers.end()) {
    printElementalArmor(elementalModifiers, modifier, armors, itemName);
  } else if (attributeModifiers.find(modifier) != attributeModifiers.end()) {
    printAttributeArmor(attributeModifiers, modifier, armors, itemName);
  } else {
    std::cout << "Modifier not found." << std::endl;
  }
}

void printAccessory(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                    const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                    const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                    const std::string& modifier,
                    const std::unordered_map<std::string, Accessories>& accessories,
                    const std::string& itemName) {
  if (materialModifiers.find(modifier) != materialModifiers.end()) {
    printMaterialAccessory(materialModifiers, modifier, accessories, itemName);
  } else if (elementalModifiers.find(modifier) != elementalModifiers.end()) {
    printElementalAccessory(elementalModifiers, modifier, accessories, itemName);
  } else if (attributeModifiers.find(modifier) != attributeModifiers.end()) {
    printAttributeAccessory(attributeModifiers, modifier, accessories, itemName);
  } else {
    std::cout << "Modifier not found." << std::endl;
  }
}

void processItem(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                 const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                 const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                 const std::string& modifier,
                 const std::unordered_map<std::string, Weapon>& weapons,
                 const std::unordered_map<std::string, Armor>& armors,
                 const std::unordered_map<std::string, Accessories>& accessories,
                 const std::string& itemName) {
  if (weapons.find(itemName) != weapons.end()) {
    printWeapon(materialModifiers, elementalModifiers, attributeModifiers, modifier, weapons, itemName);
  } else if (armors.find(itemName) != armors.end()) {
    printArmor(materialModifiers, elementalModifiers, attributeModifiers, modifier, armors, itemName);
  } else if (accessories.find(itemName) != accessories.end()) {
    printAccessory(materialModifiers, elementalModifiers, attributeModifiers, modifier, accessories, itemName);
  } else {
    std::cout << "Item not found." << std::endl;
  }
}

bool getInput(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
              const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
              const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
              const std::unordered_map<std::string, Weapon>& weapons,
              const std::unordered_map<std::string, Armor>& armors,
              const std::unordered_map<std::string, Accessories>& accessories) {
  std::string input;
  std::cout << YELLOW << "Enter an item with a modifier, or q/Q/exit/quit to quit: " << RESET;
  std::getline(std::cin, input);

  std::string lowerInput = input;
  std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), [](unsigned char glyph) {
    return std::tolower(glyph);
  });
  if (lowerInput == "q" || lowerInput == "quit" || lowerInput == "exit") {
    return false;
  }

  std::istringstream iss(input);
  std::string modifier;
  std::string itemName;
  iss >> modifier;
  std::getline(iss, itemName, '\n');
  trim(itemName);

  processItem(
    materialModifiers, elementalModifiers, attributeModifiers, modifier, weapons, armors, accessories, itemName);
  return true;
}

int main() {
  const std::unordered_map<std::string, Weapon> weapons = loadWeapons();
  const std::unordered_map<std::string, Armor> armors = loadArmors();
  const std::unordered_map<std::string, Accessories> accessories = loadAccessories();
  const std::unordered_map<std::string, MaterialModifier> materialModifiers = loadMaterialModifiers();
  const std::unordered_map<std::string, ElementalModifier> elementalModifiers = loadElementalModifiers();
  const std::unordered_map<std::string, AttributeModifier> attributeModifiers = loadAttributeModifiers();
  while (getInput(materialModifiers, elementalModifiers, attributeModifiers, weapons, armors, accessories)) {}
  std::cout << "Exiting..." << std::endl;
  return 0;
}
