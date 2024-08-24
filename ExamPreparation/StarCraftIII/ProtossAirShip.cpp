//
// Created by uchih on 24/08/2024.
//
#include "ProtossAirShip.h"

ProtossAirShip::ProtossAirShip(const AirShipType type, const int health, const int damage, const int maxShield, const int shieldRegenerateRate, const int shipId)
    : AirShip(type, health, damage, shipId), _maxShield(maxShield), _shieldRegenerateRate(shieldRegenerateRate), _currShield(maxShield) {}

void ProtossAirShip::takeDamage(const int damage) {
    _currShield -= damage;
    if (_currShield < 0) {
        _currHealth += _currShield;
        _currShield = 0;
        if (_currHealth < 0)
            _currHealth = 0;
    }
}

void ProtossAirShip::finishTurn() {
    _currShield += _shieldRegenerateRate;
    if (_currShield > _maxShield)
        _currShield = _maxShield;
}