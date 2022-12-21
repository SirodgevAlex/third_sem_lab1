#pragma once

#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "Sort.h"
#include "Sequence.h"
#include "DynamicArray.h"

using namespace std;

template<typename T>
int draw(vector<string> &SortName, bool (*compare)(T, T)) {
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
    int W = 640, H = 480;
    sf::RectangleShape OsX(sf::Vector2f(W, 1));
    OsX.setFillColor(sf::Color::Black);
    OsX.setPosition(0, H - 40);
    sf::RectangleShape OsY(sf::Vector2f(1, H));
    OsY.setFillColor(sf::Color::Black);
    OsY.setPosition(40, 0);
    int x0 = 40;
    int y0 = H - 40;
    sf::RectangleShape line[10];
    int sc = 120;
    for (int i = 0; i < 10; i++) {
        line[i].setSize(sf::Vector2f(1, 20));
        line[i].setFillColor(sf::Color::Black);
        if (i < 5) {
            line[i].setPosition(x0 + (i + 1) * 100, y0 - 10);
        } else {
            line[i].setRotation(90);
            line[i].setPosition(x0 + 10, y0 - 100);
            y0 -= 100;
        }
    }
    y0 = H - 40;
    sf::Texture t;
    t.loadFromFile("/Users/aleksandrsirodzev/Documents/для графиков.png");
    sf::Sprite pic(t);
    sf::CircleShape point(2.f);
    sf::RectangleShape strel[4];
    for (int i = 0; i < 4; i++) {
        strel[i].setSize(sf::Vector2f(1, 25));
        strel[i].setFillColor(sf::Color::Black);
        if (i < 2)
            strel[i].setPosition(x0, 0);
        else
            strel[i].setPosition(W, y0);
    }
    strel[0].setRotation(25);
    strel[1].setRotation(-25);
    strel[2].setRotation(60);
    strel[3].setRotation(-250);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        window.draw(pic);
        for (int i = 0; i < 8; i++) {
            if (i < 4) window.draw(strel[i]);
            window.draw(line[i]);
        }
        window.draw(OsX);
        window.draw(OsY);
        //window.draw(shape);
        vector<std::chrono::duration<double>> SortingTimes;
        ArraySequence<T> *AuxiliarySequence = new ArraySequence<T>();
        point.setFillColor(sf::Color::Blue);
        float x1 = x0;
        float y1 = y0;
        for (int i = 100; i <= 5000; i += 200) {
            int size = i;
            while (AuxiliarySequence->GetLength() != i) {
                AuxiliarySequence->Append(rand());
//                for (int g = 0; g < AuxiliarySequence->GetLength() - 1; g++) {
//                    cout << AuxiliarySequence->Get(g) << ' ';
//                }
//                cout << '\n';
            }
            SortTimes(AuxiliarySequence, SortingTimes, SortName, asc);
            for (int g = 0; g < SortName.size(); g++) {
                if (g == 0) point.setFillColor(sf::Color::Blue);
                else if (g == 1) point.setFillColor(sf::Color::Green);
                else if (g == 2) point.setFillColor(sf::Color::Red);
                else if (g == 3) point.setFillColor(sf::Color::Yellow);
                else if (g == 4) point.setFillColor(sf::Color::Cyan);
                else if (g == 5) point.setFillColor(sf::Color::Blue);
                else if (g == 6) point.setFillColor(sf::Color::Transparent);
                else if (g == 7) point.setFillColor(sf::Color::Black);
                int cur = chrono::duration_cast<chrono::milliseconds>(SortingTimes[g]).count();
                y1 = y0 - cur;
                cout << i << ' ' << y1 << ' ' << cur << '\n';
                point.setPosition(x1, y1);
                window.draw(point);
            }
            x1 = x0 + i / 10;
            window.draw(point);
        }
        window.display();
        return 0;
        //usleep(10000000000);

    }
}