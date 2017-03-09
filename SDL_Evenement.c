#include "header.h"

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
