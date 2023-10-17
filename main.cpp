#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace sf;
class Number {
    int number;
    RectangleShape ob{ Vector2f(272,168) }; //прямоугольник в котором будет число number цвета color
    Number(int n,  Color c) {
        number = n;
        ob.setFillColor(c);
    }
};

int main()

{
    Texture pointer; // указатель на выйгрышное число
    pointer.loadFromFile("C:/Users/stepaks/source/repos/randomizer/pointer.png");
    Sprite point;
    point.setTexture(pointer);
    point.scale(Vector2f(0.15, 0.15));
    point.setPosition(547, 0);

    Texture fon; // сама рамка
    fon.loadFromFile("C:/Users/stepaks/source/repos/randomizer/frame.png");
    Sprite fonsprite;
    fonsprite.setTexture(fon);

    Sprite fonsprite2;// тож рамка
    fonsprite2.setTexture(fon);
    fonsprite2.setPosition(1280, 0);

    Font font;
    font.loadFromFile("C:/Users/stepaks/source/repos/randomizer/fonty.ttf");
  
    float vel = 1;
    int min = 0;
    int max = 100;
    Vector2f pos;
    Vector2f pos2;

    sf::Music top; //музяка
    top.openFromFile("C:/Users/stepaks/source/repos/randomizer/track.mp3");
    top.play();

    RenderWindow window(sf::VideoMode(1280, 360), "EPIC RANDOMIZER");
    window.setFramerateLimit(144);

    RectangleShape bg(Vector2f(1280, 360));// фон
    bg.setFillColor(Color::White);

    Clock tostart;//отсчёт до начала рулетки
    bool flag = true; // начало рулетки
    bool slowflag = false;
    Clock clock;//таймер
    float spintimer; // время для ускорения и замедления рулетки
    float time; //прост

    while (window.isOpen())
    {

        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 3000;

        if (Keyboard::isKeyPressed(Keyboard::F)) {
            flag = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::G)) {
            flag = false;
        }
        if (flag) {
            spintimer = tostart.getElapsedTime().asSeconds();

            if (spintimer < 20 && !slowflag) {
                vel = ((spintimer / 6) * (spintimer / 6)) + 0.2;
            }
            if (spintimer >= 25) {
                slowflag = true;
                tostart.restart();
            }
            if (spintimer > 0.5 && slowflag && vel>0) {
                if (vel - ((vel / 13) + 0.06) > 0) {
                    vel -= ((vel / 13) + 0.06);
                    tostart.restart();
                }
                else {
                    vel = 0;
                }
            }

            fonsprite.move(-1*time*vel, 0);
            fonsprite2.move(-1 * time*vel, 0);
            pos = fonsprite.getPosition();
            pos2 = fonsprite2.getPosition();
            if (pos.x <= -1280) {
                fonsprite.setPosition(pos2.x+1279, 0);
            }
            if (pos2.x <= -1280) {
                fonsprite2.setPosition(pos.x+1279, 0);
            }
        }

        window.setSize(Vector2u(1280,  360));//сохранение размера окна постоянным
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(bg);
        window.draw(fonsprite);
        window.draw(fonsprite2);
        window.draw(point);
        window.display();
        
    }

    return 0;
}