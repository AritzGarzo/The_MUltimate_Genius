#include "SDL_TTF.h"
#include "SDL.h"

#include "text.h"
#include "graphics.h"
#include "imagen.h"
#include <stdio.h>

TTF_Font* font = 0;



void textuaGaitu_galderak(void)
{
	font = TTF_OpenFontIndex("C:\\WINDOWS\\Fonts\\ARIAL.TTF", 32, 0); // 32 tamaina
	if (!font)
	{
		printf("TTF_OpenFontIndex: %s\n", TTF_GetError());
		// handle error
	}
}

//profila
void textuaGaitu_profila(void)
{
	font = TTF_OpenFontIndex("C:\\WINDOWS\\Fonts\\BRLNSR.TTF", 64, 0);
	if (!font)
	{
		printf("TTF_OpenFontIndex: %s\n", TTF_GetError());
		// handle error
	}
}

//pantaila beltza
void textuaGaitu_beltza(void)
{
	font = TTF_OpenFontIndex("C:\\WINDOWS\\Fonts\\BRLNSR.TTF", 16, 0);
	if (!font)
	{
		printf("TTF_OpenFontIndex: %s\n", TTF_GetError());
		// handle error
	}
}

void textuaIdatzi(int x, int y, char* str)
{
	SDL_Surface* textSurface;
	SDL_Texture* mTexture;
	SDL_Color textColor = { 0X00, 0X00, 0X00 };
	SDL_Rect src, dst;
	SDL_Renderer* gRenderer;

	if (font == 0) return;
	gRenderer = getRenderer();
	textSurface = TTF_RenderText_Solid(font, str, textColor);
	mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
	src.x = 0; dst.x = x;
	src.y = 0; dst.y = y;
	src.w = dst.w = textSurface->w;
	src.h = dst.h = textSurface->h;
	SDL_RenderCopy(gRenderer, mTexture, &src, &dst);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(mTexture);
}

void textuaIdatzi_beltza(int x, int y, char* str)
{
	SDL_Surface* textSurface;
	SDL_Texture* mTexture;
	SDL_Color textColor = { 0XFF, 0XFF, 0XFF };
	SDL_Rect src, dst;
	SDL_Renderer* gRenderer;

	if (font == 0) return;
	gRenderer = getRenderer();
	textSurface = TTF_RenderText_Solid(font, str, textColor);
	mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
	src.x = 0; dst.x = x;
	src.y = 0; dst.y = y;
	src.w = dst.w = textSurface->w;
	src.h = dst.h = textSurface->h;
	SDL_RenderCopy(gRenderer, mTexture, &src, &dst);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(mTexture);
}

void textuaDesgaitu(void)
{
	if (font != 0) TTF_CloseFont(font);
	font = 0;
}

