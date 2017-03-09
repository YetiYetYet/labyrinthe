#include "header.h"

void musiqueDebut(Donnee * data){
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
  {
    printf("%s", Mix_GetError());
  }
  data->musique = Mix_LoadMUS("./Son/Ugh.mp3");
  Mix_PlayMusic(data->musique, 0);
  SDL_Delay(6400);
}

void musiqueJeu(Donnee* data){
  data->musique = Mix_LoadMUS("./Son/Rock.mp3");
  Mix_PlayMusic(data->musique, -1);
}

void musiqueVictoire(Donnee* data){
  data->musique = Mix_LoadMUS("./Son/Victoire.mp3");
  Mix_PlayMusic(data->musique, 0);
}