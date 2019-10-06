#pragma once

#include "engine/libmath.h"
#include "engine/sprite.h"
#include "engine/animation.h"
#include "engine/collision.h"
#include "engine/engine.h"
#include "config.h"


// -----------------------------------------------------------------------------
// Data
// -----------------------------------------------------------------------------

typedef struct
{
    vecf2 position;
    float direction; // Vect director on x axis
    float velocity; // Boat can move only on x axis
    Animation anim;
    Sprite * spritesArray[GAME_BOAT_ANIM_NB_FRAMES];
} Boat;

typedef struct
{
    vecf2 position;
    float velocity; // Moves only on Y axis
    RectCollider collider;
    Animation anim;
    Sprite * spritesArray[GAME_SHARK_ANIM_NB_FRAMES];
} Shark;

typedef struct
{
    vecf2 position;
    float velocity; // Moves only on Y axis
    RectCollider collider;
    Sprite * sprite;
} Anchor;

typedef struct
{
    vecf2 position;
    Animation anim;
    Sprite * spritesArray[GAME_EXPLOSION_ANIM_NB_FRAMES];
} Explosion;

typedef struct
{
    vecf2 cameraRect; // Rectangle of camera vision
    Boat boat;
    Engine * engine; // TODO: to remove if not used anymore
    Shark * sharksArray[GAME_NB_MAX_SHARKS];
    Explosion * explosionsArray[GAME_NB_MAX_SHARKS]; // Basically, only sharks explode
    Anchor * anchor; // Anchor not NULL means boat is firing
    Sprite * background;
    Sprite * foreground;
    Sprite * textBitMap[10]; // The font is only 10 chars
    int isPaused;
    int score;
    float remainingTime; // Remaining time
    float timeAtStartInSec; // Available amount of time at beginning
} Game;


// -----------------------------------------------------------------------------
// Methods
// -----------------------------------------------------------------------------

void gameInit(Game * _game);
void gameDestroy(Game * _game);
void gameUpdate(Game * _game, float _dt);
void gameFixedUpdate(Game * _game, float _dt);
void gameRender(Game * _game);
