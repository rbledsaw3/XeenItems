#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

const char* RED = "\033[31m";      // Red
const char* GREEN = "\033[32m";    // Green
const char* YELLOW = "\033[33m";   // Yellow
const char* BLUE = "\033[34m";     // Blue
const char* MAGENTA = "\033[35m";  // Magenta
const char* CYAN = "\033[36m";     // Cyan
const char* RESET = "\033[0m";     // Reset to default color

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

std::unordered_map<std::string, Weapon> weapons;
std::unordered_map<std::string, Armor> armors;
std::unordered_map<std::string, Accessories> accessories;
std::unordered_map<std::string, AttributeModifier> attributeModifiers;
std::unordered_map<std::string, ElementalModifier> elementalModifiers;
std::unordered_map<std::string, MaterialModifier> materialModifiers;

void loadWeapons() {
    std::ifstream file("weapons.csv");
    std::string line;
    std::getline(file, line); // skip header line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, minDamage, maxDamage, baseCost, restrictions;
        std::getline(ss, name, ',');
        std::getline(ss, minDamage, ',');
        std::getline(ss, maxDamage, ',');
        std::getline(ss, baseCost, ',');
        std::getline(ss, restrictions);
        try {
            std::stoi(minDamage);
            std::stoi(maxDamage);
            std::stoi(baseCost);
        } catch (const std::invalid_argument &e) {
            std::cout << RED << "Error: invalid argument in weapons.csv" << e.what() << RESET << std::endl;
            exit(1);
        }
        Weapon weapon = {name, std::stoi(minDamage), std::stoi(maxDamage), std::stoi(baseCost), restrictions};
        weapons[name] = weapon;
    }
}

void loadArmors() {
    std::ifstream file("armor.csv");
    std::string line;
    std::getline(file, line); // skip header line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, baseCost, armorClass, equipable, restrictions;
        std::getline(ss, name, ',');
        std::getline(ss, baseCost, ',');
        std::getline(ss, armorClass, ',');
        std::getline(ss, equipable, ',');
        std::getline(ss, restrictions);
        try {
            std::stoi(baseCost);
            std::stoi(armorClass);
        } catch (const std::invalid_argument &e) {
            std::cout << RED << "Error: invalid argument in armor.csv" << e.what() << RESET << std::endl;
            exit(1);
        }
        Armor armor = {name, std::stoi(baseCost), std::stoi(armorClass), equipable, restrictions};
        armors[name] = armor;
    }
}

void loadAccessories() {
    std::ifstream file("accessories.csv");
    std::string line;
    std::getline(file, line); // skip header line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, baseCost, qtyEquipable;
        std::getline(ss, name, ',');
        std::getline(ss, baseCost, ',');
        std::getline(ss, qtyEquipable);
        try {
            std::stoi(baseCost);
        } catch (const std::invalid_argument &e) {
            std::cout << RED << "Error: invalid argument in accessories.csv" << e.what() << RESET << std::endl;
            exit(1);
        }
        Accessories accessory = {name, std::stoi(baseCost), qtyEquipable};
        accessories[name] = accessory;
    }
}

void loadAttributeModifiers() {
    std::ifstream file("attributes.csv");
    std::string line;
    std::getline(file, line); // skip header line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, type, bonus;
        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, bonus);
        try {
            std::stoi(bonus);
        } catch (const std::invalid_argument &e) {
            std::cout << RED << "Error: invalid argument in attributes.csv" << e.what() << RESET << std::endl;
            exit(1);
        }
        AttributeModifier attributeModifier = {name, type, std::stoi(bonus)};
        attributeModifiers[name] = attributeModifier;
    }
}

void loadElementalModifiers() {
    std::ifstream file("elements.csv");
    std::string line;
    std::getline(file, line); // skip header line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string type, name, resistance, damage;
        std::getline(ss, type, ',');
        std::getline(ss, name, ',');
        std::getline(ss, resistance, ',');
        std::getline(ss, damage);
        try {
            std::stoi(resistance);
            std::stoi(damage);
        } catch (const std::invalid_argument &e) {
            std::cout << RED << "Error: invalid argument in elements.csv" << e.what() << RESET << std::endl;
            exit(1);
        }
        ElementalModifier elementalModifier = {type, name, std::stoi(resistance), std::stoi(damage)};
        elementalModifiers[name] = elementalModifier;
    }
}

