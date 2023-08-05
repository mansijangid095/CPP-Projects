#ifndef SONG_INTERFACE_H
#define SONG_INTERFACE_H
#include<iostream>
#include"../inc/errorHandlingWithInputs.h"

class ISong{  
    public:
    virtual std ::string getTitle() = 0;
    virtual void setTitle(std ::string title) = 0;   
    virtual void playSong() = 0;
    virtual void pauseSong() = 0;
};

#endif