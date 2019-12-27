#pragma once


#include "engine/types.h"

typedef struct
{
    int uvX;
    int uvY;
    uint32 textureID;
} FontGlyph;

typedef struct
{
    FontGlyph * glyphs;
} Font;


/// Load the font library.
/// @return 0 if success, otherwise, a positive number.
int initFontLibrary();

/// Unload and destroy the font library.
/// @return 0 if success, otherwise, a positive number.
int destroyFontLibrary();

/// Load a font from a file. This allocate the font on the heap.
/// Creates a bitmap with the glyphes for the set of requested char (e.g., 'A','Z').
/// Use the ASCII representation and order (e.g., 'A','z' to load all uppercases and lowercases).
/// @param path Font file.
/// @param fontSizeInPx Size of the font (heigh in pixels)
/// @param charStart First character to load from ASCII (e.g., 'a')
/// @param charEnd Last character to load from ASCII (e.g., 'z')
/// @return The loaded font or NULL if error
Font * loadFontFromFile(const char * path, int fontSixeInPx, int charStart, int charEnd);

/// Free the font memory.
/// @param font Pointer to the font to free
void destroyFont(Font * font);

