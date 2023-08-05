#include"../../inc/song.h"
#include<gtest/gtest.h>

class SongTest : public testing ::Test{
    public:
    Song *song;
    Song *song1;
    void SetUp(){
        song = new Song("TestSong");
        song1 = new Song("Song number 1");
    }
    void TearDown(){
        delete song;
        delete song1;
    }
};

TEST_F(SongTest, getTitle){
    std ::string title = song->getTitle();
    std ::string title1 = song1->getTitle();
    EXPECT_EQ(title, "TestSong");
    EXPECT_EQ(title1, "Song number 1");
}

TEST_F(SongTest, setTitle){
    song->setTitle("Song 1");
    EXPECT_EQ(song->getTitle(), "Song 1");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}