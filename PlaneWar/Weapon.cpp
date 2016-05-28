//
//  Weapon.cpp
//  PlaneWar
//
//  Created by Ferris on 16/5/28.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include "Weapon.hpp"

bool Weapon::fire(sf::Event event,sf::Vector2u plane_size, sf::Sprite*plane)
{
    
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::LAlt) {
        bullets.push_back(new Bullet());
        sf::Vector2f plane_position = plane->getPosition();
        (*(bullets.end()-1))->setPosition(plane_size.x/2+plane_position.x,plane_position.y-20);
        
        return true;
    }
    return false;
}
void Weapon::fly()
{
    for(auto &a:bullets)
    {
        a->move(direction, -3);
    }
}
void Weapon::fly2()
{
    for(auto &a:bullets)
    {
        a->move(direction, speed);
    }
}


bool Weapon::fire2(sf::Vector2u plane_size, sf::Sprite*plane)
{
    bullets.push_back(new Bullet());
    (*(bullets.end()-1))->setColor(sf::Color::Black);
    sf::Vector2f plane_position = plane->getPosition();
    (*(bullets.end()-1))->setPosition(plane_size.x/2+plane_position.x,plane_position.y+50);
    return true;
}