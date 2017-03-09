/* Ce fichier inclut les fonctions en quelque sorte inclassable mais qui n'en reste pas
moins importante.
*/
#include "header.h"

// La fonction pour charger une images et gerer les erreurs et les exeptions.
SDL_Surface* chargerImg(const char* fileName) {
  SDL_Surface *image = IMG_Load(fileName);
  if (!image)
  {
     printf("Charger_Image: %s\n", IMG_GetError());
     return 0;
  }
  return image;
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