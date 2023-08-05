#include "../inc/menus.h"

int main()
{
    std ::vector<IPlayList *> allPlaylists;
    IMusicLibrary *myLibrary = new MusicLibrary("My Library", allPlaylists);
    Menus menu(myLibrary);
    menu.mainMenu();
}