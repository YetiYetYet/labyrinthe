/* 
La fonction main dispose de deux mode d'exectution, Si il est lancé avec l'argument '-debug',
le programme se lancera en en mode devellopeur et n'auras pas l'introduction ni les musiques. 
De plus 3 touches seront debloquer : v pour forcer la victoire, b pour diminiuer le champ de
vision et n pour l'augmenter.
*/

#include "header.h"

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