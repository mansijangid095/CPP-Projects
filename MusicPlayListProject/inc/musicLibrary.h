#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "musicLibraryInterface.h"

class MusicLibrary : public IMusicLibrary
{
    std ::string playListName;
    std ::vector<IPlayList *> playLists;
    std ::unordered_set<std ::string> playListsHashSet;

public:
    MusicLibrary(std ::string playListName, std ::vector<IPlayList *> playlists);
    bool createNewPlayList(std ::string playListName);
    void showPlayLists();
    int totalPlaylists();
    bool removePlayList(int index);
    int editPlayLists();
    IPlayList *getPlayList(int index);
};

#endif