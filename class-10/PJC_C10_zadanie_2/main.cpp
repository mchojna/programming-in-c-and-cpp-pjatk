#include <iostream>
#include <SFML/Graphics.hpp>

const float gravity = 0.5f;
const float jump_strength = -10.0f;

auto main() -> int {
    auto window = sf::RenderWindow(
        sf::VideoMode({800, 200}), "Dino Beta",
        sf::Style::Default, sf::ContextSettings(0, 0, 1)
    );
    window.setFramerateLimit(60);

    auto ground = sf::RectangleShape(sf::Vector2f(800.f, 50.f));
    ground.setFillColor(sf::Color::Black);
    ground.setPosition(0, window.getSize().y - ground.getSize().y);

    auto player = sf::RectangleShape(sf::Vector2f(50.f, 50.f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(20, ground.getPosition().y - player.getSize().y);

    float verticalVelocity = 0.0f;
    bool isJumping = false;

    auto blocks = std::deque<sf::RectangleShape>();

    while(window.isOpen()) {
        auto event = sf::Event();
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && !isJumping) {
                verticalVelocity = jump_strength;
                isJumping = true;
            }
        }

        auto randInt = rand() % 101;
        if(randInt % 50 == 0) {
            int x = rand() % 20 + 20;
            int y = rand() % 20 + 20;

            auto block = sf::RectangleShape(sf::Vector2f(x, y));
            block.setFillColor(sf::Color::Red);
            block.setPosition(window.getSize().x - block.getSize().x, ground.getPosition().y - block.getSize().y);

            blocks.push_back(block);
        }

        verticalVelocity += gravity;
        player.move(0, verticalVelocity);

        if (player.getPosition().y >= 100.f) {
            player.setPosition(player.getPosition().x, 100.f);
            verticalVelocity = 0.0f;
            isJumping = false;
        }

        window.clear(sf::Color::White);
        window.draw(ground);
        window.draw(player);

        for(auto& block: blocks) {
            block.move(sf::Vector2f(-10, 0));
            window.draw(block);

            if(player.getGlobalBounds().intersects(block.getGlobalBounds())) {
                return 0;
            }
        }

        for(auto const& block: blocks) {
            if(block.getPosition().x < 0) {
                blocks.pop_front();
                break;
            }
        }

        window.display();
    }
}