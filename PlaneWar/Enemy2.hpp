//
//  Enemy2.hpp
//  PlaneWar
//
//  Created by Ferris on 16/5/13.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#ifndef Enemy2_hpp
#define Enemy2_hpp

#include "Enemy.hpp"
class Enemy2:public Enemy
{
public:
    Enemy2(std::string name = "image/shoot.png",sf::IntRect intrect = sf::IntRect(335, 750,169, 258)):Enemy(name,intrect){
        weapons->push_back(new Weapon(-1));
        weapons->push_back(new Weapon(1));
    }
    
    virtual bool down();
private:
    sf::Texture texture;
    sf::Image image;
};

#endif /* Enemy2_hpp */
