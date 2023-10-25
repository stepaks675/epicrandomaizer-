#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
Vector2i m;
Font font2;
Music saw;
int min, max;
class TextBox {
public:
	std::string txt="";
	FloatRect collisionBox;
	Text insideTxt;
	RectangleShape box{ Vector2f(300, 40) };
	bool inFocus;
	bool isActive=false;
	void checkFocus() {
		insideTxt.setString(txt);
		if (collisionBox.contains(m.x, m.y)) {
			inFocus = true;
			if (isActive == false) {
				box.setOutlineColor(Color::Black);
			}
		}
		else {
			inFocus = false;
			if (isActive == false) {
				box.setOutlineColor(Color::White);
			}
		}
	}
	void setActive() {
		if (inFocus == true) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				isActive = true;
				box.setOutlineColor(Color::Red);
			}
		}
		else {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				isActive = false;
				box.setOutlineColor(Color::White);
			}
		}
	}
	TextBox(int x,int y, std::string str="") {
		box.setPosition(x, y);
		box.setFillColor(Color::White);
		box.setOutlineThickness(3);
		insideTxt.setCharacterSize(35);
		insideTxt.setFont(font2);
		insideTxt.setFillColor(Color::Black);
		insideTxt.setPosition(x, y);
		insideTxt.setString(str);
		collisionBox = box.getGlobalBounds();
	}
};
int StartUI(int &min, int &max) {
	saw.openFromFile("sawsnd.mp3");
	saw.play();
	font2.loadFromFile("font2.ttf");
	RenderWindow win(sf::VideoMode(640, 480), "Enter min and max numbers");
	Text minn;
	minn.setFont(font2);
	minn.setCharacterSize(23);
	minn.setFillColor(Color::Red);
	minn.setString("Enter minimal \nnumber");
	minn.setPosition(360, 165);
	Text maxn;
	maxn.setFont(font2);
	maxn.setCharacterSize(23);
	maxn.setFillColor(Color::Red);
	maxn.setString("Enter maximal number\n (greater than minimal)");
	maxn.setPosition(360, 250);
	Texture btn;
	Texture txt;
	Sprite bg;
	Sprite button;
	btn.loadFromFile("startbutton.png");
	txt.loadFromFile("metalbg.jpg");
	bg.setTexture(txt);
	button.setTexture(btn);
	button.setScale(0.07, 0.07);
	button.setPosition(50, 325);
	FloatRect buttonc = button.getGlobalBounds();
	TextBox box1(50, 165);
	TextBox box2(50, 250);
	while (win.isOpen()) {
		m = Mouse::getPosition(win);
		Event event;
		win.clear();
		box1.checkFocus();
		box1.setActive();
		box2.checkFocus();
		box2.setActive();
		while (win.pollEvent(event))
		{
			if (event.type == Event::TextEntered) {
				switch (event.text.unicode) {
				case 49:
					if (box1.isActive == true) {
						if (box1.txt.size() < 10) {
							box1.txt += "1";
						}
					}
					if (box2.isActive == true) {
						if (box2.txt.size() < 10) {
							box2.txt += "1";
						}
					}
					break;
				case 50:
					if (box1.isActive == true) {
						if (box1.txt.size() < 10) {
							box1.txt += "2";
						}
					}
					if (box2.isActive == true) {
						if (box2.txt.size() < 10) {
							box2.txt += "2";
						}
					}
					break;
				case 51:
					if (box1.isActive == true) {
						if (box1.txt.size() < 10) {
							box1.txt += "3";
						}
					}
					if (box2.isActive == true) {
						if (box2.txt.size() < 10) {
							box2.txt += "3";
						}
					}
					break;
				case 52:
					if (box1.isActive == true) {
						if (box1.txt.size() < 10) {
							box1.txt += "4";
						}
					}
					if (box2.isActive == true) {
						if (box2.txt.size() < 10) {
							box2.txt += "4";
						}
					}
					break;
				case 53:
					if (box1.isActive == true) {
						if (box1.txt.size() < 10) {
							box1.txt += "5";
						}
					}
					if (box2.isActive == true) {
						if (box2.txt.size() < 10) {
							box2.txt += "5";
						}
					}
					break;
				case 54:
					if (box1.isActive == true) {
						if (box1.txt.size() < 10) {
							box1.txt += "6";
						}
					}
					if (box2.isActive == true) {
						if (box2.txt.size() < 10) {
							box2.txt += "6";
						}
					}
					break;
				case 55:
					if (box1.isActive == true) {
						if (box1.txt.size() < 10) {
							box1.txt += "7";
						}
					}
					if (box2.isActive == true) {
						if (box2.txt.size() < 10) {
							box2.txt += "7";
						}
					}
					break;
				case 56:
					if (box1.isActive == true) {
						if (box1.txt.size() < 10) {
							box1.txt += "8";
						}
					}
					if (box2.isActive == true) {
						if (box2.txt.size() < 10) {
							box2.txt += "8";
						}
					}
					break;
				case 57:
					if (box1.isActive == true) {
						if (box1.txt.size() < 10) {
							box1.txt += "9";
						}
					}
					if (box2.isActive == true) {
						if (box2.txt.size() < 10) {
							box2.txt += "9";
						}
					}
					break;
				case 48:
					if (box1.isActive == true) {
						if (box1.txt.size() > 0) {
							box1.txt += "0";
						}
					}
					if (box2.isActive == true) {
						if (box2.txt.size() > 0) {
							box2.txt += "0";
						}
					}
					break;
				case 8:
					if (box1.isActive == true) {
						if (box1.txt.size() > 0) {
							box1.txt.pop_back();
						}
					}
					if (box2.isActive == true) {
						if (box2.txt.size() > 0) {
							box2.txt.pop_back();
						}
					}
					break;
				}
			}
		}
		if (buttonc.contains(m.x, m.y)) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (box1.txt != "" && box2.txt != "") {
				min = stoi(box1.txt);
				max = stoi(box2.txt);
				if (max > min) {
					saw.stop();
					win.close();
				}
			}
			}
		}
		win.draw(bg);
		win.draw(box1.box);
		win.draw(box1.insideTxt);
		win.draw(box2.box);
		win.draw(box2.insideTxt);
		win.draw(button);
		win.draw(maxn);
		win.draw(minn);
		win.display();

	}
}
