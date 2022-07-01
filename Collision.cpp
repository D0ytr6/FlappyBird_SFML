#include "Collision.h"
bool Collisions(Sprite& birdsprite, Sprite& sprite1, Sprite& sprite2, Sprite& sprite3, Sprite& sprite4, Sprite& sprite5, Sprite& sprite6) {
    // завантажуємо спрайти перешкод та головного героя, формуємо з них прямокутники
    FloatRect BirdSprite = birdsprite.getGlobalBounds();
    FloatRect Sprite1 = sprite1.getGlobalBounds();
    FloatRect Sprite2 = sprite2.getGlobalBounds();
    FloatRect Sprite3 = sprite3.getGlobalBounds();
    FloatRect Sprite4 = sprite4.getGlobalBounds();
    FloatRect Sprite5 = sprite5.getGlobalBounds();
    FloatRect Sprite6 = sprite6.getGlobalBounds();
    int CheckY = birdsprite.getPosition().y;
    // Перевіряємо чи пересікаються прямокутники між собою, або з землею
    if (BirdSprite.intersects(Sprite1) or BirdSprite.intersects(Sprite2) or BirdSprite.intersects(Sprite3) or BirdSprite.intersects(Sprite4) or BirdSprite.intersects(Sprite5) or BirdSprite.intersects(Sprite6) or CheckY > 685) {
        return true;
    }
    else
    {
        return false;
    }
}