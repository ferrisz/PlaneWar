//
//  Enemy2.cpp
//  PlaneWar
//
//  Created by Ferris on 16/5/13.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include "Enemy2.hpp"
#include <random>

bool Enemy2::down()
{
    switch (downstate) {
        case 1:this->setTextureRect(sf::IntRect(0, 486,165, 261));
            downstate++;
            break;
        case 2:this->setTextureRect(sf::IntRect(0, 225,165, 261));
            downstate++;
            break;
        case 3:this->setTextureRect(sf::IntRect(839, 748,165, 260));
            downstate++;
            break;
        case 4: this->setTextureRect(sf::IntRect(165, 486,165, 261));
            downstate++;
            downover = true;
            break;
        default:
            break;
    }

    
    
    downbegin = true;
    return true;
}
