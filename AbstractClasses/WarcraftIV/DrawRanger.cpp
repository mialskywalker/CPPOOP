//
// Created by uchih on 20/08/2024.
//
#include <string>
#include <iostream>

#include "DrawRanger.h"

using namespace std;

DrawRanger::DrawRanger(const std::string & name, const int maxMana, const int baseManaRegenRate)
: Hero(name, maxMana, baseManaRegenRate) {};

//virtual
void DrawRanger::castSpell(const SpellType spell) {
    Spell & sp=_spells[spell];

    if (_currMana>=sp.manaCost) {
        //we can cast the spell;
        //show the text
        cout<<_name<<" casted "<<sp.name<<" for "<<sp.manaCost<<" mana"<<endl;
        _currMana-=sp.manaCost;

        if (spell==SpellType::BASIC) {
            cout<<_name<<" casted "<<_spells[SpellType::BASIC].name<<" for 0 mana"<<endl;
        };
    }
    else {
        //can't cast spell, not enough mana
        cout<<_name<<" - not enough mana to cast "<<sp.name<<endl;
    };
};

//virtual
void DrawRanger::regenerateMana() {
    _currMana+=_manaRegenRate;
    if (_currMana>_maxMana) {
        _currMana=_maxMana;
    };
};
