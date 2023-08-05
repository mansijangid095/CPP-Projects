#include "../inc/menus.h"

Menus::Menus(IMusicLibrary *myLibrary)
{
    this->myLibrary = myLibrary;
}

void Menus::globalSongs()
{
    std ::vector<ISong *> globalSongs;
    globalPlaylist = new PlayList("Global PlayList", globalSongs);
    globalPlaylist->addSong("Song1");
    globalPlaylist->addSong("Song2");
    globalPlaylist->addSong("Song3");
    globalPlaylist->addSong("Song4");
    globalPlaylist->addSong("Song5");
}

void Menus ::showGlobalSongs()
{
    globalPlaylist->showSongs();
}

void Menus ::mainMenu()
{
    ErrorHandling<int> errorHandling;
    globalSongs();
    int songIndex = -1;
    while (true)
    {
        showGlobalSongs();
        std ::cout << "1. Play Song \n2. Pause Song \n3. MyLibrary\n4. Exit" << std ::endl;
        int input;
        errorHandling.errorHandlingWithUserInput(input);
        mainMenuFunctions(input, songIndex);
    }
}

void Menus ::mainMenuFunctions(int index, int &songIndex)
{
    ErrorHandling<int> errorHandling;
    switch (index)
    {
    case 1:
        std ::cout << "Enter song index who want to play" << std ::endl;
        errorHandling.errorHandlingWithUserInput(songIndex);
        if (songIndex <= 0 || songIndex > globalPlaylist->totalSongs())
        {
            std ::cout << "this index song not exist!" << std ::endl;
            break;
        }
        globalPlaylist->getSong(songIndex - 1)->playSong();
        break;
    case 2:
        if (songIndex != -1)
            globalPlaylist->getSong(songIndex - 1)->pauseSong();
        else
            std ::cout << "No song is playing" << std ::endl;
        break;
    case 3:
        libraryMenu();
        break;
    case 4:
        std ::cout << "Exiting" << std ::endl;
        exit(0);
    default:
        std ::cout << "Wrong index !" << std ::endl;
        break;
    }
}

void Menus ::libraryMenu()
{
    ErrorHandling<int> errorHandling;
    bool isValid = true;
    while (isValid)
    {
        std ::cout << "Choose songs from this global playlist for your playlist !" << std ::endl;
        globalPlaylist->showSongs();
        std ::cout << "the playlists are : " << std ::endl;
        myLibrary->showPlayLists();
        std ::cout << "1. Create New PlayList\n2. Remove Existing PlayList\n3. Edit PlayList\n4. Back" << std ::endl;
        int input;
        int index;
        std ::string name;
        errorHandling.errorHandlingWithUserInput(input);
        switch (input)
        {
        case 1:
            std ::cout << "Enter New PlayList Name: " << std ::endl;
            std ::cin.ignore();
            getline(std ::cin, name);
            myLibrary->createNewPlayList(name);
            std ::cout << std ::endl;
            break;
        case 2:
            std ::cout << "Enter PlayList index to remove: ";
            errorHandling.errorHandlingWithUserInput(index);
            myLibrary->removePlayList(index);
            std ::cout << std ::endl;
            break;
        case 3:
            goToPlaylist();
            break;
        case 4:
            isValid = false;
            break;
        default:
            std ::cout << "Wrong index!" << std ::endl;
            break;
        }
    }
}
void Menus ::goToPlaylist()
{
    ErrorHandling<int> errorHandling;
    std ::cout << "Enter playlist Index in which you want to go: " << std ::endl;
    int index;
    errorHandling.errorHandlingWithUserInput(index);
    editPlayList(index);
}

void Menus ::editPlayList(int index)
{
    if (index <= 0 || index > myLibrary->totalPlaylists())
    {
        std ::cout << "this playlist index does not exist!" << std ::endl;
        return;
    }
    IPlayList *currentPlaylist = myLibrary->getPlayList(index - 1);
    bool isValid = true;
    bool isplaying = false;
    while (isValid)
    {
        std ::cout << "Your playlist name: " << currentPlaylist->getPlaylistName() << std ::endl;
        currentPlaylist->showSongs();
        std ::cout << "1. Play Song \n2. Pause Song\n3. Add Song\n4. Remove Song\n5. Previous Song\n6. Next Song\n7. "
             << "Move Up\n8. MoveDown\n9. Back\n"
             << std ::endl;
        editPlayListFunctions(currentPlaylist, isValid, isplaying);
    }
}
void Menus ::editPlayListFunctions(IPlayList *currentPlaylist, bool &isValid, bool &isplaying)
{
    ErrorHandling<int> errorHandling;
    int input;
    int index;
    std ::string songName;

    std ::cout << "enter operation you want to perform : " << std ::endl;
    errorHandling.errorHandlingWithUserInput(input);
    switch (input)
    {
    case 1:
        std ::cout << "Enter song index you want to play :";
        errorHandling.errorHandlingWithUserInput(index);
        if (index <= 0 || index > currentPlaylist->totalSongs())
        {
            std ::cout << "this index song not exist!" << std ::endl;
            break;
        }
        isplaying = true;
        currentPlaylist->getSong(index - 1)->playSong();
        break;
    case 2:
        if (isplaying)
            currentPlaylist->getSong(index - 1)->pauseSong();
        else
            std ::cout << "no song is playing so cannot be paused" << std ::endl;
        isplaying = false;
        break;
    case 3:
        std ::cout << "Enter song index you want to add from global playlist : ";
        errorHandling.errorHandlingWithUserInput(index);
        if (index <= 0 || index > globalPlaylist->totalSongs())
        {
            std ::cout << "This index song does not exist" << std ::endl;
        }
        if (currentPlaylist->addSong(globalPlaylist->getSong(index - 1)->getTitle()))
        {
            std ::cout << globalPlaylist->getSong(index - 1)->getTitle() << " is added" << std ::endl;
        }

        break;
    case 4:
        std ::cout << "Enter Song Index you want to remove : ";
        errorHandling.errorHandlingWithUserInput(index);
        if (index <= 0 || index > currentPlaylist->totalSongs())
        {
            std ::cout << "this index song not exist!" << std ::endl;
            break;
        }
        currentPlaylist->removeSong(index - 1);
        break;
    case 5:
        if (currentPlaylist->totalSongs() == 0)
        {
            std ::cout << "No song in this playlist. please add songs in the playlist firstly" << std ::endl;
        }
        else
            std ::cout << "The previous song is : " << currentPlaylist->previousSong() << " is Playing" << std ::endl;
        break;
    case 6:
        if (currentPlaylist->totalSongs() == 0)
        {
            std ::cout << "No song in this playlist. please add songs in the playlist firstly" << std ::endl;
        }
        else
            std ::cout << "The next song is : " << currentPlaylist->nextSong() << " is Playing" << std ::endl;
        break;
    case 7:
    std ::cout << "Enter index you want to move up" << std ::endl;
        errorHandling.errorHandlingWithUserInput(index);
        currentPlaylist->moveUp(index - 1);
        break;
    case 8:
    std ::cout << "Enter index you want to move down" << std ::endl;
        errorHandling.errorHandlingWithUserInput(index);
        currentPlaylist->moveDown(index - 1);
        break;
    case 9:
        isValid = false;
        break;
    default:
        std ::cout << "This index song not exists!" << std ::endl;
        break;
    }
}