void loadMaterialModifiers() {
    std::ifstream file("materials.csv");
    std::string line;
    std::getline(file, line); // skip header line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string quality, material, toHitBonus, damageBonus, armorClassBonus, costMultiplier;
        std::getline(ss, quality, ',');
        std::getline(ss, material, ',');
        std::getline(ss, toHitBonus, ',');
        std::getline(ss, damageBonus, ',');
        std::getline(ss, armorClassBonus, ',');
        std::getline(ss, costMultiplier);
        try {
            std::stoi(toHitBonus);
            std::stoi(damageBonus);
            std::stoi(armorClassBonus);
            std::stof(costMultiplier);
        } catch (const std::invalid_argument &e) {
            std::cout << RED << "Error: invalid argument in materials.csv" << e.what() << RESET << std::endl;
            exit(1);
        }
        MaterialModifier materialModifier = {quality, material, std::stoi(toHitBonus), std::stoi(damageBonus), std::stoi(armorClassBonus), std::stof(costMultiplier)};
        materialModifiers[material] = materialModifier;
    }
}

void readCSVs() {
    loadWeapons();
    loadArmors();
    loadAccessories();
    loadAttributeModifiers();
    loadElementalModifiers();
    loadMaterialModifiers();
}

void processItem(const std::string &modifier, const std::string &itemName);
void trim(std::string &str);

void printMaterialWeapon(std::string material, std::string weaponName) {
    Weapon weapon = weapons[weaponName];
    MaterialModifier materialModifier = materialModifiers[material];
    std::cout << GREEN << "Name: " << materialModifier.material << " " << weapon.name << RESET << std::endl;
    std::cout << "Damage: " << weapon.minDamage + materialModifier.damageBonus << "-" << weapon.maxDamage + materialModifier.damageBonus << std::endl;
    std::cout << "Cost: " << weapon.baseCost * materialModifier.costMultiplier << std::endl;
    std::cout << "To Hit Bonus: +" << materialModifier.toHitBonus << std::endl;
    std::cout << "Restrictions: " << weapon.restrictions << std::endl;
}

void printElementalWeapon(std::string elemental, std::string weaponName) {
    Weapon weapon = weapons[weaponName];
    ElementalModifier elementalModifier = elementalModifiers[elemental];
    std::cout << GREEN << "Name: " << elementalModifier.name << " " << weapon.name << RESET << std::endl;
    std::cout << "Damage: " << weapon.minDamage << "-" << weapon.maxDamage << std::endl;
    std::cout << "Cost: " << weapon.baseCost << std::endl;
    std::cout << "Elemental Damage: " << elementalModifier.damage << " " << elementalModifier.type << " Damage" << std::endl;
    std::cout << "Total Damage: " << weapon.minDamage + elementalModifier.damage << "-" << weapon.maxDamage + elementalModifier.damage << std::endl;
    std::cout << "Restrictions: " << weapon.restrictions << std::endl;
}

void printAttributeWeapon(std::string attribute, std::string weaponName) {
    Weapon weapon = weapons[weaponName];
    AttributeModifier attributeModifier = attributeModifiers[attribute];
    std::cout << GREEN << "Name: " << attributeModifier.name << " " << weapon.name << RESET << std::endl;
    std::cout << "Damage: " << weapon.minDamage << "-" << weapon.maxDamage << std::endl;
    std::cout << "Cost: " << weapon.baseCost << std::endl;
    std::cout << "Attribute Bonus: +" << attributeModifier.bonus << " " << attributeModifier.type << std::endl;
    std::cout << "Restrictions: " << weapon.restrictions << std::endl;
}

void printMaterialArmor(std::string material, std::string armorName) {
    Armor armor = armors[armorName];
    MaterialModifier materialModifier = materialModifiers[material];
    std::cout << GREEN << "Name: " << materialModifier.material << " " << armor.name << RESET << std::endl;
    std::cout << "Armor Class: " << armor.armorClass + materialModifier.armorClassBonus << std::endl;
    std::cout << "Cost: " << armor.baseCost * materialModifier.costMultiplier << std::endl;
    std::cout << "Restrictions: " << armor.restrictions << std::endl;
}

void printElementalArmor(std::string elemental, std::string armorName) {
    Armor armor = armors[armorName];
    ElementalModifier elementalModifier = elementalModifiers[elemental];
    std::cout << GREEN << "Name: " << elementalModifier.name << " " << armor.name << RESET << std::endl;
    std::cout << "Resistance: " << elementalModifier.resistance << "% " << elementalModifier.type << std::endl;
    std::cout << "Armor Class: " << armor.armorClass << std::endl;
    std::cout << "Cost: " << armor.baseCost << std::endl;
    std::cout << "Restrictions: " << armor.restrictions << std::endl;
}

void printAttributeArmor(std::string attribute, std::string armorName) {
    Armor armor = armors[armorName];
    AttributeModifier attributeModifier = attributeModifiers[attribute];
    std::cout << GREEN << "Name: " << attributeModifier.name << " " << armor.name << RESET << std::endl;
    std::cout << "Bonus: +" << attributeModifier.bonus << " " << attributeModifier.type << std::endl;
    attributeModifier.type == "AC" ? 
        std::cout << "Armor Class: " << armor.armorClass + attributeModifier.bonus << std::endl :
        std::cout << "Armor Class: " << armor.armorClass << std::endl;
    std::cout << "Cost: " << armor.baseCost << std::endl;
    std::cout << "Restrictions: " << armor.restrictions << std::endl;
}

