//The Movement Header File

#pragma once

#include "Link.h"

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

void MovingAround(Link &character);
void DecideEdges(Link &character, int windowX, int windowY);
void AnimateWalk(Link &character);

bool CollisionDetection(sf::Sprite sprite1, sf::Sprite sprite2);

#endif