#ifndef PLAYLISTINTERFACE_H
#define PLAYLISTINTERFACE_H
#include "playList.h"
#include "../inc/errorHandlingWithInputs.h"
class IMusicLibrary
{

public:
    virtual bool createNewPlayList(std ::string playListName) = 0;
    virtual void showPlayLists() = 0;
    virtual int totalPlaylists() = 0;
    virtual bool removePlayList(int index) = 0;
    virtual int editPlayLists() = 0;
    virtual IPlayList* getPlayList(int index) = 0;
};

#endif