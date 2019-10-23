#pragma once

#include "engine/libmath.h"
#include "engine/sprite.h"
#include "engine/animation.h"
#include "engine/collision.h"
#include "engine/engine.h"

#include "gameplay/config.h"
#include "gameplay/game_app.h"


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
} FishingTime;


// -----------------------------------------------------------------------------

void fishingTimeInit(Engine * _engine, GameApp * _gameapp, FishingTime * _game);
void fishingTimeDestroy(Engine * _engine, GameApp * _gameapp, FishingTime * _game);
void fishingTimeUpdate(Engine * _engine, GameApp * _gameapp, FishingTime * _game, float _dt);
void fishingTimeFixedUpdate(Engine * _engine, GameApp * _gameapp, FishingTime * _game, float _dt);
void fishingTimeRender(Engine * _engine, GameApp * _gameapp, FishingTime * _game);
