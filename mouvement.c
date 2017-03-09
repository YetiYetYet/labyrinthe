#include "header.h"

Point coor[NDIR] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

void transition(Donnee* data,Entite* e,int dir){
  SDL_Rect position;
  int temps = 5;
  position.x = data->heros.x * TAILLEELMT;
  position.y = data->heros.y * TAILLEELMT;
  int x = e->x + coor[dir].x;
  int y = e->y + coor[dir].y;
  int i;
  int j;
  j = 0;
  if(prochaine_pos(data, x, y)){
    switch(dir){
      case HAUT:
      for(i=0; i<4; i++){
        position.y = position.y - 5;
        if(j==0){
          data->img_heros = chargerImg("./Image/moupi2.bmp");
          j=1;
          placerLabyrinthe(data);
          SDL_Delay(temps);
          champsVision(data, i*5, HAUT);
          SDL_BlitSurface (data->img_heros, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
          SDL_UpdateWindowSurface(data->Fenetre);
        }
        if(j==1){
          data->img_heros = chargerImg("./Image/moupi.bmp");
          j=0;
          placerLabyrinthe(data);
          SDL_Delay(temps);
          champsVision(data, i*5, HAUT);
          SDL_BlitSurface (data->img_heros, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
          SDL_UpdateWindowSurface(data->Fenetre);
        }
      }
      break;
      case BAS:
      for(i=0; i<4; i++){
        position.y = position.y + 5;
        if(j==0){
          data->img_heros = chargerImg("./Image/moupi2.bmp");
          j=1;
          placerLabyrinthe(data);
          SDL_Delay(temps);
          champsVision(data, i*5, BAS);
          SDL_BlitSurface (data->img_heros, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
          SDL_UpdateWindowSurface(data->Fenetre);
        }
        if(j==1){
          data->img_heros = chargerImg("./Image/moupi.bmp");
          j=0;
          placerLabyrinthe(data);
          SDL_Delay(temps);
          champsVision(data, i*5, BAS);
          SDL_BlitSurface (data->img_heros, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
          SDL_UpdateWindowSurface(data->Fenetre);
        }
      }
      break;
      case GAUCHE:
      for(i=0; i<4; i++){
        position.x = position.x - 5;
        if(j==0){
          data->img_heros = chargerImg("./Image/moupi2.bmp");
          j=1;
          placerLabyrinthe(data);
          SDL_Delay(temps);
          champsVision(data, i*5, GAUCHE);
          SDL_BlitSurface (data->img_heros, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
          SDL_UpdateWindowSurface(data->Fenetre);
        }
        if(j==1){
          data->img_heros = chargerImg("./Image/moupi.bmp");
          j=0;
          placerLabyrinthe(data);
          SDL_Delay(temps);
          champsVision(data, i*5, GAUCHE);
          SDL_BlitSurface (data->img_heros, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
          SDL_UpdateWindowSurface(data->Fenetre);
        }
      }
      break;
      case DROITE:
      for(i=0; i<4; i++){
        position.x = position.x + 5;
        if(j==0){
          data->img_heros = chargerImg("./Image/moupi2.bmp");
          j=1;
          placerLabyrinthe(data);
          SDL_Delay(temps);
          champsVision(data, i*5, DROITE);
          SDL_BlitSurface (data->img_heros, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
          SDL_UpdateWindowSurface(data->Fenetre);
        }
        if(j==1){
          data->img_heros = chargerImg("./Image/moupi.bmp");
          j=0;
          placerLabyrinthe(data);
          SDL_Delay(temps);
          champsVision(data, i*5, DROITE);
          SDL_BlitSurface (data->img_heros, NULL, SDL_GetWindowSurface(data->Fenetre), &position);
          SDL_UpdateWindowSurface(data->Fenetre);
        }
      }
    }
  }
}

int prochaine_pos(Donnee* data, int x, int y) {
  if(x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR && data->tableau[y][x] == GEMME){
    data->tableau[y][x] = 0;
    data->vision++;
  }
  return x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR && data->tableau[y][x] != MUR;
}

void deplacer_entite(Donnee* data, Entite* e, int dir) {
  int x = e->x + coor[dir].x;
  int y = e->y + coor[dir].y;
  
  if(prochaine_pos(data, x, y)) {
    e->x = x;
    e->y = y;
  }
}

