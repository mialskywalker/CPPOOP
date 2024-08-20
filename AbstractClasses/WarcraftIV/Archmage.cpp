//
// Created by uchih on 20/08/2024.
//
#include "Archmage.h"
#include <string>
#include <iostream>

using namespace std;


Archmage::Archmage(const std::string & name, const int maxMana, const int baseManaRegenRate, const int manaRegenModifier)
:Hero(name, maxMana,baseManaRegenRate), _manaRegenModifier(manaRegenModifier) {};

//virtual
void Archmage::castSpell(const SpellType spell) {
    Spell & sp=_spells[spell];

    if (_currMana>=sp.manaCost) {
        //we can cast the spell;
        //show the text
        cout<<_name<<" casted "<<sp.name<<" for "<<sp.manaCost<<" mana"<<endl;
        _currMana-=sp.manaCost;

        if (spell==SpellType::ULTIMATE) {
            regenerateMana();
        };
    }
    else {
        //can't cast spell, not enough mana
        cout<<_name<<" - not enough mana to cast "<<sp.name<<endl;
    };
};


//virtual
void Archmage::regenerateMana() {
    _currMana+=(_manaRegenRate*_manaRegenModifier);
    if (_currMana>_maxMana) {
        _currMana=_maxMana;
    };
};
