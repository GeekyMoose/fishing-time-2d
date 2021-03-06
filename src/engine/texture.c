#include "engine/texture.h"

#include "engine/assertions.h"
#include "engine/log.h"
#include "engine/types.h"

#include <GL/glew.h>

Texture createTexture(const uint8* _buffer, int _width, int _height, int _channels)
{
    uint32 format;
    switch (_channels) {
        case 1:
            format = GL_RED;
            break;
        case 2:
            format = GL_RG;
            break;
        case 3:
            format = GL_RGB;
            break;
        case 4:
            format = GL_RGBA;
            break;
        default:
            format = GL_RGBA;
            ASSERT_MSG(FALSE, "[Texture] Invalid channels value %d", _channels);
            break;
    }

    uint32 textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, format, _width, _height, 0, format, GL_UNSIGNED_BYTE, _buffer);
    if (glGetError() != GL_NO_ERROR) {
        LOG_ERR("[Texture] Method glGetError failed with GLenum = %d", glGetError());
        ASSERT_MSG(FALSE, "[Texture] Method glGetError failed with GLenum = %d", glGetError());
    }

    glBindTexture(GL_TEXTURE_2D, 0);

    Texture texture;
    texture.id = textureID;
    texture.width = _width;
    texture.height = _height;

    return texture;
}

Texture createTextureFromImage(const Image* _image)
{
    return createTexture(_image->buffer, _image->width, _image->height, _image->channels);
}

void destroyTexture(Texture* _texture)
{
    ASSERT_MSG(_texture != NULL, "[Texture] Texture should not be NULL");

    if (_texture != NULL) {
        glDeleteTextures(1, &_texture->id);
    }
}
