#include "../inc/musicLibrary.h"
MusicLibrary ::MusicLibrary(std ::string playListName, std ::vector<IPlayList *> playlists){
    this->playListName = playListName;
    this->playLists = playLists;
}
bool MusicLibrary ::createNewPlayList(std ::string playListName)
{
    if (!playListsHashSet.count(playListName))
    {
        std ::vector<ISong *> songs;
        IPlayList* newPlaylist = new PlayList(playListName, songs);
        playLists.push_back(newPlaylist);
        playListsHashSet.insert(playListName);
        return true;
    }
    std ::cout << "This playlist name is already added please choose a different name " << std ::endl;
    return false;
}
int MusicLibrary ::totalPlaylists()
{
    return playLists.size();
}
void MusicLibrary ::showPlayLists()
{
    for (int index = 0; index < playLists.size(); index++)
    {
        std ::cout << index + 1 << ". " << playLists[index]->getPlaylistName() << std ::endl;
    }
    std ::cout << std ::endl;
}
bool MusicLibrary ::removePlayList(int index)
{
    index--;
    if (playLists.size() > index && index >= 0)
    {
        std ::string playListToBeRemoved = playLists[index]->getPlaylistName();
        playLists.erase(playLists.begin() + index);
        std ::cout << playListToBeRemoved << " is succesfully removed" << std ::endl;
        playListsHashSet.erase(playListToBeRemoved);
        return true;
    }
    std ::cout << "This playlist you want to remove is not exist" << std ::endl;
    return false;
}
int MusicLibrary ::editPlayLists()
{
    ErrorHandling<int> errorHandling;
    std ::cout << "Enter playList number you want to go: " << std ::endl;
    int playlistIndex;
    errorHandling.errorHandlingWithUserInput(playlistIndex);
    return playlistIndex - 1;
}

IPlayList *MusicLibrary ::getPlayList(int index){
    return playLists[index];
}

