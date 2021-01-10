

//Libraries
#include "ResourceManager.h"

TextureCache ResourceManager::_textureCache;

GLTexture ResourceManager::getText(std::string texturePath) {
    return _textureCache.getTexture(texturePath);
}