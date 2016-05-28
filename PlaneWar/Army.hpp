//
//  Army.hpp
//  PlaneWar
//
//  Created by Ferris on 16/5/28.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#ifndef Army_hpp
#define Army_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Enemy1.hpp"
#include "Enemy2.hpp"
#include "Enemy.hpp"
#include "Background.hpp"
class Army
{
public:
    void setowner(Backgroud*);
    void add();
    void moving();
    void down();
    bool fire();
    bool bulletfly();
private:
    std::vector<Enemy*> enemys;
    Backgroud *background;
    std::vector<Weapon*> enemyweapons;
    int i = 0;
};
#endif /* Army_hpp */
