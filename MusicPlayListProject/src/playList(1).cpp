#include "../inc/playList.h"

PlayList ::PlayList(std ::string playListName, std ::vector<ISong *> songs)
{
    this->playListName = playListName;
    this->songs = songs;
}
std ::string PlayList ::getPlaylistName()
{
    return playListName;
}
int PlayList ::totalSongs()
{
    return songs.size();
}
void PlayList ::showSongs()
{
    std ::cout << "The Songs Are : " << std ::endl;
    for (int songIndex = 0; songIndex < songs.size(); songIndex++)
    {
        std ::cout << songIndex + 1 << " " << songs[songIndex]->getTitle() << std ::endl;
    }
    std ::cout << std ::endl;
}

std ::string PlayList ::previousSong()
{
    std ::cout << currentSongIndex << std ::endl;
    if (currentSongIndex == -1)
    { 
        currentSongIndex=0;
        songs[currentSongIndex]->playSong();
        return songs[currentSongIndex]->getTitle();
    }
    if (currentSongIndex == 0)
    {
        currentSongIndex = songs.size();
    }
    currentSongIndex--;
    songs[currentSongIndex]->playSong();
    return songs[currentSongIndex]->getTitle();
}
std ::string PlayList ::nextSong()
{
    if (currentSongIndex == -1)
    { 
        currentSongIndex++;
        songs[currentSongIndex]->playSong();
        return songs[currentSongIndex]->getTitle();
    }
    if (currentSongIndex == songs.size() - 1)
    {
        currentSongIndex = -1;
    }
    currentSongIndex++;
    songs[currentSongIndex]->playSong();
    return songs[currentSongIndex]->getTitle();
}
bool PlayList ::addSong(std ::string songName)
{
    if (!songsHashSet.count(songName))
    {
        ISong *song = new Song(songName);
        songs.push_back(song);
        songsHashSet.insert(songName);
        return true;
    }
    std ::cout << "This song is already contained in the playList " << std ::endl;
    return false;
}
bool PlayList ::removeSong(int index)
{
    if (index < songs.size() && index >= 0)
    {
        std ::string song = songs[index]->getTitle();
        songs.erase(songs.begin() + index);
        songsHashSet.erase(song);
        std ::cout << song << " is successfully removed " << std ::endl;
        return true; 
    }
    std ::cout << "Song does not exist in the playlist " << std ::endl;
    return false;
}
void PlayList ::moveUp(int index)
{
    std ::cout << index << std ::endl;
    if (index > 0 && index < songs.size())
    {
        std ::string temp = songs[index]->getTitle();
        songs[index]->setTitle(songs[index - 1]->getTitle());
        songs[index - 1]->setTitle(temp);
    }
    else if (index == 0)
    {
        std ::string temp = songs[index]->getTitle();
        songs[index]->setTitle(songs[songs.size() - 1]->getTitle());
        songs[songs.size() - 1]->setTitle(temp);
    }
    else
    {
        std ::cout << "Wrong index !" << std ::endl;
    }
}
void PlayList ::moveDown(int index)
{
    if (index >= 0 && index < songs.size() - 1 && songs.size() > 1)
    {
        std ::string temp = songs[index]->getTitle();
        songs[index]->setTitle(songs[index + 1]->getTitle());
        songs[index + 1]->setTitle(temp);
    }
    else if (index == songs.size() && songs.size() > 1)
    {
        std ::string temp = songs[index]->getTitle();
        songs[index]->setTitle(songs[0]->getTitle());
        songs[0]->setTitle(temp);
    }
    else
    {
        std ::cout << "Wrong index !" << std ::endl;
    }
}

ISong *PlayList::getSong(int index)
{
    return songs[index];
}
