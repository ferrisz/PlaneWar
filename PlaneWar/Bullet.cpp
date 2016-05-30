//
//  Bullet.cpp
//  PlaneWar
//
//  Created by Ferris on 16/5/13.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include "Bullet.hpp"

Bullet::Bullet()
{
    if (!texture.loadFromImage(image)) {
        return EXIT_FAILURE;
    }
    this->setTexture(texture);
    this->setTextureRect(sf::IntRect(1004, 987,9, 21));
}
void Bullet::setuse(bool b)
{
    use = b;
}
bool Bullet::getuse()
{
    return use;
}