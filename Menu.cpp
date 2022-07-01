#include "Menu.h"
Menu:: Menu(RenderWindow& window) {
    Button Start("playbtn.png", 60, 450, 1.3f, 1.3f); // ��������� ��������� ����� ������
    Button Exit("exit.png", 287, 450, 1.3f, 1.3f);
    Image icon;
    icon.loadFromFile("icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    Image textimage;
    Texture background, text;
    Sprite backgSprite, textSprite; // ��������� ������ ���� �� ������ 
    background.loadFromFile("background.png");
    textimage.loadFromFile("text.png");
    textimage.createMaskFromColor(sf::Color::White);
    text.loadFromImage(textimage);
    backgSprite.setTexture(background);
    textSprite.setTexture(text);
    textSprite.setScale(3.5f, 3.5f);
    textSprite.setPosition(93, 100);
    bool ismenu = true;
    // �������� �������� ���������
    while (ismenu == true) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        window.clear();
        if (IntRect(60, 450, 173, 97.5).contains(Mouse::getPosition(window)) and Mouse::isButtonPressed(Mouse::Left)) {
            ismenu = false; // ���� ���������� �������� ������ �����, ���� �����������
        }
        window.clear();
        if (IntRect(287, 450, 173, 97.5).contains(Mouse::getPosition(window)) and Mouse::isButtonPressed(Mouse::Left)) {
            window.close();
            ismenu = false; // ���� ���������� �������� ������ �����, ��� �����������
        }
        //���������� �������� ����
        
        window.draw(backgSprite);
        window.draw(textSprite);
        window.draw(Start.ButtonSprite);
        window.draw(Exit.ButtonSprite);
        window.display();
    }

}