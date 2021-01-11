#include "ebentoak.h"
#include "imagen.h"


POSIZIOA saguPos;
SDL_Event event;
POSIZIOA saguarenPosizioa() { return saguPos;}
HITBOX hitbox;//

int ebentuaJasoGertatuBada(void){
	int ret = 0;
	if( SDL_PollEvent( &event ) )
	{
		/* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
		switch( event.type )
		{
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
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
					switch ( event.button.button ){
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
					saguPos.y =event.motion.y;
					ret = SAGU_MUGIMENDUA;
					break;
			default:
				break;
		}
	}
	return ret;
}
void KolisioakKonprobatu(void* pixels, int pitch, Uint8 bpp)
{
	JOKALARIA sprite;

	sprite.id_2d = spriteKargatu(".\\img\\PersonajeChicoVF .bmp");

	int PertzonaiaEzkerMuga = sprite.id_2d.x + 46;
	int PertzonaiaEskuinMuga = sprite.id_2d.x + 82;
	int PertzonaiaYGoikoa = sprite.id_2d.y;
	int PertzonaiaYBekoa = sprite.id_2d.y + 59;
	int YBekoa = sprite.id_2d.y + 52;
	


	//////////////////////////////tetectar el color//////////////////////////////
	hitbox.goikoa = getpixel(pixels, pitch, bpp, pertsonaia.DestSprite.x + 66, pertsonaia.DestSprite.y + 0);		//Burua
	//Ezkerreko aldea
	hitbox.ezker.goikoa = getpixel(pixels, pitch, bpp, pertsonaia.DestSprite.x + 46, pertsonaia.DestSprite.y + 11);

	hitbox.ezker.erdikoa = getpixel(pixels, pitch, bpp, pertsonaia.DestSprite.x + 46, pertsonaia.DestSprite.y + 32);
	hitbox.ezker.behekoa = getpixel(pixels, pitch, bpp, pertsonaia.DestSprite.x + 46, pertsonaia.DestSprite.y + 52);
	//Eskuineko aldea
	hitbox.eskuin.goikoa = getpixel(pixels, pitch, bpp, pertsonaia.DestSprite.x + 82, pertsonaia.DestSprite.y + 11);
	hitbox.eskuin.erdikoa = getpixel(pixels, pitch, bpp, pertsonaia.DestSprite.x + 82, pertsonaia.DestSprite.y + 32);
	hitbox.eskuin.behekoa = getpixel(pixels, pitch, bpp, pertsonaia.DestSprite.x + 82, pertsonaia.DestSprite.y + 52);
	//Behekoa
	hitbox.behekoa.ezker = getpixel(pixels, pitch, bpp, pertsonaia.DestSprite.x + 54, pertsonaia.DestSprite.y + 59);
	hitbox.behekoa.eskuin = getpixel(pixels, pitch, bpp, pertsonaia.DestSprite.x + 75, pertsonaia.DestSprite.y + 59);
	if (hitbox.behekoa.eskuin == BELTZA || hitbox.behekoa.ezker == BELTZA || hitbox.eskuin.behekoa == BELTZA || hitbox.ezker.behekoa == BELTZA)
	{
		
	}
}
