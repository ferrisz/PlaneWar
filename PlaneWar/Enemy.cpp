//
//  Enemy.cpp
//  PlaneWar
//
//  Created by Ferris on 16/5/28.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include "Enemy.hpp"
#include <random>
#include <iostream>
bool Enemy::down()
{
    switch (downstate) {
        case 1:this->setTextureRect(sf::IntRect(267, 347,57, 51));
            downstate++;
            break;
        case 2:this->setTextureRect(sf::IntRect(873, 697,57, 51));
            downstate++;
            break;
        case 3:this->setTextureRect(sf::IntRect(267, 296,57, 51));
            downstate++;
            break;
        case 4: this->setTextureRect(sf::IntRect(930, 697,57, 51));
            downstate++;
            downover = true;
            break;
        default:
            break;
    }
     return true;
}
bool Enemy::fire2()
{
    for(auto&a:*weapons)
    {
        a->fire2(plane_size, this);
    }
}