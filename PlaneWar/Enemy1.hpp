//
//  Enemy1.hpp
//  PlaneWar
//
//  Created by Ferris on 16/5/28.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#ifndef Enemy1_hpp
#define Enemy1_hpp
#include "Enemy.hpp"
class Enemy1:public Enemy
{
public:
    Enemy1(std::string name = "shoot.png",sf::IntRect intrect =sf::IntRect(0, 0, 69, 99)):Enemy(name,intrect){}
    virtual bool down();

private:
    sf::Texture texture;
    sf::Image image;

};

#endif /* Enemy1_hpp */
