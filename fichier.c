#include "fichier.h"




int controle_de_saisi(){
 char c;
 int n;
     printf("DONNER LE NOMBRE DE CARRE ");
    do{

        scanf("%c",&c);
        fflush(stdin);
        if(isdigit(c)){
                        n=atoi(&c);
                        if(n>9) {printf("VEUILLEZ SAISIR UN NOMBRE DE DISK INFERIEUR A 7 :");
                                 c='a';
                                 }
                        }
        else        {
                         printf("VEUILLEZ SAISIR UN CHIFFRE SVP ");
                    }
    }while(!isdigit(c));

return n;
}








SDL_Window * creation_fenetre(char * nom_fenetre,int taille,int hauteur){
SDL_Window* w;
w=SDL_CreateWindow(nom_fenetre,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,taille,hauteur,SDL_WINDOW_SHOWN);
return w;

  }








  SDL_Renderer * remplissage_fenetre(SDL_Window * fenetre){
            SDL_Renderer * r;
            r=SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED);
            SDL_RenderPresent(r);
            return r;
                                                           }









   void un_rectangle(SDL_Renderer *r ,int pos_x,int pos_y){
                    SDL_Rect un_rect={pos_x,pos_y,3,3};
                    SDL_SetRenderDrawColor( r, 250, 150, 50, 0 );
                    SDL_RenderFillRect(r,&un_rect);
                    SDL_RenderPresent(r);
                                                          }







void   tracer(SDL_Renderer * r,int * tab,int x,int y){
float d_x,d_y, a,b;
     d_x=tab[0];
     d_y=tab[1];
     if(d_x!=x){ a=(y-d_y)/(x-d_x);
                 b=d_y-a*d_x;
                 do{
                 SDL_Delay(3);
                un_rectangle(r,d_x,d_y);
                if(d_x<x) d_x++;
                else  d_x--;
                d_y=a*d_x+b;
              }
        while(d_x!=x);
             }
    else{
            do{
                SDL_Delay(3);
                if(d_y<y) d_y++;
                else if(d_y>y) d_y--;
                un_rectangle(r,d_x,d_y);
                }
         while(d_y!=y);
        }
tab[0]=x;
tab[1]=y;
 }







 void dessin_abyme(SDL_Renderer*r,int *tab,int x,int y,int t,int n){
 if(n>0){
      tracer(r,tab,x+t/2,y);
      tracer(r,tab,x+t/4, y-t/4);
      dessin_abyme(r,tab,x+t/4, y-t/4, t/2, n-1) ;
      tracer(r,tab,x,y-t/2) ;
      tracer(r,tab,x+t/2, y-t) ;
      tracer(r,tab,x+t, y-t/2) ;
      tracer(r,tab,x+t/2, y) ;
      tracer(r,tab,x+t,y) ;
      tracer(r,tab,x+t, y-t) ;
      tracer(r,tab,x, y-t) ;
      tracer(r,tab,x,y);

       }

 }