void printMaterialAccessory(std::string material, std::string accessoryName) {
    Accessories accessory = accessories[accessoryName];
    MaterialModifier materialModifier = materialModifiers[material];
    std::cout << GREEN << "Name: " << materialModifier.quality << " " << materialModifier.material << " " << accessory.name << RESET << std::endl;
    std::cout << "Cost: " << accessory.baseCost * materialModifier.costMultiplier << std::endl;
    std::cout << "Qty Equipable: " << accessory.qtyEquipable << std::endl;
}

void printElementalAccessory(std::string elemental, std::string accessoryName) {
    Accessories accessory = accessories[accessoryName];
    ElementalModifier elementalModifier = elementalModifiers[elemental];
    std::cout << GREEN << "Name: " << elementalModifier.name << " " << accessory.name << RESET << std::endl;
    std::cout << "Bonus: +" << elementalModifier.resistance << " " << elementalModifier.type << std::endl;
    std::cout << "Cost: " << accessory.baseCost << std::endl;
    std::cout << "Qty Equipable: " << accessory.qtyEquipable << std::endl;
}

void printAttributeAccessory(std::string attribute, std::string accessoryName) {
    Accessories accessory = accessories[accessoryName];
    AttributeModifier attributeModifier = attributeModifiers[attribute];
    std::cout << GREEN << "Name: " << attributeModifier.name << " " << accessory.name << RESET << std::endl;
    std::cout << "Bonus: +" << attributeModifier.bonus << " " << attributeModifier.type << std::endl;
    std::cout << "Cost: " << accessory.baseCost << std::endl;
    std::cout << "Qty Equipable: " << accessory.qtyEquipable << std::endl;
}

void trim(std::string& str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}

void printWeapon(const std::string& modifier, const std::string &itemName) {
    if (materialModifiers.find(modifier) != materialModifiers.end()) {
        printMaterialWeapon(modifier, itemName);
    } else if (elementalModifiers.find(modifier) != elementalModifiers.end()) {
        printElementalWeapon(modifier, itemName);
    } else if (attributeModifiers.find(modifier) != attributeModifiers.end()) {
        printAttributeWeapon(modifier, itemName);
    } else {
        std::cout << "Modifier not found." << std::endl;
    }
}

void printArmor(const std::string& modifier, const std::string &itemName) {
    if (materialModifiers.find(modifier) != materialModifiers.end()) {
        printMaterialArmor(modifier, itemName);
    } else if (elementalModifiers.find(modifier) != elementalModifiers.end()) {
        printElementalArmor(modifier, itemName);
    } else if (attributeModifiers.find(modifier) != attributeModifiers.end()) {
        printAttributeArmor(modifier, itemName);
    } else {
        std::cout << "Modifier not found." << std::endl;
    }
}

void printAccessory(const std::string& modifier, const std::string &itemName) {
    if (materialModifiers.find(modifier) != materialModifiers.end()) {
        printMaterialAccessory(modifier, itemName);
    } else if (elementalModifiers.find(modifier) != elementalModifiers.end()) {
        printElementalAccessory(modifier, itemName);
    } else if (attributeModifiers.find(modifier) != attributeModifiers.end()) {
        printAttributeAccessory(modifier, itemName);
    } else {
        std::cout << "Modifier not found." << std::endl;
    }
}

void processItem(const std::string& modifier, const std::string &itemName) {
    if (weapons.find(itemName) != weapons.end()) {
        printWeapon(modifier, itemName);
    } else if (armors.find(itemName) != armors.end()) {
        printArmor(modifier, itemName);
    } else if (accessories.find(itemName) != accessories.end()) {
        printAccessory(modifier, itemName);
    } else {
        std::cout << "Item not found." << std::endl;
    }
}

bool getInput() {
    std::string input;
    std::cout << YELLOW << "Enter an item with a modifier, or q/Q/exit/quit to quit: " << RESET;
    std::getline(std::cin, input);

    std::string lowerInput = input;
    std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(),
            [](unsigned char c) {return std::tolower(c); });
    if (lowerInput == "q" || lowerInput == "quit" || lowerInput == "exit") {
        return false;
    }

    std::istringstream iss(input);
    std::string modifier, itemName;
    iss >> modifier;
    std::getline(iss, itemName, '\n');
    trim(itemName);

    processItem(modifier, itemName);
    return true;
}

int main () {
    readCSVs();
    while (getInput()){}
    std::cout << "Exiting..." << std::endl;
    return 0;

}
