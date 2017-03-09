#include "header.h"

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
