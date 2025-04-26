#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

auto app1() -> void {
    auto window = sf::RenderWindow(
        sf::VideoMode({800, 600}), "App1",
        sf::Style::Default, sf::ContextSettings(0, 0, 8)
    );
    window.setFramerateLimit(60);

    auto rectangle = sf::RectangleShape(sf::Vector2f(75.f, 75.f));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setPosition(350, 250);

    auto move = sf::Vector2f(4.f, 4.f);

    while(window.isOpen()) {
        auto event = sf::Event();
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) window.close();
            else if(event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    auto mousePosition = sf::Mouse::getPosition(window);

                    if(rectangle.getGlobalBounds().contains({static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)})) {
                        auto i = rand() % 7;
                        auto color = rectangle.getFillColor();

                        switch (i) {
                            case 0: color = sf::Color::Blue; break;
                            case 1: color = sf::Color::Green; break;
                            case 2: color = sf::Color::Yellow; break;
                            case 3: color = sf::Color::Cyan; break;
                            case 4: color = sf::Color::Red; break;
                            case 5: color = sf::Color::Magenta; break;
                            case 6: color = sf::Color::Black; break;
                        }
                        rectangle.setFillColor(color);
                    }
                }
            }
        }

        if(rectangle.getPosition().x + rectangle.getSize().x > window.getSize().x ||
            rectangle.getPosition().x <= 0) {
            move.x = -move.x;
        }
        if(rectangle.getPosition().y + rectangle.getSize().y > window.getSize().y ||
            rectangle.getPosition().y < 0) {
            move.y = -move.y;
        }
        rectangle.move(move);

        window.clear(sf::Color::White);
        window.draw(rectangle);
        window.display();
    }
}

auto app2() -> void {
    auto window = sf::RenderWindow(
        sf::VideoMode({800, 600}), "App2",
        sf::Style::Default, sf::ContextSettings(0, 0, 8)
    );
    window.setFramerateLimit(60);

    auto ball = sf::CircleShape(50, 30);
    ball.setFillColor(sf::Color::Red);
    ball.setPosition(350, 500);

    auto moveVector = sf::Vector2f(0.f, 0.f);

    auto moveUp = false;
    auto power = 1.0f;

    while(window.isOpen()) {
        auto event = sf::Event();
        if(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                moveUp = true;
            } else if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
                moveUp = false;
            }
        }

        if(moveUp) {
            power = 0.99f;
            moveVector.y = -15.f;
        } else if (ball.getPosition().y >= 500 && moveVector.y < 1.f && moveVector.y > -1.f){
            moveVector.y = 0;
        } else if (moveVector.y > -1.f && moveVector.y < 0.0f && ball.getPosition().y != 500) {
            power = 0.99f;
            moveVector.y = 1.f;
        } else if (moveVector.y > 0.0f && ball.getPosition().y >= 500) {
            power = 0.99f;
            moveVector.y = moveVector.y * (-0.6f);
        } else if (moveVector.y < 0) {
            moveVector.y *= power;
            if(power > 0.95f) {
                power *= 0.995f;
            } else if(power > 0.9f) {
                power *= 0.99f;
            } else if(power > 0.85f) {
                power *= 0.985f;
            } else {
                power *= 0.98f;
            }
        } else if (moveVector.y > 0) {
            moveVector.y *= power;
            if (power > 1.1f) {
                power *= 1.0005f;
            } else if (power > 1.01f) {
                power *= 1.005f;
            } else {
                power *= 1.05f;
            }
        }

        // std::cout << moveVector.y << " " << power << " " << ball.getPosition().y << "\n";
        ball.move(moveVector);
        window.clear(sf::Color::White);
        window.draw(ball);
        window.display();
    }
}

auto main() -> int {
    // app1();
    app2();
}