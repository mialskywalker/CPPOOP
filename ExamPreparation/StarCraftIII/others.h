//
// Created by uchih on 24/08/2024.
//

#ifndef OTHERS_H
#define OTHERS_H
#include <vector>
#include <memory>

#include "AirShip.h"

bool doDamage(AirShip *attacker, std::vector<std::unique_ptr<AirShip> > &enemyFleet, int damage);

#endif //OTHERS_H
