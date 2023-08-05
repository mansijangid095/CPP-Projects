#include "../../inc/musicLibrary.h"
#include <gtest/gtest.h>

class PlaylistTest : public testing ::Test
{
public:
    IMusicLibrary *playlists;
    void SetUp()
    {
        std ::string libraryName = "My library";
        std ::vector<IPlayList *> playlists;
        
        playlists = new MusicLibrary(libraryName, );
    }
    void tearDown()
    {
        delete playlists;
    }
};

TEST_F(PlaylistTest, createPlaylistTest)
{
    EXPECT_EQ(playlists->createNewPlayList("Playlist1TEST"), true);
    EXPECT_EQ(playlists->createNewPlayList("Playlist12TEST"), true);
    EXPECT_EQ(playlists->createNewPlayList("Playlist1TEST"), false);
    EXPECT_EQ(playlists->createNewPlayList("Playlist1TEST"), false);
}

TEST_F(PlaylistTest, totalPlaylistsTest)
{
    playlists->createNewPlayList("playlist1");
    playlists->createNewPlayList("playlist2");
    playlists->createNewPlayList("playlist3");
    playlists->createNewPlayList("playlist4");

    EXPECT_EQ(playlists->totalPlaylists(), 4);
}

TEST_F(PlaylistTest, removePlaylistTest)
{
    playlists->createNewPlayList("playlist1");
    playlists->createNewPlayList("playlist2");
    playlists->createNewPlayList("playlist3");
    playlists->createNewPlayList("playlist4");

    EXPECT_EQ(playlists->removePlayList(1), true);
    EXPECT_EQ(playlists->removePlayList(2), true);
    EXPECT_EQ(playlists->removePlayList(5), false);
    EXPECT_EQ(playlists->removePlayList(-1), false);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}