#include "../inc/song.h"

Song::Song(std ::string title)
{
    this->title = title;
}

std ::string Song::getTitle()
{
    return title;
}

void Song ::setTitle(std ::string title)
{
    this->title = title;
}

void Song ::playSong()
{
    std ::cout << title << " is playing." << std ::endl;
}

void Song ::pauseSong()
{
    std ::cout << title << " is pausing." << std ::endl;
}
