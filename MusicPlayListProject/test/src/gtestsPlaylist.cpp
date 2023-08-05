#include "../../inc/playList.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../inc/songMocking.h"

using testing::Return;

class PlayerTest : public testing::Test
{
public:
    std ::string playlistName;
    std ::vector<ISong *> mockSongs;
    IPlayList *playlist;
    MockSong mock1, mock2, mock3, mock4;
    void SetUp() override
    {
        std ::string playerName = "PlayerTest";
        mockSongs.push_back(&mock1);
        mockSongs.push_back(&mock2);
        mockSongs.push_back(&mock3);
        mockSongs.push_back(&mock4);
        playlist = new PlayList(playerName, mockSongs);
    }
    void TearDown() override
    {
        delete playlist;
    }
};

TEST_F(PlayerTest, previousSongTest)
{

    EXPECT_CALL(*(MockSong *)(mockSongs[0]), getTitle()).WillRepeatedly(Return("Song 1"));
    EXPECT_CALL(*(MockSong *)(mockSongs[0]), playSong()).Times(2);
    EXPECT_CALL(*(MockSong *)(mockSongs[1]), getTitle()).Times(1).WillRepeatedly(Return("Song 2"));
    EXPECT_CALL(*(MockSong *)(mockSongs[1]), playSong()).Times(1);
    EXPECT_CALL(*(MockSong *)(mockSongs[2]), getTitle()).WillRepeatedly(Return("Song 3"));
    EXPECT_CALL(*(MockSong *)(mockSongs[2]), playSong()).Times(1);
    EXPECT_CALL(*(MockSong *)(mockSongs[3]), getTitle()).WillRepeatedly(Return("Song 4"));
    EXPECT_CALL(*(MockSong *)(mockSongs[3]), playSong()).Times(2);

    EXPECT_EQ(playlist->previousSong(), "Song 1");
    EXPECT_EQ(playlist->previousSong(), "Song 4");
    EXPECT_EQ(playlist->previousSong(), "Song 3");
    EXPECT_EQ(playlist->previousSong(), "Song 2");
    EXPECT_EQ(playlist->previousSong(), "Song 1");
    EXPECT_EQ(playlist->previousSong(), "Song 4");
}

TEST_F(PlayerTest, nextSongTest)
{
    EXPECT_CALL(*(MockSong *)(mockSongs[0]), getTitle()).WillRepeatedly(Return("Song 1"));
    EXPECT_CALL(*(MockSong *)(mockSongs[0]), playSong()).Times(2);
    EXPECT_CALL(*(MockSong *)(mockSongs[1]), getTitle()).Times(1).WillRepeatedly(Return("Song 2"));
    EXPECT_CALL(*(MockSong *)(mockSongs[1]), playSong()).Times(1);
    EXPECT_CALL(*(MockSong *)(mockSongs[2]), getTitle()).WillRepeatedly(Return("Song 3"));
    EXPECT_CALL(*(MockSong *)(mockSongs[2]), playSong()).Times(1);
    EXPECT_CALL(*(MockSong *)(mockSongs[3]), getTitle()).WillRepeatedly(Return("Song 4"));
    EXPECT_CALL(*(MockSong *)(mockSongs[3]), playSong()).Times(1);
    EXPECT_EQ(playlist->nextSong(), "Song 1");
    EXPECT_EQ(playlist->nextSong(), "Song 2");
    EXPECT_EQ(playlist->nextSong(), "Song 3");
    EXPECT_EQ(playlist->nextSong(), "Song 4");
    EXPECT_EQ(playlist->nextSong(), "Song 1");
}

TEST_F(PlayerTest, addSong)
{
    EXPECT_EQ(playlist->addSong("song 1"), true);
    EXPECT_EQ(playlist->addSong("song 2"), true);
    EXPECT_EQ(playlist->addSong("song 1"), false);
    EXPECT_EQ(playlist->addSong("song 2"), false);
}

TEST_F(PlayerTest, removeSong)
{
    std ::vector <ISong *> songs;
    std ::string name = "Player1";
    EXPECT_CALL(*(MockSong *)(mockSongs[0]), getTitle()).WillOnce(Return("Song 1"));
    EXPECT_CALL(*(MockSong *)(mockSongs[1]), getTitle()).WillOnce(Return("Song 2"));
    EXPECT_CALL(*(MockSong *)(mockSongs[2]), getTitle()).WillOnce(Return("Song 3"));
    EXPECT_CALL(*(MockSong *)(mockSongs[3]), getTitle()).WillOnce(Return("Song 4"));
    EXPECT_EQ(playlist->removeSong(3), true);
    EXPECT_EQ(playlist->removeSong(1), true);
    EXPECT_EQ(playlist->removeSong(1), true);
    EXPECT_EQ(playlist->removeSong(0), true);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
