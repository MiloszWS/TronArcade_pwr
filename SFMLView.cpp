//
// Created by pmi03 on 31.05.2023.
//
#include "SFMLView.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

SFMLView :: SFMLView( boardTextView &board1) : board(board1){
    field = sf::RectangleShape (sf::Vector2f(20, 20));
    field.setFillColor(sf::Color(0, 0, 0));

    font= sf::Font();
    font.loadFromFile("../Fonts/Modern Age.ttf");//Pobrana czcionka ze strony

    scoreMotor1=0;
    scoreMotor2=0;

    LetsPlay=sf::Text("LET'S PLAY!", font, 50);
    LetsPlay.setFillColor(sf::Color::Black);
    LetsPlay.setOutlineColor(sf::Color(0, 255, 200));
    LetsPlay.setOutlineThickness(5);
    LetsPlay.setStyle(sf::Text::Bold);
    LetsPlay.setOrigin(-310,-10);

    GameOver1=sf::Text("Player One Defated!", font, 50);
    GameOver1.setFillColor(sf::Color::White);
    GameOver1.setOutlineColor(sf::Color(255, 0, 0));
    GameOver1.setOutlineThickness(5);
    GameOver1.setStyle(sf::Text::Bold);
    GameOver1.setOrigin(-160,-400);

    GameOver2=sf::Text("Player Two Defated!", font, 50);
    GameOver2.setFillColor(sf::Color::Black);
    GameOver2.setOutlineColor(sf::Color(0, 255, 200));
    GameOver2.setOutlineThickness(5);
    GameOver2.setStyle(sf::Text::Bold);
    GameOver2.setOrigin(-160,-400);

    Draw=sf::Text("DRAW!", font, 50);
    Draw.setFillColor(sf::Color(255, 0, 0));
    Draw.setOutlineColor(sf::Color(0, 255, 200));
    Draw.setOutlineThickness(5);
    Draw.setStyle(sf::Text::Bold);
    Draw.setOrigin(-360,-400);

    player1=sf::Text("Player 1", font, 20);
    player1.setFillColor(sf::Color::Black);
    player1.setOutlineColor(sf::Color(0, 255, 200));
    player1.setOutlineThickness(5);
    player1.setStyle(sf::Text::Bold);
    player1.setOrigin(-20,-30);

    score1.setFont(font);
    score1.setFillColor(sf::Color::Black);
    score1.setOutlineColor(sf::Color(0, 255, 200));
    score1.setOutlineThickness(5);
    score1.setStyle(sf::Text::Bold);
    score1.setCharacterSize(60);
    score1.setPosition(20,100);



    player2=sf::Text("Player 2", font, 20);
    player2.setFillColor(sf::Color::Black);
    player2.setOutlineColor(sf::Color(255, 0, 0));
    player2.setOutlineThickness(5);
    player2.setStyle(sf::Text::Bold);
    player2.setOrigin(-780,-30);

    score2.setFont(font);
    score2.setFillColor(sf::Color::Black);
    score2.setOutlineColor(sf::Color(255, 0, 0));
    score2.setOutlineThickness(5);
    score2.setStyle(sf::Text::Bold);
    score2.setCharacterSize(60);
    score2.setPosition(815, 100);

    pressSpace.setFont(font);
    pressSpace.setString("Press space to play again");
    pressSpace.setCharacterSize(30);
    pressSpace.setFillColor(sf::Color::Black);
    pressSpace.setOutlineColor(sf::Color(0, 255, 200));
    pressSpace.setOutlineThickness(5);
    pressSpace.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = pressSpace.getLocalBounds();
    pressSpace.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    pressSpace.setPosition(450,700);
}

void SFMLView:: setScoreMotor1(int score) {
    scoreMotor1 = score;
}

void SFMLView:: setScoreMotor2(int score) {
    scoreMotor2 = score;
}

void SFMLView::draw(sf::RenderWindow &window) {
        sf::Texture EmptyField;

        int boardWidth = board.getBoardWidth();
        int boardHeight = board.getBoardHeight();
        int fieldSize = 10; // rozmiar pojedynczego pola
        int boardWidthPixels = boardWidth * fieldSize;
        int boardHeightPixels = boardHeight * fieldSize;

        // obliczamy pozycję lewego górnego rogu planszy
        int boardLeft = (window.getSize().x - boardWidthPixels) / 2;
        int boardTop = (window.getSize().y - boardHeightPixels) / 2;

        window.draw(LetsPlay);
        window.draw(player1);
        window.draw(player2);

        for (int i = 0; i < boardWidth; ++i) {
            for (int j = 0; j < boardHeight; ++j) {
                int x = boardLeft + i * fieldSize;
                int y = boardTop + 30 + j * fieldSize;
                field.setPosition(x, y);
                window.draw(field);
                if (board.getFieldInfo(i, j) == 'P') {
                    field.setFillColor(sf::Color(0, 155, 100));
                    field.setOutlineColor(sf::Color(0, 155, 100));
                    window.draw(field);
                    field.setFillColor(sf::Color(0, 0, 0));
                    field.setOutlineColor(sf::Color(150, 150, 150));
                } if (board.getFieldInfo(i, j) == 'S') {
                    field.setFillColor(sf::Color(0, 255, 200));
                    field.setOutlineColor(sf::Color(0, 255, 200));
                    window.draw(field);
                    field.setFillColor(sf::Color(0, 0, 0));
                    field.setOutlineColor(sf::Color(150, 150, 150));
                } if (board.getFieldInfo(i, j) == 'p') {
                    field.setFillColor(sf::Color(255, 100, 0));
                    field.setOutlineColor(sf::Color(255, 100, 0));
                    window.draw(field);
                    field.setFillColor(sf::Color(0, 0, 0));
                    field.setOutlineColor(sf::Color(150, 150, 150));
                } if (board.getFieldInfo(i, j) == 's') {
                    field.setFillColor(sf::Color(255, 0, 0));
                    field.setOutlineColor(sf::Color(255, 0, 0));
                    window.draw(field);
                    field.setFillColor(sf::Color(0, 0, 0));
                    field.setOutlineColor(sf::Color(150, 150, 150));
                } if (board.getFieldInfo(i, j) == '#') {
                    field.setFillColor(sf::Color(192, 192, 192));
                    field.setOutlineColor(sf::Color(192, 192, 192));
                    window.draw(field);
                    field.setFillColor(sf::Color(0, 0, 0));
                    field.setOutlineColor(sf::Color(150, 150, 150));
            }
            }
        }

    score1.setString(std::to_string(scoreMotor1));
    score2.setString(std::to_string(scoreMotor2));
    window.draw(score2);
    window.draw(score1);

    if (board.whichOne==3){
        window.draw(Draw);
        window.draw(pressSpace);
    } if (board.whichOne == 1) {
        window.draw(GameOver1);
        window.draw(pressSpace);
    } else if (board.whichOne == 2) {
        window.draw(GameOver2);
        window.draw(pressSpace);
    }
}