#include "ResourceHolder.h"

ResourceHolder::ResourceHolder()
    :m_textures()
{
}

sf::Texture& ResourceHolder::getTexture(std::string path)
{
    const auto& pairFound = m_textures.find(path);
    if (pairFound != m_textures.end())
    {

        return pairFound->second;
    }
    else
    {
        auto& texture = m_textures[path];
        texture.loadFromFile(path);
        return texture;
    }
}

