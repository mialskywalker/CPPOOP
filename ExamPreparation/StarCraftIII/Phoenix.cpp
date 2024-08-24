//
// Created by uchih on 24/08/2024.
//
#include "Phoenix.h"
#include <iostream>

#include "others.h"

Phoenix::Phoenix(const AirShipType type, const int health, const int damage, const int maxShield, const int shieldRegenerateRate, const int shipId)
    : ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId) {}

void Phoenix::dealDamage(std::vector<std::unique_ptr<AirShip> > &enemyFleet) {
    doDamage(this, enemyFleet, _damage);
}

