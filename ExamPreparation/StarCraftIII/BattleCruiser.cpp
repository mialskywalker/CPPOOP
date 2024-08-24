//
// Created by uchih on 24/08/2024.
//
#include "BattleCruser.h"
#include "others.h"

BattleCruser::BattleCruser(const AirShipType type, const int health, const int damage, const int shipId)
    : TerranAirShip(type, health, damage, shipId) {}

void BattleCruser::dealDamage(std::vector<std::unique_ptr<AirShip> > &enemyFleet) {
    int damage = _damage;
    if (_passedTurns % (YAMATO_CANNON_LOADING_TIME + 1) == 0)
        damage *= 5;

    doDamage(this, enemyFleet, damage);
}

