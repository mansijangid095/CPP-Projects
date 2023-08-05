// #include "../inc/player.h"
#include "../inc/musicLibrary.h"
#include "../inc/errorHandlingWithInputs.h"
class Menus
{
    IMusicLibrary *myLibrary;
    IPlayList *globalPlaylist;

public:
    Menus(IMusicLibrary *myLibrary);
    void mainMenu();
    void mainMenuFunctions(int input, int &songIndex);
    void libraryMenu();
    void goToPlaylist();
    void globalSongs();
    void showGlobalSongs();
    void editPlayList(int index);
    void editPlayListFunctions(IPlayList *currentPlaylist, bool &isValid, bool &isplaying);
};