#ifndef RAYLIB_EXTRAS_HPP
#define RAYLIB_EXTRAS_HPP

#include <raylib.h>

inline void DrawTextCentered(const char *text, Vector2 position, float fontSize, Color tint) {
    int textSize = MeasureText(text, fontSize);
    Vector2 drawPosition = {position.x - textSize / 2, position.y - fontSize / 2};
    DrawText(text, drawPosition.x, drawPosition.y, fontSize, tint);
}

inline void DrawTextCenteredEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint) {
    Vector2 textSize = MeasureTextEx(font, text, fontSize, spacing);
    Vector2 drawPosition = {position.x - textSize.x / 2, position.y - textSize.y / 2};
    DrawTextEx(font, text, drawPosition, fontSize, spacing, tint);
}

inline void DrawTextCenteredPro(Font font, const char *text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint) {
    Vector2 textSize = MeasureTextEx(font, text, fontSize, spacing);
    Vector2 drawPosition = {position.x - textSize.x / 2, position.y - textSize.y / 2};
    DrawTextPro(font, text, drawPosition, origin, rotation, fontSize, spacing, tint);
}

#endif //RAYLIB_EXTRAS_HPP
