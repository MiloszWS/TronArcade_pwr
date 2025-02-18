//
// Created by pmi03 on 01.06.2023.
//
#include "SFMLController.h"
#include "Timer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <iostream>

using namespace std;

SFMLController::SFMLController(motorsTextView& motor1, class motor2& motor2, SFMLView& view1, Integrator& integer1, menuScreen& menu1, class modeChoose& modeScreen1, boardTextView& board1) : motor1(motor1), motor2(motor2), view(view1), integer(integer1), menu(menu1), mode(modeScreen1), board(board1) {
}

void SFMLController::music() {
    PlaySound(TEXT("D://CLion//Projects//TronArcade//Sounds//Separate.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

    void SFMLController::runGame() {
        sf::RenderWindow window(sf::VideoMode(900, 800), "Tron");
        window.setVerticalSyncEnabled(false);
        window.setFramerateLimit(160);

       // PlaySound(TEXT("D://CLion//Projects//TronArcade//Sounds//Motorbikes.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

        EngineUtils::Timer* timer = EngineUtils::Timer::Instance();

        motor1.direction=UP;
        motor2.direction=UP2;

        while (window.isOpen()) {
            window.setKeyRepeatEnabled(false);

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                // Obsługa klawiszy sterujących dla motoru 1 i motoru 2
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Down) {
                        motor2.goDown();
                    } else if (event.key.code == sf::Keyboard::Up) {
                        motor2.goUp();
                    } else if (event.key.code == sf::Keyboard::Right) {
                        motor2.turnRight();
                    } else if (event.key.code == sf::Keyboard::Left) {
                        motor2.turnLeft();
                    } else if (event.key.code == sf::Keyboard::S) {
                        motor1.goDown();
                    } else if (event.key.code == sf::Keyboard::W) {
                        motor1.goUp();
                    } else if (event.key.code == sf::Keyboard::D) {
                        motor1.turnRight();
                    } else if (event.key.code == sf::Keyboard::A) {
                        motor1.turnLeft();
                    } else if (event.key.code == sf::Keyboard::Space) {
                        if (integer.again == 1) {
                            // Uruchom grę od nowa
                            integer.again = 0; // Zresetuj flagę again
                            if (integer.getGameState1() != RUNNING || integer.getGameState2() != RUNNING2) {
                                // Jedno z motorów uległo awarii
                                if (integer.getGameState1() != RUNNING) {
                                    scoreMotor2++; // Zwiększ wynik dla motoru 2
                                }
                                if (integer.getGameState2() != RUNNING2) {
                                    scoreMotor1++; // Zwiększ wynik dla motoru 1
                                }
                            }
                            view.setScoreMotor1(scoreMotor1);
                            view.setScoreMotor2(scoreMotor2);
                            integer.resetGame(); // Zresetuj stany gry
                            continue; // Kontynuuj pętlę bez wywoływania funkcji update() itp.
                        }
                    }
                }
            }
//            if (integer.getGameState1() != RUNNING || integer.getGameState2() != RUNNING2) {
//                PlaySound(TEXT("D://CLion//Projects//TronArcade//Sounds//Cartoon Crash.wav"), NULL, SND_FILENAME | SND_ASYNC);
//            }

            if (integer.getGameState1() == RUNNING && integer.getGameState2() == RUNNING2) {
                timer->Tick();
                if (timer->DeltaTime() >= 5 / 60.0f) {
                    timer->Reset();
                    integer.update();
                }
            }

            window.clear(sf::Color::Black);
            view.draw(window);
            window.display();
        }
        EngineUtils::Timer::Release();
    }

    void SFMLController::modeChoose() {
        rageQuit= true;
        sf::RenderWindow chooseWindow(sf::VideoMode(900, 800), "Tron");
        chooseWindow.setVerticalSyncEnabled(false);
        chooseWindow.setFramerateLimit(160);

        while (chooseWindow.isOpen()) {
            chooseWindow.setKeyRepeatEnabled(false);

            while (chooseWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    rageQuit = true;
                    chooseWindow.close();
                }

                if (event.type == sf::Event::MouseMoved) {
                    sf::Vector2f mousePosition = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);

                    if (mode.buttonSingle.getGlobalBounds().contains(mousePosition))
                    {
                        mode.textSingle.setFillColor(sf::Color(0, 255, 200));
                        mode.textSingle.setOutlineColor(sf::Color::Black);
                    }
                    else
                    {
                        mode.textSingle.setFillColor(sf::Color::Black);
                        mode.textSingle.setOutlineColor(sf::Color(0, 255, 200));
                    }

                    if (mode.buttonMulti.getGlobalBounds().contains(mousePosition))
                    {
                        mode.textMulti.setFillColor(sf::Color(0, 255, 200));
                        mode.textMulti.setOutlineColor(sf::Color::Black);
                    }
                    else
                    {
                        mode.textMulti.setFillColor(sf::Color::Black);
                        mode.textMulti.setOutlineColor(sf::Color(0, 255, 200));
                    }
                }

                if (mode.isScreen2 && mode.buttonMulti.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    rageQuit = false;
                    chooseWindow.close(); // Zmiana ekranu na Game
                    if (!rageQuit) {
                        runGame();
                    }
                }
                if (mode.isScreen2 && mode.buttonSingle.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    rageQuit = false;
                    chooseWindow.close(); // Zmiana ekranu na Game
                }
            }

            chooseWindow.clear(sf::Color::Black);
            mode.drawChooseScreen(chooseWindow);
            chooseWindow.display();
        }
    }

    void SFMLController::play() {
        sf::RenderWindow Menuwindow(sf::VideoMode(900, 800), "Tron");
        Menuwindow.setVerticalSyncEnabled(false);
        Menuwindow.setFramerateLimit(120);

        while (Menuwindow.isOpen()) {
            Menuwindow.setKeyRepeatEnabled(false);

            while (Menuwindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    rageQuit = true;
                    Menuwindow.close();
                }

                if (event.type == sf::Event::MouseMoved) {
                    sf::Vector2f mousePosition = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);

                    if (menu.buttonPlay.getGlobalBounds().contains(mousePosition))
                    {
                        menu.buttonText.setFillColor(sf::Color(0, 255, 200));
                        menu.buttonText.setOutlineColor(sf::Color::Black);
                    }
                    else
                    {
                        menu.buttonText.setFillColor(sf::Color::Black);
                        menu.buttonText.setOutlineColor(sf::Color(0, 255, 200));
                    }
                }

                if (menu.isScreen1 && menu.buttonPlay.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    rageQuit = false;
                    Menuwindow.close(); // Zmiana ekranu na Game
                }
            }

            Menuwindow.clear(sf::Color::Black);
            menu.drawMenuScreen(Menuwindow);
            Menuwindow.display();
        }

        if (!rageQuit) {
            modeChoose();
        }
        //music.stop();
    }


