#ifndef PLAYER_H
#define PLAYER_H 

#include"playListInterface.h"

class PlayList  : public IPlayList
{
    std ::vector<ISong*> songs;
    std ::unordered_set<std ::string> songsHashSet;
    std ::string playListName;
    int currentSongIndex = -1;
public:
 
    PlayList(std ::string playListName, std ::vector<ISong*> songs);
    std ::string getPlaylistName();
    void showSongs();
    std ::string previousSong();
    std ::string nextSong();
    bool addSong(std ::string songName);
    bool removeSong(int index);
    void moveUp(int index);
    void moveDown(int index); 
    ISong* getSong(int index); 
    int totalSongs(); 
};
#endif