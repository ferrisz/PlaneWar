//
//  MyPlane.cpp
//  PlaneWar
//
//  Created by Ferris on 16/5/13.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include "MyPlane.hpp"

void MyPlane::setowner(Backgroud *opwindow)
{
    pwindow = opwindow;
}
Backgroud* MyPlane::getowner()
{
    return pwindow;
}

bool MyPlane::checkleft()
{
    sf::Vector2f position = getPosition();
    if (position.x <= 0) {
        return false;
    }else
    {
        return true;
    }
}
bool MyPlane::checkright()
{
    sf::Vector2f position = getPosition();
    if (position.x >=480-image_size.x) {
        return false;
    }else
    {
        return true;
    }
}
bool MyPlane::checkup()
{
    sf::Vector2f position = getPosition();
    if (position.y <= 0) {
        return false;
    }else
    {
        return true;
    }
}
bool MyPlane::checkdown()
{
    sf::Vector2f position = getPosition();
    if (position.y >= 800-image_size.y) {
        return false;
    }else
    {
        return true;
    }
}
void MyPlane::move_left()
{
    if (checkleft()) {
        move(-speed, 0);
    }
}
void MyPlane::move_right()
{
    if (checkright()) {
        move(speed,0);
    }
    
}
void MyPlane::move_up()
{
    if (checkup()) {
        move(0, -speed);
    }
}
void MyPlane::move_down()
{
    if (checkdown()) {
        move(0,speed);
    }
}
void MyPlane::moving(sf::Event event)
{
    sf::Vector2f position = getPosition();
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
        if (!(position.x <= 0))
        {
            this->move_left();
        }
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
        if (!(position.x>=480-plane_size.x)) {
            this->move_right();
        }
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
        if (!(position.y<= 0)) {
            this->move_up();
            this->setTextureRect(sf::IntRect(0, 99,102, 126));
        }
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
        if (!(position.y >= 800-plane_size.y)) {
            this->move_down();
        }
    }
}
bool MyPlane::down()
{
    switch (downstate) {
        case 1:this->setTextureRect(sf::IntRect(165, 234,102, 126));
            downstate++;
            break;
        case 2:this->setTextureRect(sf::IntRect(330, 624,102, 126));
            downstate++;
            break;
        case 3:this->setTextureRect(sf::IntRect(330, 498,102, 126));
            downstate++;
            break;
        case 4: this->setTextureRect(sf::IntRect(432, 624,102, 126));
            downstate++;
            break;
        case 5:
            downstate++;
            downover = true;
            break;
        default:
            break;
    }
    
    return true;
}
bool MyPlane::fire(sf::Event event)
{
    bool panduan = false;
    int i = 1;
    for(auto &a:(*weapons))
    {
        if (i++==1) {
            panduan = a->fire(event,plane_size,this);
            
        }else
            a->fire(event,plane_size,this);
    }
    return panduan;
}
void MyPlane::ishurt()
{
    life--;
    if (life==0) {
        setdownbegin(true);
    }
}
void MyPlane::buttlesmoving()
{
    for(auto &a:(*weapons))
    {
        a->fly();
    }
}