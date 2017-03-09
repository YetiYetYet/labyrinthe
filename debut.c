// Cette partie du programme ne contient fonction qui gere la 'cinématique' du début

#include "header.h"

void debut(Donnee* data){
  if(!data->debug){ // La cinématique ne s'affiche pas si le mode developpeur est enclenché.
    SDL_Surface* fond;
    SDL_Surface* personnage;
    SDL_Rect position;

    position.y = 60;
    fond = chargerImg("./Image/debut.jpg");
    personnage = chargerImg("./Image/moupi.png");
    SDL_BlitSurface(fond, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
    position.x = 150;
    position.y = 170;
    SDL_BlitSurface(personnage, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
    SDL_UpdateWindowSurface(data->Fenetre);
    musiqueDebut(data);
  }
}