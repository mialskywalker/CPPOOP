//
// Created by uchih on 24/08/2024.
//
#include "TerranAirShip.h"

TerranAirShip::TerranAirShip(const AirShipType type, const int maxHealth, const int damage, const int shipId)
    : AirShip(type, maxHealth, damage, shipId), _passedTurns(1) {}

void TerranAirShip::takeDamage(const int damage) {
    _currHealth -= damage;
    if (_currHealth < 0)
        _currHealth = 0;
}

void TerranAirShip::finishTurn() {
    _passedTurns++;
}