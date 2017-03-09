#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL_mixer.h>
#include <SDL_image.h>

#define HAUTEUR 30
#define LARGEUR 30
#define TAILLEELMT 20

int niveau1 [HAUTEUR][LARGEUR] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
  1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 
  1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 
  1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 
  1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
  1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 
  1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 
  1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 
  1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 
  1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 
  1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1,
  1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 
  1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 
  1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 
  1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 
  1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 
  1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 
  1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 
  1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 
  1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 
  1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 2, 0, 1, 
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

int niveau2 [HAUTEUR][LARGEUR] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  1, 0, 2, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 
  1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 
  1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 
  1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 
  1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 
  1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 
  1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 
  1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 
  1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 
  1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 
  1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 
  1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 
  1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 
  1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 
  1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 
  1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 
  1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 
  1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 
  1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 
  1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 
  1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 
  1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 
  1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 
  1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 
  1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 
  1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 5, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

enum { SOL, MUR, DEPART, GEMME, NENT};

typedef struct {
  int x;
  int y;
} Entite;

enum { HAUT, BAS, DROITE, GAUCHE, NDIR };

typedef struct {
  int x;
  int y;
} Point;
Point coor[NDIR] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

typedef struct {
    SDL_Window * Fenetre;
    SDL_Surface* img_mur;
    SDL_Surface* img_heros;
    SDL_Surface* img_gemme;
    SDL_Surface* img_rectangle;
    SDL_Surface* img_victoire;
    SDL_Surface* img_cercle;
    SDL_Surface* img_sol;
    Mix_Music* musique;
    Entite heros;

    int terminer;
    int debug;
    int vision;
    int tableau[HAUTEUR][LARGEUR];
} Donnee;

SDL_Surface* chargerImg(const char* fileName) {
  SDL_Surface *image = IMG_Load(fileName);
  if (!image)
  {
     printf("Charger_Image: %s\n", IMG_GetError());
     return 0;
  }
  return image;
}

void ajouter_gemmes(Donnee* data, int nb) {
  int i;
  for(i = 0; i < nb; i++) {
    int x = rand() % LARGEUR;
    int y = rand() % HAUTEUR;
    if(data->tableau[y][x] == SOL) {
      data->tableau[y][x] = GEMME;
    } else {
      i--;
    }
  }
}

void cercle(Donnee* data){
  switch(data->vision){
    case 1:
    data->img_cercle = chargerImg("./Image/circle1.png");
    break;
    case 2:
    data->img_cercle = chargerImg("./Image/circle2.png");
    break;
    case 3:
    data->img_cercle = chargerImg("./Image/circle3.png");
    break;
    case 4:
    data->img_cercle = chargerImg("./Image/circle4.png");
    break;
    case 5:
    data->img_cercle = chargerImg("./Image/circle5.png");
    break;
    case 6:
    data->img_cercle = chargerImg("./Image/circle6.png");
    break;
    case 7:
    data->img_cercle = chargerImg("./Image/circle7.png");
  }
}

void champsVision(Donnee* data, int detail, int direction){
  cercle(data);
  SDL_Rect position;
  SDL_Rect positionCercle;

  positionCercle.x = ((data->heros.x-data->vision)*TAILLEELMT);
  positionCercle.y = ((data->heros.y-data->vision)*TAILLEELMT);

  // Haut
  position.x = 0;
  position.y = 0;
  position.w = LARGEUR*TAILLEELMT;
  if(direction == HAUT){
    position.h = ((data->heros.y*TAILLEELMT)-(data->vision*TAILLEELMT))-detail;
    positionCercle.y += -detail;
  }
  else if(direction == BAS){
    position.h = (data->heros.y*TAILLEELMT-data->vision*TAILLEELMT)+detail;
  }
  else{
    position.h = (data->heros.y*TAILLEELMT-data->vision*TAILLEELMT);
  }
  SDL_BlitSurface(data->img_rectangle, &position, SDL_GetWindowSurface(data->Fenetre), &position);

  // Bas
  position.x = 0;
  position.w = LARGEUR*TAILLEELMT;
  position.h = HAUTEUR*TAILLEELMT;
  if(direction == BAS){
    position.y = ((data->heros.y+1+(data->vision*1))*TAILLEELMT)+detail;
    positionCercle.y += detail;
  }
  else if(direction == HAUT){
    position.y = ((data->heros.y+1+(data->vision*1))*TAILLEELMT)-detail;
  }
  else{
    position.y = ((data->heros.y+1+(data->vision*1))*TAILLEELMT); 
  }
  SDL_BlitSurface(data->img_rectangle, &position, SDL_GetWindowSurface(data->Fenetre), &position);

  // Droite

  position.y = 0;
  position.w = LARGEUR*TAILLEELMT;
  position.h = HAUTEUR*TAILLEELMT;
  if(direction == DROITE){
    position.x = ((data->heros.x+1+(data->vision*1))*TAILLEELMT)+detail;
    positionCercle.x += detail;
  }
  else if(direction == GAUCHE){
    position.x = ((data->heros.x+1+(data->vision*1))*TAILLEELMT)-detail;
  }
  else{
    position.x = ((data->heros.x+1+(data->vision*1))*TAILLEELMT);  
  }
  SDL_BlitSurface(data->img_rectangle, &position, SDL_GetWindowSurface(data->Fenetre), &position);

  //gauche
  position.x = 0;
  position.y = 0;
  
  position.h = HAUTEUR*TAILLEELMT;
  if(direction == GAUCHE){
    position.w = ((data->heros.x-data->vision)*TAILLEELMT)-detail;
    positionCercle.x += -detail;
  }
  else if(direction == DROITE){
    position.w = ((data->heros.x-data->vision)*TAILLEELMT)+detail;
  }
  else{
    position.w = ((data->heros.x-data->vision)*TAILLEELMT);
  }
  SDL_BlitSurface(data->img_rectangle, &position, SDL_GetWindowSurface(data->Fenetre), &position);
  SDL_BlitSurface(data->img_cercle, NULL, SDL_GetWindowSurface(data->Fenetre), &positionCercle);
  SDL_UpdateWindowSurface(data->Fenetre);
}

