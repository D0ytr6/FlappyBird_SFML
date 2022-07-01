#include "Pipe.h"

	Pipe::Pipe(string F, int X) {
        File = F;
        x = X;
        image.loadFromFile(File);
        image2.loadFromFile(File);
        image2.flipHorizontally();
        texture.loadFromImage(image);
        texture2.loadFromImage(image2);
        sprite.setTexture(texture);
        sprite2.setTexture(texture2);
        sprite.setScale(0.5f, 0.5f);
        sprite2.setScale(0.5f, 0.5f);
        sprite2.setRotation(180.f);
        sprite2.setPosition(x + 80, RandY());
        sprite.setPosition(x, sprite2.getPosition().y + 220);


}
    int Pipe::RandY() {
        return rand() % 300 + 100;
    }
    void Pipe::update_pipe(float times) {
        y1 = 0;
        y2 = 0;
        Move = -0.15;
        x = Move * times;
        sprite.move(x, y1);
        sprite2.move(x, y2);
        check = sprite.getPosition().x;
        check2 = sprite2.getPosition().x;
        if (check2 < 0)
        {
            counter++;
            sprite2.setPosition(746.5, RandY());
            sprite.setPosition(666.5, sprite2.getPosition().y + 220);

        }
    }
    void Pipe::draw_pipe(RenderWindow& window) {
        window.draw(sprite);
        window.draw(sprite2);
    
    }