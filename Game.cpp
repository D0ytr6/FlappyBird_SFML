#include"Game.h"

bool startgame() {
    // ��'���, �� � �������� ����� ��������
    RenderWindow window(sf::VideoMode(519, 720), "Flappy bird");
    int Pscore = 0;
    Menu menu(window);
    Image background;
    Texture backgroundtext;
    Sprite backroundsprite;

    Image icon;
    icon.loadFromFile("icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Font font;
    font.loadFromFile("arial.ttf");

    background.loadFromFile("background.png");
    backgroundtext.loadFromImage(background);
    backroundsprite.setTexture(backgroundtext);

    Player bird("bird.png", 150.0, 100.0);
    bird.alive = true;
    Pipe first("pipe.png", 500);
    Pipe second("pipe.png", 750);
    Pipe three("pipe.png", 1000);

    Text score;
    score.setFont(font);
    score.setPosition(5, 5);
    score.setFillColor(Color(255, 186, 0));
    score.setCharacterSize(30);

    bool checkcollisions = false;
    Clock clock;
    float times = 0;
    window.setFramerateLimit(60);
    // �������� ���� ��������, ���������� ���� ������� ����
    Event event;
    while (window.isOpen())
    {

        times = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        times = times / 1400;
        // ���������� ��䳿
        while (window.pollEvent(event)){
            // ���������� �������� �������, � ���� ����� � ��������
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Space) or Mouse::isButtonPressed(Mouse::Left)) {
            bird.Fall = -0.6;
        }
        else {
            bird.Fall = bird.Fall + 0.07;
        }

        // ��������� ������� �������� ���糿, ������� � �� �������
        checkcollisions = Collisions(bird.sprite, first.sprite, first.sprite2, second.sprite, second.sprite2, three.sprite, three.sprite2);
        if (checkcollisions == true) {
            bird.alive = false; // ���� ������ ��������� true, �� ������ ������
        }
        // ���� ������ ����, ����������� ��� ��������� �� ������� ��������� ������� ������.
        if (bird.alive == true) {
            Pscore = three.counter + second.counter + first.counter; // ����� ������� ����
            ostringstream PlayerScore;
            PlayerScore << Pscore; //������� ������� ���� � ������� �����, �� �������� �������� ���� �� ��� ���
            score.setString("Score: " + PlayerScore.str());
            window.clear();
            window.draw(backroundsprite);
            window.draw(bird.sprite);
            bird.update(times);
            first.draw_pipe(window);
            second.draw_pipe(window);
            three.draw_pipe(window);
            window.draw(score);
            first.update_pipe(times);
            second.update_pipe(times);
            three.update_pipe(times);
            window.display();

        }
        else {
            // ������ �������, ������� ������� ������. ��������� �������� ������������
            if (bird.sprite.getPosition().y < 690) {
                window.clear();
                bird.Fall = 0.7;
                bird.sprite.setRotation(90.f);
                window.draw(backroundsprite);
                window.draw(bird.sprite);
                bird.update(times);
                first.draw_pipe(window);
                second.draw_pipe(window);
                three.draw_pipe(window);
                window.display();
            }
            else {
                // ������ �������� ����, ������� ���� ��������
                window.clear();
                window.draw(backroundsprite);
                window.draw(bird.sprite);
                first.draw_pipe(window);
                second.draw_pipe(window);
                three.draw_pipe(window);
                window.display();
                Restart restarts(window, Pscore);
                restarts.draw(window);
                if (restarts.update_events(window) == false) {
                    return true; // ������� true ���� ���������� �������� �������
                }
            }

        }

    }
}
void gameRun() {
    // ���������� �������, ������� ������� ������� startgamne
    if (startgame() == true) {
        gameRun();
    }

}