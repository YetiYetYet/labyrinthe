/* Le fichier header déclare au préalable pour tout les fichiers ou il est inclut, les variable
globales, les structures et les prototypes.
*/

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL_mixer.h> // Bibliotèque SDL qui gere les musiques de fond.
#include <SDL_image.h>

#define HAUTEUR 30 // gere le nombre d'élément sur la hauteurs.
#define LARGEUR 30 // gere le nombre d'élément sur la largeurs.
#define TAILLEELMT 20 // gere en la taille en pixel d'un élément.

// Structure qui gere le contenue du tableau. NENT correspond au nombre d'entité total.
enum { SOL, MUR, DEPART, GEMME, NENT};

// Les absices x y sont traiter par le haut a gauche. x étant la largeur et y la hauteur. 
typedef struct {
  int x; // x correspond à la position dans la largeur.
  int y; // y correspond à la hauteur.
} Entite;

// Structure qui gere les directions, NDIR correspond au nombre de direction total.
enum { HAUT, BAS, DROITE, GAUCHE, NDIR };

// Structure qui gere les points haut, bas, droite, gauche avec le tableau coor.
typedef struct {
  int x;
  int y;
} Point;
extern Point coor[NDIR];

// Structure qui stock et permet d'initialiser qu'une seule fois les données.
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

// Declaration des prototypes.
SDL_Surface* chargerImg(const char* fileName);
void ajouter_gemmes(Donnee* data, int nb);
void cercle(Donnee* data);
void champsVision(Donnee* data, int detail, int direction);
void initialisation(Donnee* data, int debug);
int prochaine_pos(Donnee* data, int x, int y);
void deplacer_entite(Donnee* data, Entite* e, int dir);
void placerLabyrinthe(Donnee * data);
void tableau(Donnee* data);
void transition(Donnee* data,Entite* e,int dir);
void boucleNiveau(Donnee* data);
void musiqueDebut(Donnee * data);
void debut(Donnee* data);
void musiqueVictoire(Donnee* data);
void victoire(Donnee* data);
void musiqueJeu(Donnee* data);
void gagner(Donnee* data);
void libererMemoire(Donnee* data);
int main(int argc, char *argv[]);
void initialiseLab();
