#include "Restart.h"

Restart::Restart(RenderWindow& window, int& score) : exit("exit.png", 173, 525, 1.3f, 1.3f), restartGame("restart.png", 153, 400, 1.f, 1.f) {
    // створюємо об'єкт рестарту
    ScoreCount << score;
    image.loadFromFile("Gameover.png");
    image.createMaskFromColor(sf::Color::White);
    text.loadFromImage(image);
    textSprite.setTexture(text);
    textSprite.setScale(3.5f, 3.5f);
    textSprite.setPosition(93, 100);
    font.loadFromFile("arial.ttf");
    scores.setFont(font);
    scores.setPosition(110, 150);
    scores.setFillColor(Color(255, 186, 0));
    scores.setCharacterSize(50);
    scores.setString("Scores: " + ScoreCount.str());
    scores.setPosition(150, 200);
    scores.setFillColor(Color(255, 255, 255));
    scores.setCharacterSize(50);
    background.loadFromFile("background.png");
    backgSprite.setTexture(background);
}
bool Restart::update_events(RenderWindow& window) {
    // Перевіряємо події на екрані
    Event event;
    while (Isrestart == true) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        window.clear();
        if (IntRect(153, 400, 214, 75).contains(Mouse::getPosition(window)) and Mouse::isButtonPressed(Mouse::Left)) {
            Isrestart = false;
            return false;

        }
        if (IntRect(173, 525, 173, 97.5).contains(Mouse::getPosition(window)) and Mouse::isButtonPressed(Mouse::Left)) {
            window.close();
            Isrestart = false;
        }
    }

}
void Restart::draw(RenderWindow& window) {
    window.draw(backgSprite);
    window.draw(textSprite);
    window.draw(scores);
    window.draw(restartGame.ButtonSprite);
    window.draw(exit.ButtonSprite);
    window.display();

}