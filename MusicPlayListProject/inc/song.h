#ifndef SONG_H
#define SONG_H
#include "songInterface.h"

class Song : public ISong
{
    std ::string title;
    bool isPlaying;

public:
    Song(std ::string title);
    std ::string getTitle();
    void setTitle(std ::string title);
    void playSong();
    void pauseSong();
};

#endif