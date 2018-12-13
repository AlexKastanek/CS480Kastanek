//
// Created by mari on 12/9/18.
//

#ifndef SHOOTINGGALLERY_SOUND_H
#define SHOOTINGGALLERY_SOUND_H
#include <SDL2/SDL_mixer.h>
#include "window.h"
#define BG_MUSIC "../audio/westernBGMusic.mp3"
using namespace std;

class Sound{
public:
    Sound();
    ~Sound();
    void background();
    void audio(const char* &file);
    static Mix_Chunk *soundEffect;
    static Mix_Music *bgMusic;
private:
};


#endif //SHOOTINGGALLERY_SOUND_H
