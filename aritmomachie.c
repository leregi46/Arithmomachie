/*
    Author Reginald Victor on April 2017
    Thanks to Chamane for contributions and advisory
*/
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#define LONGUEUR_ECHIQUIER_X 327.5
#define LONGUEUR_ECHIQUIER_Y 635

int init_bibliotheque(void){
  if(!al_init())
  {
      al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);
      return 0;
  }

  else
  {
    printf("INITIALISATION ALLEGRO: REUSSITE\n");
    return 1;
  }
}
void dessiner_fenetre(const char *titre, int largeur, int hauteur)
{

  ALLEGRO_DISPLAY*ecran;
  ecran = al_create_display(largeur,hauteur);
  al_set_window_title(ecran, *titre);
  al_clear_to_color(al_map_rgb(85,85,85));
  al_init_primitives_addon();
  dessiner_echiquier();
  generer_fenetre_case();
  al_flip_display();
  al_rest(6000);
  al_destroy_display(ecran);
}

void dessiner_echiquier(){
	float largeur = 1240;
    float hauteur = 750;
    float x1 = (largeur - LONGUEUR_ECHIQUIER_X)/2;
    float y1 = (hauteur-LONGUEUR_ECHIQUIER_Y)/2;
    float x2 = x1 + LONGUEUR_ECHIQUIER_X;
    float y2 = y1 + LONGUEUR_ECHIQUIER_Y;
    float epp = 5;

    ALLEGRO_COLOR couleur = al_map_rgba(12,45,69,241);
    al_draw_rectangle(x1,y1,x2,y2,couleur,epp);
}

void generer_fenetre_case(){
	
   float largeur_prim = 307.5;
   float hauteur_prim = 615;
   float largeur1 = 1240;
   float hauteur1 = 750;
   float LONG_CASE = 38.4375;
   float x1 = (largeur1-largeur_prim)/2;
   float y1 = (hauteur1-hauteur_prim)/2;
   float x2 = x1 + LONG_CASE ;
   float y2 = y1 + LONG_CASE;
   int ligne, colonne;
   float epp = 1.5;
   ALLEGRO_COLOR couleur = al_map_rgba(12,45,69,241);

  float x_a=x1, y_a=y1, x_b=x2, y_b=y2;
  float first_x_a=x_a, first_x_b=x_b;
  for(ligne=0;ligne<16;ligne++)
  {
  	if(ligne!=0){
  		x_a=first_x_a;
  		y_a=y_a+LONG_CASE;
  		x_b=first_x_b;
  		y_b=y_b+LONG_CASE;
  	}
  	for(colonne=0;colonne<8;colonne++){
  		if(colonne!=0){
  			x_a=x_b;
  			y_a=y_a;
  			x_b=x_b+LONG_CASE;
  			y_b=y_b;

  		}
	
	if((colonne%2==0)&&!(ligne%2==0))
    		al_draw_filled_rectangle(x_a,y_a,x_b,y_b,couleur);
    	else if(!(colonne%2==0)&&(ligne%2==0))
    		al_draw_filled_rectangle(x_a,y_a,x_b,y_b,couleur);
    	else
        	al_draw_rectangle(x_a,y_a,x_b,y_b,couleur,epp);
  	}
  }
}

int main(int argc, char const *argv[])
{


    if (!init_bibliotheque()) // nap start tout sann bezwen
        return 7;
	dessiner_fenetre("ARITHMOMACHIE",1240,750);
	return 0;
}
