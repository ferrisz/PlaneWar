//
//  Weapon.hpp
//  PlaneWar
//
//  Created by Ferris on 16/5/13.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#ifndef Weapon_hpp
#define Weapon_hpp

#include "Bullet.hpp"
class Weapon
{
public:
    friend class  Plane;
    Weapon(float i):direction(i){}
    bool fire(sf::Event,sf::Vector2u,sf::Sprite*);
    bool fire2(sf::Vector2u plane_size, sf::Sprite*plane);
    void fly();
    void fly2();
    void setspeed(int i)
    {
        speed = i;
    }
    std::vector<Bullet*> bullets;
private:
    //    MyPlane *myplane;
    float i = 0;
    int direction = 0;
    int speed = 1;
};

#endif /* Weapon_hpp */
