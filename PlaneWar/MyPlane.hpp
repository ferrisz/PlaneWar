//
//  MyPlane.hpp
//  PlaneWar
//
//  Created by Ferris on 16/5/28.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#ifndef MyPlane_hpp
#define MyPlane_hpp

#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Plane.hpp"
class Backgroud;
class MyPlane :public Plane
{
public:
    MyPlane(std::string name = "image/shoot.png",sf::IntRect intrect = sf::IntRect(165, 360,102, 126)):Plane(name,intrect){
        this->setColor(sf::Color::Blue);
        lifenumber = 3;
    }
    bool fire(sf::Event);
    bool checkleft();
    bool checkright();
    bool checkup();
    bool checkdown();
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    void moving(sf::Event);
    void setowner(Backgroud *);
    virtual bool down();
    void ishurt();
    void buttlesmoving();
    int getlife()
    {
        return life;
    }
    void gownup()
    {
        grade++;
        switch (grade) {
            case 2:
                weapons->push_back(new Weapon(-1));
                weapons->push_back(new Weapon(1));
                break;
            case 3:
                weapons->push_back(new Weapon(-2));
                weapons->push_back(new Weapon(2));
                break;
            case 4:
                weapons->push_back(new Weapon(-3));
                weapons->push_back(new Weapon(3));
            default:
                break;
        }
    }
    Backgroud* getowner();
private:
    sf::Image image;
    sf::Texture  texture;
    sf::Vector2u image_size;
    Backgroud *pwindow;
    int grade = 1;
    int i = 0;
    int speed =1;
    int life = 3;
};
#endif /* MyPlane_hpp */
