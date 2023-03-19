#include <string>
#include <iostream>
#include <vector>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#else
#include <SDL.h>
//#include <SDL_image.h>
#endif

#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* surface;

SDL_Texture* mailboxTex = nullptr;

float drawX = 0.f;
float drawY = 0.f;

SDL_Texture* loadTexture(const std::string& file, SDL_Renderer* ren) {

	int width, height, colorComponents;
	const unsigned char* textureData = stbi_load(file.c_str(), &width, &height, &colorComponents, 4);

	if (textureData == nullptr) {
		return nullptr;
	}

	SDL_Texture* texture = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	unsigned char* bytes = nullptr;
	int pitch = 0;
	SDL_LockTexture(texture, nullptr, reinterpret_cast<void**>(&bytes), &pitch);
	memcpy(bytes, textureData, width * height * sizeof(Uint32));	
	SDL_UnlockTexture(texture);

	return texture;
}

void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y) {
	SDL_Rect destination;
	destination.x = x;
	destination.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &destination.w, &destination.h);
	SDL_BlendFactor(SDL_BLENDFACTOR_DSD_ALPHA);
	SDL_RenderCopy(ren, tex, NULL, &destination);
}



void drawRandomPixels() {
	SDL_SetRenderDrawColor(renderer, 64, 64, 64, 255);
	SDL_RenderClear(renderer);
	renderTexture(mailboxTex, renderer, int(drawX), int(drawY));
	SDL_RenderPresent(renderer);
}

void mainLoop()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if(e.type == SDL_KEYDOWN) {
			if(e.key.keysym.sym == SDLK_LEFT) {
				drawX -= 5.f;
			}
			if(e.key.keysym.sym == SDLK_RIGHT) {
				drawX += 5.f;
			}
		}
	}
	drawRandomPixels();
}

int main(int argc, char* argv[]) {
	printf("Hello World!");
#ifdef __EMSCRIPTEN__
	//SDL_SetHint(SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT, "#canvas");
#endif
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(512, 512, 0, &window, &renderer);


	mailboxTex = loadTexture("assets/letterBox.png", renderer);

#ifdef __EMSCRIPTEN__
	emscripten_set_main_loop(mainLoop, 0, 1);
#else
	while (1) {
		mainLoop();
		//SDL_Delay(16);
	}
#endif 
	}