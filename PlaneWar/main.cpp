
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//




// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

//int main(int, char const**)
//{
//    // Create the main window
//    sf::RenderWindow window(sf::VideoMode(Width, Height), "PlaneWar Powered by Zhoufeiyu");
//
//    // Set the Icon
//    sf::Image icon;
//    if (!icon.loadFromFile(resourcePath() + "image/icon.png")) {
//        return EXIT_FAILURE;
//    }
//    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
//
//    // Load a sprite to display
//    sf::Texture texture;
//    if (!texture.loadFromFile(resourcePath() + "image/background.png")) {
//        return EXIT_FAILURE;
//    }
//    sf::Sprite sprite(texture);
//
//    // Create a graphical text to display
//    sf::Font font;
//    if (!font.loadFromFile(resourcePath() + "font/sansation.ttf")) {
//        return EXIT_FAILURE;
//    }
//    sf::Text text("Hello SFML", font, 50);
//    text.setColor(sf::Color::Black);
//
//    // Load a music to play
//    sf::Music music;
//    if (!music.openFromFile(resourcePath() + "audio/nice_music.ogg")) {
//        return EXIT_FAILURE;
//    }
//
//    // Play the music
//    music.play();
//
//    // Start the game loop
//    while (window.isOpen())
//    {
//        // Process events
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // Close window: exit
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//
//            // Escape pressed: exit
//            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
//                window.close();
//            }
//        }
//
//        // Clear screen
//        window.clear();
//
//        // Draw the sprite
//        window.draw(sprite);
//
//        // Draw the string
//        window.draw(text);
//
//        // Update the window
//        window.display();
//    }
//
//    return EXIT_SUCCESS;
//}
#define SCREEN_WIDTH 480
#define SCREEN_HIGTH 800
#include "Background.hpp"
#include "Weapon.hpp"
#include "Army.hpp"
#include <iostream>

using  namespace std;
sf::Image Bullet::image;
int main(int, char const**)
{
    Bullet::image.loadFromFile(resourcePath()+"image/shoot.png");
    Backgroud window;
    Army army;
    army.setowner(&window);
    
    sf::Clock clock1,clock2,clock3,clock4,clock5,secondclock;
    sf::Time time1 ,time2,time3,time4,time5,secondtime;
    int difference = 1;
    int enemysfrequency = 3;
    sf::Music music;
    sf::Music music_bullet;
    sf::Music music_down;
    sf::Music game_over;
    if (!game_over.openFromFile(resourcePath()+"audio/game_over.ogg")) {
        return EXIT_FAILURE;
    }
    if (!music_down.openFromFile(resourcePath()+"audio/enemy3_down.ogg")) {
        return EXIT_FAILURE;
    }
    if (!music_bullet.openFromFile(resourcePath()+"audio/bullet.ogg")) {
        return EXIT_FAILURE;
    }
    if (!music.openFromFile(resourcePath()+"audio/game_music.ogg")) {
        return EXIT_FAILURE;
    }
    music.play();
    while (window.getwindow().isOpen())
    {
        sf::Event event;
        while (window.getwindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.getwindow().close();
        }
        window.getmyplane().moving(event);
        time1 = clock1.getElapsedTime();
        if((double)time1.asSeconds()>0.1){
            if(window.getmyplane().fire(event)){
                music_bullet.play();
            }
            clock1.restart();
        }
        time2 = clock2.getElapsedTime();
        if ((double)time2.asSeconds()>enemysfrequency) {
            army.add();
            army.fire();
            clock2.restart();
        }
        time3 = clock3.getElapsedTime();
        if ((double)time3.asSeconds()>0.2&&window.getmyplane().isdown()) {
            window.getmyplane().down();
            clock3.restart();
        }
        window.getmyplane().buttlesmoving();
        army.moving();
        window.check();
        army.bulletfly();
        if(window.touchbullet())
        {
            music_down.play();
        }
        time5 = clock5.getElapsedTime();
        if(time5.asSeconds()>0.1){
            army.down();
            clock5.restart();
        }
        if (window.getmyplane().isdown()) {
            game_over.play();
            music.stop();
        }
        secondtime = secondclock.getElapsedTime();
        if (secondtime.asSeconds()>10) {
            //            window.change(difference);
            if (enemysfrequency==3) {
                enemysfrequency -=2 ;
                difference++;
                window.baomu(difference);
                difference++;
                //                secondclock.restart();
            }
            
        }
        window.touchenemy();
        window.touch();
        window.touchhero();
        window.refresh();
        window.enemybulletstouch();
        if(window.isover())
        {
            enemysfrequency = 3;
            difference = 1;
            secondclock.restart();
        }
        time4 = clock4.getElapsedTime();
        if (time4.asSeconds()>0.5) {
            window.usebomb(event);
            clock4.restart();
        }
    }
    return EXIT_SUCCESS;
}
