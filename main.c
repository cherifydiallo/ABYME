#include "fichier.h"

int main(int argc,char * argv[]){

SDL_Renderer * remplir;
SDL_Window* window = NULL;
int nbre;
int t[2];
t[0]=100;
t[1]=650;
nbre=controle_de_saisi();
SDL_Init(SDL_INIT_VIDEO);
window=creation_fenetre("DESSIN EN ABYME",850,670);
remplir=remplissage_fenetre(window);


dessin_abyme(remplir,t,t[0],t[1],630,nbre);

SDL_Delay(5000);
SDL_DestroyWindow(window);
SDL_DestroyRenderer(remplir);
SDL_Quit();

}
