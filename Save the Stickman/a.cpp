#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <vector>
int main (int argc, char* argv[])
{
// Declaration
SDL_Surface* theScreen = NULL;
SDL_Surface* theText = NULL;
bool quit = false;
bool begin = false; // Begin input?
TTF_Font *font = NULL;
std::vector<Uint16> theString;
SDL_Event theEvent;
// Inits
// WARNING : No checks have been done.
SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();
font = TTF_OpenFont("madan.ttf", 24); // Make sure this is in the directory
theString.resize(0);
SDL_EnableUNICODE(1); // Unicode is off by default

// Window Creation
theScreen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);
SDL_WM_SetCaption("Click to Begin", NULL);

while (!quit)
{
while (SDL_PollEvent(&theEvent))
{
// Window has exited
if (theEvent.type == SDL_QUIT)
{
quit = true;
}

// Begin rendering // Give time to alt shift
if (theEvent.type == SDL_MOUSEBUTTONDOWN)
{
begin = true;
SDL_WM_SetCaption("अख।झझणझ", NULL);
}

if (begin)
{
// Push back to the vector and render
if (theEvent.type == SDL_KEYDOWN)
{
theString.push_back(theEvent.key.keysym.unicode);
if (theText != NULL)
{
SDL_FreeSurface(theText); // Memory leak sucks
}
Uint16* arr = new Uint16[theString.size() + 1];
arr[theString.size()] = '\0'; // Terminate the string
std::copy(theString.begin(), theString.end(), arr);
SDL_Color black = {0,0,0};
theText = TTF_RenderUNICODE_Blended(font,arr, black);
delete[] arr; // Was useless anyway
}
}
}
// Clear, Render and Flip
SDL_FillRect(theScreen, &theScreen->clip_rect,SDL_MapRGB(theScreen->format, 0xff,0xff,0xff));
SDL_BlitSurface(theText, NULL, theScreen,NULL);
SDL_Flip(theScreen);
}
// Shut down the unicode (Just in case)
SDL_EnableUNICODE(0);
// Close, clear and quit everything
TTF_CloseFont(font);
SDL_FreeSurface(theText);
TTF_Quit();
SDL_Quit();
return 0;
}
