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

sf::Font& ResourceHolder::getFont(std::string path)
{
    const auto& pairFound = m_fonts.find(path);
    if (pairFound != m_fonts.end())
    {

        return pairFound->second;
    }
    else
    {
        auto& font = m_fonts[path];
        font.loadFromFile(path);
        return font;
    }
}

//No error checking on the buffer!
sf::Sound& ResourceHolder::getSound(std::string path)
{
    sf::SoundBuffer buffer;
    buffer.loadFromFile(path);

    const auto& pairFound = m_sounds.find(path);
    if (pairFound != m_sounds.end())
    {

        return pairFound->second;
    }
    else
    {
        auto& sound = m_sounds[path];
        sound.setBuffer(buffer);
        return sound;
    }
}

