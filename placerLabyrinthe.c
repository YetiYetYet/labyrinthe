#include "header.h"

void placerLabyrinthe(Donnee * data){
  int x, y;
  for(x = 0; x < LARGEUR; x++) {
    for(y = 0; y < HAUTEUR; y++) {
      SDL_Rect position;
      position.x = x * TAILLEELMT;
      position.y = y * TAILLEELMT;
      if(data->tableau[y][x] == MUR)
        SDL_BlitSurface (data->img_mur, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
      if(!data->tableau[y][x] == MUR || data->tableau[y][x] > 1)
        SDL_BlitSurface(data->img_sol, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
      if(data->tableau[y][x] == GEMME)
        SDL_BlitSurface(data->img_gemme, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
    }
  }
}

void tableau(Donnee* data) {
  int x, y;
  for(x = 0; x < LARGEUR; x++) {
    for(y = 0; y < HAUTEUR; y++) {
      SDL_Rect position;
      position.x = x * TAILLEELMT;
      position.y = y * TAILLEELMT;
      if(data->tableau[y][x] == MUR)
        SDL_BlitSurface (data->img_mur, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
      if(!data->tableau[y][x] == MUR || data ->tableau[y][x] > 1)
        SDL_BlitSurface(data->img_sol, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
      if(data->tableau[y][x] == GEMME)
        SDL_BlitSurface(data->img_gemme, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
    }
  }
  SDL_Rect position;
  position.x = data->heros.x * TAILLEELMT;
  position.y = data->heros.y * TAILLEELMT;
  SDL_BlitSurface (data->img_heros, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
}