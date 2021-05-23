#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int controle_de_saisi();
SDL_Window * creation_fenetre( char* ,int,int);
void un_rectangle(SDL_Renderer *,int,int);
void tracer(SDL_Renderer *,int *,int,int);
void dessin_abyme(SDL_Renderer *,int*,int,int,int,int);


#endif // FICHIER_H_INCLUDED
