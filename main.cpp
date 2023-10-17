#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace sf;
Font font;
const Color  COLORS[] = { Color::Blue, Color::White, Color::Red, Color::Magenta, Color::Green, Color::Yellow, Color::Cyan };
class Number {
public:
    Text mytext;
    std::string number;
    RectangleShape ob{ Vector2f(266,163) }; //прямоугольник в котором будет число number цвета color
    Number(int min=1, int max=100) {
        number = (std::to_string((rand() % max - min + 1) + min));
        ob.setFillColor(COLORS[rand() % 7]);
        mytext.setFont(font);
        mytext.setString(number);
        mytext.setCharacterSize(100);
        mytext.setFillColor(Color::Black);

    }
};

int main()

{
    RenderWindow window(sf::VideoMode(1280, 360), "EPIC RANDOMIZER");
    window.setFramerateLimit(240);

    while (!Keyboard::isKeyPressed(Keyboard::Space)) {

    }
    srand(time(NULL));

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

    font.loadFromFile("C:/Users/stepaks/source/repos/randomizer/fonty.ttf");
  
    float vel = 1;
    int min = 0;
    int max = 100;
    Vector2f pos;
    Vector2f pos2;

    sf::Music top; //музяка
    top.openFromFile("C:/Users/stepaks/source/repos/randomizer/track.mp3");
    top.play();



    RectangleShape bg(Vector2f(1280, 360));// фон
    bg.setFillColor(Color::White);

    Clock tostart;//отсчёт до начала рулетки
    bool flag = true; // начало рулетки
    bool slowflag = false;
    Clock clock;//таймер
    float spintimer; // время для ускорения и замедления рулетки
    float time; //прост

    Number* first = new Number();
    first->ob.setPosition(27, 99);
    first->mytext.setPosition(96, 115);
    Number* second = new Number();
    second->ob.setPosition(347, 99);
    second->mytext.setPosition(416, 115);
    Number* third = new Number();
    third->ob.setPosition(667, 99);
    third->mytext.setPosition(736, 115);
    Number* fourth = new Number();
    fourth->ob.setPosition(985, 99);
    fourth->mytext.setPosition(1054, 115);

    Number* first1 = new Number();
    first1->ob.setPosition(1307, 99);
    first1->mytext.setPosition(1307+69, 115);
    Number* second1 = new Number();
    second1->ob.setPosition(1627, 99);
    second1->mytext.setPosition(1627+69, 115);
    Number* third1 = new Number();
    third1->ob.setPosition(1947, 99);
    third1->mytext.setPosition(1947+69, 115);
    Number* fourth1 = new Number();
    fourth1->ob.setPosition(2265, 99);
    fourth1->mytext.setPosition(2265+69, 115);


    while (window.isOpen())
    {
        
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 3000;
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

            first->ob.setPosition(pos.x + 27, 99);
            second->ob.setPosition(pos.x + 347, 99);
            third->ob.setPosition(pos.x + 667, 99);
            fourth->ob.setPosition(pos.x + 985, 99);
            first->mytext.setPosition(pos.x + 27+69, 115);
            second->mytext.setPosition(pos.x + 347+69, 115);
            third->mytext.setPosition(pos.x + 667+69, 115);
            fourth->mytext.setPosition(pos.x + 985+69, 115);


            first1->ob.setPosition(pos2.x + 27, 99);
            second1->ob.setPosition(pos2.x + 347, 99);
            third1->ob.setPosition(pos2.x + 667, 99);
            fourth1->ob.setPosition(pos2.x + 985, 99);
            first1->mytext.setPosition(pos2.x + 27 + 69, 115);
            second1->mytext.setPosition(pos2.x + 347 + 69, 115);
            third1->mytext.setPosition(pos2.x + 667 + 69, 115);
            fourth1->mytext.setPosition(pos2.x + 985 + 69, 115);


            if (pos.x <= -1280) {
                fonsprite.setPosition(pos2.x+1280, 0);

                first = new Number();

                second = new Number();

                 third = new Number();

                fourth = new Number();

                first->ob.setPosition(pos.x + 27, 99);
                second->ob.setPosition(pos.x + 347, 99);
                third->ob.setPosition(pos.x + 667, 99);
                fourth->ob.setPosition(pos.x + 985, 99);
                first->mytext.setPosition(pos.x + 27 + 69, 115);
                second->mytext.setPosition(pos.x + 347 + 69, 115);
                third->mytext.setPosition(pos.x + 667 + 69, 115);
                fourth->mytext.setPosition(pos.x + 985 + 69, 115);
            }
            if (pos2.x <= -1280) {
                fonsprite2.setPosition(pos.x+1280, 0);
                first1 = new Number();

                second1 = new Number();

                third1 = new Number();

                fourth1 = new Number();

                first1->ob.setPosition(pos2.x + 27, 99);
                second1->ob.setPosition(pos2.x + 347, 99);
                third1->ob.setPosition(pos2.x + 667, 99);
                fourth1->ob.setPosition(pos2.x + 985, 99);
                first1->mytext.setPosition(pos2.x + 27 + 69, 115);
                second1->mytext.setPosition(pos2.x + 347 + 69, 115);
                third1->mytext.setPosition(pos2.x + 667 + 69, 115);
                fourth1->mytext.setPosition(pos2.x + 985 + 69, 115);
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
        window.draw(first->ob);
        window.draw(second->ob);
        window.draw(third->ob);
        window.draw(fourth->ob);
        window.draw(first1->ob);
        window.draw(second1->ob);
        window.draw(third1->ob);
        window.draw(fourth1->ob);
        window.draw(first->mytext);
        window.draw(second->mytext);
        window.draw(third->mytext);
        window.draw(fourth->mytext);
        window.draw(first1->mytext);
        window.draw(second1->mytext);
        window.draw(third1->mytext);
        window.draw(fourth1->mytext);
        window.draw(point);
        window.display();
        
    }

    return 0;
}