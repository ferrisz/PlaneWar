//
//  Plane.cpp
//  PlaneWar
//
//  Created by Ferris on 16/5/13.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include "Plane.hpp"

Plane::Plane(std::string name,sf::IntRect intrect)
{
    if (!image.loadFromFile(resourcePath()+"image/shoot.png")) {
        return EXIT_FAILURE;
    }
    texture.loadFromImage(image);
    this->setTexture(texture);
    this->setTextureRect(intrect);
    plane_size = sf::Vector2u(intrect.width,intrect.height);
    weapons = new std::vector<Weapon*>;
    weapons->push_back(new Weapon(0));
    downbegin = false;
    downover = false;
}
bool Plane::fire(sf::Event event)
{
    for(auto&a:*weapons)
    {
        a->fire(event,plane_size,this);
    }
    return true;
}
sf::Vector2u Plane::getsize()
{
    return plane_size;
}
void Plane::buttlesmoving()
{
    for(auto&a:*weapons)
    {
        a->fly();
    }
}
bool Plane::isdown()
{
    return downbegin;
}
