//
// Created by uchih on 19/08/2024.
//
#include "Glock.h"
#include <iostream>

Glock::Glock(const int damagePerRound, const int clipSize, const int remainingAmmo)
    : Pistol(damagePerRound, clipSize, remainingAmmo) {}

// virtual
bool Glock::fire(PlayerVitalData &enemyPlayerData) {

    int healthDamage = _damagePerRound / 2;
    int armorDamage = _damagePerRound / 2;

    for (int curShot = 0; curShot < ROUNDS_PER_FIRE && enemyPlayerData.health > 0; curShot++) {
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
    }

    return enemyPlayerData.health <= 0;
}
