#ifndef HEADER_CONSOLE_HPP
#define HEADER_CONSOLE_HPP

#include <string>
#include <unordered_map>

#include "items.hpp"

const char* const RED = "\033[31m";      // Red
const char* const GREEN = "\033[32m";    // Green
const char* const YELLOW = "\033[33m";   // Yellow
const char* const BLUE = "\033[34m";     // Blue
const char* const MAGENTA = "\033[35m";  // Magenta
const char* const CYAN = "\033[36m";     // Cyan
const char* const RESET = "\033[0m";     // Reset to default color

void printMaterialWeapon(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                         const std::string& material,
                         const std::unordered_map<std::string, Weapon>& weapons,
                         const std::string& weaponName);

void printElementalWeapon(const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                          const std::string& elemental,
                          const std::unordered_map<std::string, Weapon>& weapons,
                          const std::string& weaponName);

void printAttributeWeapon(const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                          const std::string& attribute,
                          const std::unordered_map<std::string, Weapon>& weapons,
                          const std::string& weaponName);

void printMaterialArmor(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                        const std::string& material,
                        const std::unordered_map<std::string, Armor>& armors,
                        const std::string& armorName);

void printElementalArmor(const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                         const std::string& elemental,
                         const std::unordered_map<std::string, Armor>& armors,
                         const std::string& armorName);

void printAttributeArmor(const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                         const std::string& attribute,
                         const std::unordered_map<std::string, Armor>& armors,
                         const std::string& armorName);

void printMaterialAccessory(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                            const std::string& material,
                            const std::unordered_map<std::string, Accessory>& accessories,
                            const std::string& accessoryName);

void printElementalAccessory(const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                             const std::string& elemental,
                             const std::unordered_map<std::string, Accessory>& accessories,
                             const std::string& accessoryName);

void printAttributeAccessory(const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                             const std::string& attribute,
                             const std::unordered_map<std::string, Accessory>& accessories,
                             const std::string& accessoryName);

void trim(std::string& str);

void printWeapon(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                 const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                 const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                 const std::string& modifier,
                 const std::unordered_map<std::string, Weapon>& weapons,
                 const std::string& itemName);

void printArmor(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                const std::string& modifier,
                const std::unordered_map<std::string, Armor>& armors,
                const std::string& itemName);

void printAccessory(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                    const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                    const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                    const std::string& modifier,
                    const std::unordered_map<std::string, Accessory>& accessories,
                    const std::string& itemName);

void processItem(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
                 const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
                 const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
                 const std::string& modifier,
                 const std::unordered_map<std::string, Weapon>& weapons,
                 const std::unordered_map<std::string, Armor>& armors,
                 const std::unordered_map<std::string, Accessory>& accessories,
                 const std::string& itemName);

bool getInput(const std::unordered_map<std::string, MaterialModifier>& materialModifiers,
              const std::unordered_map<std::string, ElementalModifier>& elementalModifiers,
              const std::unordered_map<std::string, AttributeModifier>& attributeModifiers,
              const std::unordered_map<std::string, Weapon>& weapons,
              const std::unordered_map<std::string, Armor>& armors,
              const std::unordered_map<std::string, Accessory>& accessories);

#endif // HEADER_CONSOLE_HPP
