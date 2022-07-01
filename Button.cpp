#include "Button.h"

Button::Button(string F, int X, int Y, float Scalex, float Scaley) {
    File = F;
    x = X;
    y = Y;
    scaleX = Scalex;
    scaleY = Scaley;
    // завантажуємо текстуру та створємо спрайти кнопки
    button.loadFromFile(File);
    ButtonSprite.setTexture(button);
    ButtonSprite.setScale(scaleX, scaleY);
    ButtonSprite.setPosition(x, y);
}