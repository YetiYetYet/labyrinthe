#include "header.h"

void gagner(Donnee* data){
  if(data->tableau[data->heros.y][data->heros.x] == 5){
    data->terminer = 1;
  }
}

void victoire(Donnee* data){
  musiqueVictoire(data);
  SDL_BlitSurface(data->img_victoire, NULL, SDL_GetWindowSurface(data->Fenetre), NULL);
  SDL_UpdateWindowSurface(data->Fenetre);
  while(data->terminer != -1){
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT || event.key.keysym.sym==SDLK_ESCAPE || event.key.keysym.sym==SDLK_q){data->terminer = -1;}
    }
  }
}