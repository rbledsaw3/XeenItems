#ifndef _SRC_ITEM_HPP_
#define _SRC_ITEM_HPP_

#include <iostream>
#include <string>

class Item {
  public:
    Item(const Item&) = default;
    Item(Item&&) = delete;
    Item& operator=(const Item&) = default;
    Item& operator=(Item&&) = delete;

    std::string name;
    int baseCost;

    virtual ~Item() = default;
    virtual void display() const = 0;
};

class Weapon : public Item {
  public:
    int minDamage;
    int maxDamage;
    std::string restrictions;

    void display() const override {
      std::cout << "Weapon: " << name << "\n";
      std::cout << "Base Cost: " << baseCost << "\n";
      std::cout << "Damage: " << minDamage << " - " << maxDamage << "\n";
      std::cout << "Restrictions: " << restrictions << "\n";
    }
};

class Armor : public Item {
  public:
    int armorClass;
    std::string equipable;
    std::string restrictions;

    void display() const override {
      std::cout << "Armor: " << name << "\n";
      std::cout << "Base Cost: " << baseCost << "\n";
      std::cout << "Armor Class: " << armorClass << "\n";
      std::cout << "Equipable: " << equipable << "\n";
      std::cout << "Restrictions: " << restrictions << "\n";
    }
};

#endif  // _SRC_ITEM_HPP_
