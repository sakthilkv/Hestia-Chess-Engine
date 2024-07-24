#include <SFML/Graphics.hpp>
#include "chessboard.hpp"

void displayChessboard(uint64_t pieceBitboard, uint64_t highlightBitboard, int redSquare) {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Chessboard");

    const int squareSize = 500 / 8; 

    sf::RectangleShape squares[8][8];
    sf::Color pieceColor(255, 165, 0, 255); 
    sf::Color highlightColor(0, 255, 0, 255); 
    sf::Color redColor(255, 0, 0, 100); 
    sf::Color lightColor(243, 225, 255); 
    sf::Color darkColor(166, 88, 162);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            squares[i][j].setSize(sf::Vector2f(squareSize, squareSize));
            squares[i][j].setPosition(j * squareSize, i * squareSize);

            // Determine square color
            if (redSquare == (i * 8 + j)) {
                squares[i][j].setFillColor(redColor);
            } else if (pieceBitboard & (1ULL << (i * 8 + j))) {
                squares[i][j].setFillColor(pieceColor);
            } else if (highlightBitboard & (1ULL << (i * 8 + j))) {
                squares[i][j].setFillColor(highlightColor);
            } else {
                squares[i][j].setFillColor((i + j) % 2 == 0 ? lightColor : darkColor);
            }
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                window.draw(squares[i][j]);
            }
        }

        window.display();
    }
}
