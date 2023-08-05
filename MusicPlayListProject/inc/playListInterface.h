#ifndef PLAYERNTERFACE
#define PLAYERNTERFACE
#include <iostream>
#include <vector>
#include <stack>
#include "song.h"
#include <unordered_set>

class IPlayList
{
public:
    virtual std ::string getPlaylistName() = 0;
    virtual void showSongs() = 0;
    virtual std ::string previousSong() = 0;
    virtual std ::string nextSong() = 0;
    virtual bool addSong(std ::string songName) = 0;
    virtual bool removeSong(int index) = 0;
    virtual void moveUp(int index) = 0;
    virtual void moveDown(int index) = 0;
    virtual ISong *getSong(int index) = 0;
    virtual int totalSongs() = 0;
};
#endif