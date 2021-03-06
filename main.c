#include "import.h"
#include "map.c"
#include "events.c"
#include "perso.c"

int main(int argc,char** argv){
	Map* carte;
// 	Mix_Music* musique;
	Input in;
	gameover = jump = left = right = move = fly = 0;	step = 1;	vie = 3;	score = 00000;
	LARGEUR_TILE = 24;
	HAUTEUR_TILE = 16;
	memset(&in,0,sizeof(in));
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); // preapare SDL video ET audio
	TTF_Init(); //prepare SDL fonts 
	screen = SDL_SetVideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	carte = ChargerMap("level1.txt",LARGEUR_FENETRE,HAUTEUR_FENETRE);
	mario = IMG_Load("./img/mario-3.png");
// 	musique = Mix_LoadMUS("./sons/mario-bros-song.mp3");
	perso.x = respawnX = 30;
	perso.y = saveY = respawnY = 535;
	perso.w = 24;
	perso.h = 32;
	posblit.x = MARIO_WALK_R_X;
	posblit.y = MARIO_WALK_Y;
	posblit.w = MARIO_WIDTH;
	posblit.h = MARIO_HEIGHT;
	
// 	Mix_PlayMusic(musique, -1);
	while(!gameover)
	{
		UpdateEvents(&in);
		Evolue(&in,carte,&perso);
		FocusScrollCenter(carte,&perso);
		AfficherMap(carte,screen);
		AfficherPerso(&perso,screen,mario,carte->xscroll,carte->yscroll);
		TableauDeBord(screen);
		SDL_Flip(screen);
		SDL_Delay(8);
	}
// 	Mix_FreeMusic(musique); 
	LibererMap(carte);
	TTF_Quit();
	SDL_Quit();
	return 0;
}
