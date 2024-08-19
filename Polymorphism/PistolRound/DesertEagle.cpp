//
// Created by uchih on 19/08/2024.
//
#include "DesertEagle.h"
#include <iostream>

DesertEagle::DesertEagle(const int damagePerRound, const int clipSize, const int remainingAmmo)
    : Pistol(damagePerRound, clipSize, remainingAmmo) {}

// virtual
bool DesertEagle::fire(PlayerVitalData &enemyPlayerData) {

    int healthDamage = 3*(_damagePerRound / 4);
    int armorDamage = _damagePerRound / 4;

    if (_currClipBullets <= 0) {
        reload();
        return false;
    }

    _currClipBullets--;

    enemyPlayerData.armor -= armorDamage;

    if (enemyPlayerData.armor < 0) {
        enemyPlayerData.health += enemyPlayerData.armor;
        enemyPlayerData.armor = 0;
    }

    enemyPlayerData.health -= healthDamage;

    std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor" << std::endl;

    return enemyPlayerData.health <= 0;
}

