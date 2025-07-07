#ifndef HEADER_DATA_LOADER_HPP
#define HEADER_DATA_LOADER_HPP

#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_map>

#include "console.hpp"
#include "items.hpp"


template <typename T>
T parseUnsignedInt(const std::string& str, const char* fileName) {
    static_assert(std::is_unsigned_v<T> &&
                    std::is_integral_v<T>,
                    "T must be an unsigned integral type");
    try {
        size_t idx = 0;
        unsigned long long value = std::stoull(str, &idx, 0);
        if (idx != str.size()) {
            std::cerr << RED << "Error: Extra characters after number in " <<
                fileName << ": " << str << RESET << "'\n";
            exit(1);
        }
        if (value > std::numeric_limits<T>::max()) {
            std::cerr << RED << "Error: Value out of range for type in " <<
                fileName << ": " << str << RESET << "'\n";
            exit(1);
        }
        return static_cast<T>(value);
    } catch (const std::invalid_argument& e) {
        std::cerr << RED << "Error: Invalid argument in " << fileName << ": " << e.what() << RESET << "\n";
        exit(1);
    } catch (const std::out_of_range& e) {
        std::cerr << RED << "Error: Out of range in " << fileName << ": " << e.what() << RESET << "\n";
        exit(1);
    }
}

int parseInt(const std::string& str, const char* fileName);

float parseFloat(const std::string& str, const char* fileName);

std::unordered_map<std::string, Weapon> loadWeapons(const char* fileName = "data/weapons.csv");

std::unordered_map<std::string, Armor> loadArmors(const char* fileName = "data/armor.csv");

std::unordered_map<std::string, Accessory> loadAccessories(const char* fileName = "data/accessories.csv");

std::unordered_map<std::string, AttributeModifier> loadAttributeModifiers(const char* fileName = "data/attributes.csv");

std::unordered_map<std::string, ElementalModifier> loadElementalModifiers(const char* fileName = "data/elements.csv");

std::unordered_map<std::string, MaterialModifier> loadMaterialModifiers(const char* fileName = "data/materials.csv");

#endif // HEADER_DATA_LOADER_HPP
