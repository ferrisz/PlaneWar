//
//  Bullet.hpp
//  PlaneWar
//
//  Created by Ferris on 16/5/28.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Bullet: public sf::Sprite
{
public:
    Bullet();
    static sf::Image image;
    //    static void load();
    void setuse(bool);
    bool getuse();
    void check();
private:
    sf::Texture  texture;
    bool use = false;
    
};


#endif /* Bullet_hpp */
