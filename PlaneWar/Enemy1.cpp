//
//  Enemy1.cpp
//  PlaneWar
//
//  Created by Ferris on 16/5/28.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include "Enemy1.hpp"
#include <random>

bool Enemy1::down()
{
    switch (downstate) {
        case 1:this->setTextureRect(sf::IntRect( 534, 655,69, 95));
            downstate++;
            break;
        case 2:this->setTextureRect(sf::IntRect(603, 655, 69, 95));
            downstate++;
            break;
        case 3:this->setTextureRect(sf::IntRect( 672, 653,69, 95));
            downstate++;
            break;
        case 4: this->setTextureRect(sf::IntRect(741, 653,69, 95));
            downstate++;
            downover = true;
            break;
        default:
            break;
    }
    downbegin = true;
    return true;
}
