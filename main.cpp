#include <iostream>

#include "data_loader.hpp"

int main() {
  const std::unordered_map<std::string, Weapon> weapons = loadWeapons();
  const std::unordered_map<std::string, Armor> armors = loadArmors();
  const std::unordered_map<std::string, Accessory> accessories = loadAccessories();
  const std::unordered_map<std::string, MaterialModifier> materialModifiers = loadMaterialModifiers();
  const std::unordered_map<std::string, ElementalModifier> elementalModifiers = loadElementalModifiers();
  const std::unordered_map<std::string, AttributeModifier> attributeModifiers = loadAttributeModifiers();
  while (getInput(materialModifiers, elementalModifiers, attributeModifiers, weapons, armors, accessories)) {}
  std::cout << "Exiting..." << "\n";
  return 0;
}
