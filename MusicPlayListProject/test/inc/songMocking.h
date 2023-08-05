#include"../../inc/song.h"
#include<gtest/gtest.h>
#include<gmock/gmock.h>

class MockSong : public ISong
{
public:
    MOCK_METHOD(std ::string, getTitle, (), (override));
    MOCK_METHOD(void, setTitle, (std ::string title), (override));
    MOCK_METHOD(void, playSong, (), (override));
    MOCK_METHOD(void, pauseSong, (), (override));
};