void initialisation(Donnee* data, int debug) {
  int x, y;
  int nb_aleatoire = (rand()%2 + 1);
  printf("ugh %d\n", nb_aleatoire);
  
  data->Fenetre = SDL_CreateWindow(
    "Moupi doit trouver la sortie !",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    20*HAUTEUR,
    20*LARGEUR,
    SDL_WINDOW_SHOWN);

  data->img_mur = chargerImg("./Image/mur.bmp");
  data->img_heros = chargerImg("./Image/moupi2.bmp");
  data->img_rectangle = chargerImg("./Image/rectangle.png");
  data->img_victoire = chargerImg("./Image/Victoire.jpg");
  data->img_cercle = chargerImg("./Image/circle1.png");
  data->img_gemme = chargerImg("./Image/gom.png");
  data->img_sol = chargerImg("./Image/sol.png");
  data->vision = 1;
  data->terminer = 0;
  data->debug = debug;

  switch(nb_aleatoire){
    case 1:
    for(x = 0; x < LARGEUR; x++) {
      for(y = 0; y < HAUTEUR; y++) {
        if(niveau1[y][x] == 2){
          data->heros.x = x;
          data->heros.y = y;
          data->tableau == 0;
        }
        data->tableau[y][x] = niveau1[y][x]; 
      }
    }
    break;
    case 2:
    for(x = 0; x < LARGEUR; x++) {
      for(y = 0; y < HAUTEUR; y++) {
        if(niveau2[y][x] == 2){
          data->heros.x = x;
          data->heros.y = y;
          data->tableau == 0;
        }
        data->tableau[y][x] = niveau2[y][x]; 
      }
    }
    break;
  }
  ajouter_gemmes(data, 6);
  SDL_UpdateWindowSurface(data->Fenetre);
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

void loop_level1(Donnee* data) {
  tableau(data);
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    if(event.type == SDL_QUIT || event.key.keysym.sym==SDLK_ESCAPE || event.key.keysym.sym==SDLK_q){data->terminer = -1;}
    switch (event.type) {
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym) {
          case SDLK_RIGHT:
          transition(data, &data->heros, DROITE);
          deplacer_entite(data, &data->heros, DROITE);
          break;
          case SDLK_LEFT:
          transition(data, &data->heros, GAUCHE);
          deplacer_entite(data, &data->heros, GAUCHE);
          break;
          case SDLK_UP:
          transition(data, &data->heros, HAUT);
          deplacer_entite(data, &data->heros, HAUT);
          break;
          case SDLK_DOWN:
          transition(data, &data->heros, BAS);
          deplacer_entite(data, &data->heros, BAS);
          break;
          case SDLK_b:
          if(data->debug)
            data->vision++;
          break;
          case SDLK_n:
          if(data->vision > 1 && data-> debug)  
            data->vision--;
          break;
          case SDLK_v:
          if(data->debug)
            data->terminer = 1;
          break;
          default: break;
       }
    }
  }
}

void musiqueDebut(Donnee * data){
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
  {
    printf("%s", Mix_GetError());
  }
  data->musique = Mix_LoadMUS("./Son/Ugh.mp3");
  Mix_PlayMusic(data->musique, 0);
  SDL_Delay(6400);
}

void debut(Donnee* data){
  if(!data->debug){
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

void musiqueVictoire(Donnee* data){
  data->musique = Mix_LoadMUS("./Son/Victoire.mp3");
  Mix_PlayMusic(data->musique, 0);
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

void musiqueJeu(Donnee* data){
  data->musique = Mix_LoadMUS("./Son/Rock.mp3");
  Mix_PlayMusic(data->musique, -1);
}

void gagner(Donnee* data){
  if(data->tableau[data->heros.y][data->heros.x] == 5){
    data->terminer = 1;
  }
}

void libererMemoire(Donnee* data){
  Mix_FreeMusic(data->musique);
  SDL_FreeSurface(data->img_sol);
  SDL_FreeSurface(data->img_cercle);
  SDL_FreeSurface(data->img_mur);
  SDL_FreeSurface(data->img_heros);
  SDL_FreeSurface(data->img_gemme);
  SDL_FreeSurface(data->img_rectangle);
  SDL_FreeSurface(data->img_victoire);
}

int main(int argc, char *argv[]) {
  Donnee* data = malloc(sizeof *data);
  SDL_Init(SDL_INIT_VIDEO);
  if(argc > 1){
      if(!strcmp(argv[1], "-debug")){
        initialisation(data, 1);
      }
      else{
        initialisation(data, 0);
      }
  }
  else{
    initialisation(data, 0);
  }
  debut(data);
  musiqueJeu(data);
  while(data->terminer !=-1){
    if (data->terminer == 0){
      loop_level1(data);
      champsVision(data, 0, -1);
      gagner(data);
      SDL_UpdateWindowSurface(data->Fenetre);
    }
    else if(data->terminer == 1){
      victoire(data);
      data->terminer = -1;
    }
  }
  libererMemoire(data);
  SDL_DestroyWindow(data->Fenetre);
  SDL_Quit();
  return 0;
}