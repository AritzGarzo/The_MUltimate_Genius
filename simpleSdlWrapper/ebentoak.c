#include "ebentoak.h"
#include "imagen.h"





HITBOX hitbox;
POSIZIOA saguPos;
SDL_Event event;

POSIZIOA saguarenPosizioa() { return saguPos; }

int ebentuaJasoGertatuBada(void) {
	int ret = 0;
	if (SDL_PollEvent(&event))
	{
		/* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				ret = TECLA_LEFT;
				//actualizaPlayer(-15);
				break;
			case SDLK_RIGHT:
				ret = TECLA_RIGHT;
				//actualizaPlayer(15);
				break;
			case SDLK_DOWN:
				ret = TECLA_DOWN;
				break;
			default:
				ret = event.key.keysym.sym;
				break;
			}
			break;
		case SDL_QUIT:
			ret = GERTAERA_IRTEN;
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				ret = SAGU_BOTOIA_EZKERRA;
				break;
			case SDL_BUTTON_RIGHT:
				ret = SAGU_BOTOIA_ESKUMA;
				break;
			default:
				ret = event.button.button;
				break;
			}
			break;
		case SDL_MOUSEMOTION:
			//ALDAGIA OROKOR BATEN EZARRIK ODUGU X ETA Y GERO FUNZTIO BATEKIN IRAKURTZEKO AZKEN EBENTUAREN POSIZIOA
			saguPos.x = event.motion.x;
			saguPos.y = event.motion.y;
			ret = SAGU_MUGIMENDUA;
			break;
		default:
			break;
		}
	}
	return ret;
}

void KolisioakKonprobatu(void* pixels, int pitch, Uint8 bpp, JOKALARIA sprite)
{

	//////////////////////////////detectar el color//////////////////////////////
	hitbox.goikoa = getpixel(pixels, pitch, bpp, sprite.pos.x + 9, sprite.pos.y);        //Burua
	//Ezkerreko aldea

	hitbox.ezker.erdikoa = getpixel(pixels, pitch, bpp, sprite.pos.x, sprite.pos.y + 14);

	//Eskuineko aldea

	hitbox.eskuin.erdikoa = getpixel(pixels, pitch, bpp, sprite.pos.x + 18, sprite.pos.y + 14);

	//Behekoa
	hitbox.behekoa.ezker = getpixel(pixels, pitch, bpp, sprite.pos.x + 9, sprite.pos.y + 28);


}