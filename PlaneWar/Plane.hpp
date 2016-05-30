//
//  Plane.hpp
//  PlaneWar
//
//  Created by Ferris on 16/5/13.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#ifndef Plane_hpp
#define Plane_hpp

#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Weapon.hpp"
#include <string>
#include <vector>
#include <random>
class Plane:public sf::Sprite
{
public:
    Plane(std::string,sf::IntRect);
    virtual bool fire(sf::Event);
    void buttlesmoving();
    sf::Vector2u getsize();
    virtual bool down(){
        return true;
    }
    bool isdown();
    std::vector<Weapon*>* getweapon()
    {
        return weapons;
    }
    void setdownover(bool b)
    {
        downover = b;
    }
    void setdownbegin(bool b)
    {
        downbegin = b;
    }
    bool isdownover()
    {
        return downover;
    }
    void delife()
    {
        lifenumber--;
    }
    int getlife()
    {
        return lifenumber;
    }
    void setlife(int n)
    {
        lifenumber = n;
    }
    
private:
    
    sf::Vector2f plane_position;
    sf::Image image;
    sf::Texture  texture;
protected:
    sf::Vector2u plane_size;
    std::vector<Weapon*> *weapons;
    bool downbegin;
    bool downover;
    int downstate = 1;
    int lifenumber = 1;
};

#endif /* Plane_hpp */
