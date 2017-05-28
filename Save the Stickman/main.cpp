//The headers files
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "SDL/SDL_ttf.h"
#include<iostream>
using namespace std;

//Screen attributes
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 700;
const int SCREEN_BPP = 32;

//The surfaces for the images
SDL_Surface *background = NULL;
SDL_Surface *stkman = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *score= NULL;
SDL_Surface *wrong_1=NULL;
SDL_Surface *wrong_2=NULL;
SDL_Surface *wrong_3=NULL;
SDL_Surface *wrong_4=NULL;
SDL_Surface *wrong_5=NULL;
SDL_Surface *wrong_6=NULL;
SDL_Surface *splashscreen=NULL;

// declaration for TTF types
TTF_Font *font=NULL;
TTF_Font *ansque=NULL;
TTF_Font *mistakes=NULL;
TTF_Font *answer=NULL;
TTF_Font *ans_ka=NULL;

//message
SDL_Surface *message=NULL;
SDL_Surface *nooqa=NULL;
SDL_Surface *text_mistakes=NULL;
SDL_Surface *text_answer=NULL;
SDL_Surface *text_ans_ka=NULL;

// The surface for he keyboard

// pointers for normal letters
SDL_Surface *key_ka = NULL;
SDL_Surface *key_kha=NULL;
SDL_Surface *key_ga=NULL;
SDL_Surface *key_gha=NULL;
SDL_Surface *key_nha=NULL;
SDL_Surface *key_cha=NULL;
SDL_Surface *key_chha=NULL;
SDL_Surface *key_ja=NULL;
SDL_Surface *key_jha=NULL;
SDL_Surface *key_yea=NULL;
SDL_Surface *key_ta=NULL;
SDL_Surface *key_tha=NULL;
SDL_Surface *key_da=NULL;
SDL_Surface *key_dha=NULL;
SDL_Surface *key_na=NULL;
SDL_Surface *key_taa=NULL;
SDL_Surface *key_thaa=NULL;
SDL_Surface *key_daa=NULL;
SDL_Surface *key_dhaa=NULL;
SDL_Surface *key_anaa=NULL;
SDL_Surface *key_pa=NULL;
SDL_Surface *key_fa=NULL;
SDL_Surface *key_ba=NULL;
SDL_Surface *key_va=NULL;
SDL_Surface *key_ma=NULL;
SDL_Surface *key_ya=NULL;
SDL_Surface *key_ra=NULL;
SDL_Surface *key_la=NULL;
SDL_Surface *key_wo=NULL;
SDL_Surface *key_sha_moto=NULL;
SDL_Surface *key_sha_kha=NULL;
SDL_Surface *key_sha_patulo=NULL;
SDL_Surface *key_ha=NULL;
SDL_Surface *key_chya=NULL;
SDL_Surface *key_tra=NULL;
SDL_Surface *key_zya=NULL;

//pointers for Nepali vowel letters
SDL_Surface *key_a=NULL;
SDL_Surface *key_aa=NULL;
SDL_Surface *key_e=NULL;
SDL_Surface *key_ee=NULL;
SDL_Surface *key_u=NULL;
SDL_Surface *key_uu=NULL;
SDL_Surface *key_ae=NULL;
SDL_Surface *key_ai=NULL;
SDL_Surface *key_o=NULL;
SDL_Surface *key_au=NULL;
SDL_Surface *key_am=NULL;
SDL_Surface *key_aaa=NULL;
SDL_Surface *key_re=NULL;

//pointers for the signs
SDL_Surface *key_akar=NULL;
SDL_Surface *key_hraswa_ekar=NULL;
SDL_Surface *key_dirga_ekar=NULL;
SDL_Surface *key_hraswa_ukar=NULL;
SDL_Surface *key_dirga_ukar=NULL;
SDL_Surface *key_rekar=NULL;
SDL_Surface *key_aekar=NULL;
SDL_Surface *key_aaikar=NULL;
SDL_Surface *key_wokar=NULL;
SDL_Surface *key_aukar=NULL;
SDL_Surface *key_anuswar=NULL;
SDL_Surface *key_bisarga=NULL;

//text pointers declaration

//text color
SDL_Color textColor = { 255, 255, 255 };

//The event structure
SDL_Event event;

//enable unicod््SDL_EnableUNICODE(1);


SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );

        //If the image was optimized just fine
        if( optimizedImage != NULL )
        {
            //Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF );

            //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
    }

    //Return the optimized image
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return 1;
    }

    if(TTF_Init()==-1)
    {
        return false;
    }

    SDL_WM_SetCaption( "Save the \xE0 \xA4 1.0", NULL );

    //If everything initialized fine
    return true;
}

bool splash()
{
    //Load splash screen
    splashscreen=load_image("splash.png");
    if(splashscreen==NULL)
    {
        return false;
    }
}

bool load_files()
{
    //Load the background image
    background = load_image( "background.png" );

    //If the background didnt load
    if( background == NULL )
    {
        return false;
    }

    //Load the stick figure
    stkman = load_image( "1.png" );
    if( stkman == NULL )
    {
        return false;
    }

    score= load_image("score.png");

    if( score== NULL)
    {
        return false;
    }

    //For the keyboard

    key_ka=load_image("ka.jpg");
    if(key_ka==NULL)
    {
        return false;
    }

    key_kha=load_image("kha.jpg");
    if(key_kha==NULL)
    {
        return false;
    }

    key_ga=load_image("ga.jpg");
    if(key_ga==NULL)
    {
         return false;
    }

    key_gha=load_image("gha.jpg");
    if(key_gha==NULL)
    {

        return false;
    }

    key_nha=load_image("nha.jpg");
    if(key_nha==NULL)
    {
        return false;
    }

    key_cha=load_image("cha.jpg");
    if(key_cha==NULL)
    {
        return false;
    }

    key_chha=load_image("chha.jpg");
    if(key_chha==NULL)
    {
        return false;
    }

    key_ja=load_image("ja.jpg");
    if(key_ja==NULL)
    {
        return false;
    }

    key_jha=load_image("jha.jpg");
    if(key_jha==NULL)
    {
        return false;
    }

    key_yea=load_image("yea.jpg");
    if(key_yea==NULL)
    {
        return false;
    }

    key_ta=load_image("ta.jpg");
    if(key_ta==NULL)
    {
        return false;
    }

    key_tha=load_image("tha.jpg");
    if(key_tha==NULL)
    {
        return false;
    }

    key_da=load_image("da.jpg");
    if(key_da==NULL)
    {
        return false;
    }

    key_dha=load_image("dha.jpg");
    if(key_dha==NULL)
    {
        return false;
    }

    key_na=load_image("na.jpg");
    if(key_na==NULL)
    {
        return false;
    }

    key_taa=load_image("taa.jpg");
    if(key_taa==NULL)
    {
        return false;
    }

    key_thaa=load_image("thaa.jpg");
    if(key_thaa==NULL)
    {
        return false;
    }

    key_daa=load_image("daa.jpg");
    if(key_daa==NULL)
    {

        return false;
    }

    key_dhaa=load_image("dhaa.jpg");
    if(key_dhaa==NULL)
    {
        return false;
    }

    key_anaa=load_image("anaa.jpg");
    if(key_anaa==NULL)
    {
        return false;
    }

    key_pa=load_image("pa.jpg");
    if(key_pa==NULL)
    {
        return false;
    }

    key_fa=load_image("fa.jpg");
    if(key_fa==NULL)
    {
        return false;
    }

    key_ba=load_image("ba.jpg");
    if(key_ba==NULL)
    {
        return false;
    }

    key_va=load_image("va.jpg");
    if(key_va==NULL)
    {
        return false;
    }

    key_ma=load_image("ma.jpg");
    if(key_ma==NULL)
    {
        return false;
    }

    key_ya=load_image("ya.jpg");
    if(key_ya==NULL)
    {
        return false;
    }

    key_ra=load_image("ra.jpg");
    if(key_ra==NULL)
    {
        return false;
    }

    key_la=load_image("la.jpg");
    if(key_la==NULL)
    {
        return false;
    }

    key_wo=load_image("wo.jpg");
    if(key_wo==NULL)
    {
        return false;
    }

    key_sha_moto=load_image("sha_moto.jpg");
    if(key_sha_moto==NULL)
    {
        return false;
    }

    key_sha_kha=load_image("sha_kha.jpg");
    if(key_sha_kha==NULL)
    {
        return false;
    }

    key_sha_patulo=load_image("sha_patulo.jpg");
    if(key_sha_patulo==NULL)
    {
        return false;
    }

    key_ha=load_image("ha.jpg");
    if(key_ha==NULL)
    {
        return false;
    }

    key_chya=load_image("chya.jpg");
    if(key_chya==NULL)
    {
        return false;
    }

    key_tra=load_image("tra.jpg");
    if(key_ta==NULL)
    {
        return false;
    }

    key_zya=load_image("zya.jpg");
    if(key_zya==NULL)
    {
        return false;
    }


// image importing for the respective pointers
    key_a=load_image("a.jpg");
    if(key_a==NULL)
    {
        return false;
    }

    key_aa=load_image("aa.jpg");
    if(key_aa==NULL)
    {
        return false;
    }

    key_e=load_image("e.jpg");
    if(key_e==NULL)
    {
        return false;
    }

    key_ee=load_image("ee.jpg");
    if(key_ee==NULL)
    {
        return false;
    }

    key_u=load_image("u.jpg");
    if(key_u==NULL)
    {
        return false;
    }

    key_uu=load_image("uu.jpg");
    if(key_uu==NULL)
    {
        return false;
    }

    key_ae=load_image("ae.jpg");
    if(key_ae==NULL)
    {
        return false;
    }

    key_ai=load_image("ai.jpg");
    if(key_ai==NULL)
    {
        return false;
    }

    key_o=load_image("o.jpg");
    if(key_o==NULL)
    {
        return false;
    }

    key_au=load_image("au.jpg");
    if(key_au==NULL)
    {
        return false;
    }

    key_am=load_image("am.jpg");
    if(key_am==NULL)
    {
        return false;
    }

    key_aaa=load_image("aaa.jpg");
    if(key_aaa==NULL)
    {
        return false;
    }

    key_re=load_image("re.jpg");
    if(key_re==NULL)
    {
        return false;
    }

// Loading the signs(pointer assignment for image of signs)
    key_akar=load_image("akar.jpg");
    if(key_re==NULL)
    {
        return false;
    }

    key_hraswa_ekar=load_image("hraswa_ekar.jpg");
    if(key_hraswa_ekar==NULL)
    {
        return false;
    }

    key_dirga_ekar=load_image("dirga_ekar.jpg");
    if(key_dirga_ekar==NULL)
    {
        return false;
    }

    key_hraswa_ukar=load_image("hraswa_ukar.jpg");
    if(key_hraswa_ukar==NULL)
    {
        return false;
    }

    key_dirga_ukar=load_image("dirga_ukar.jpg");
    if(key_dirga_ukar==NULL)
    {
        return false;
    }

    key_rekar=load_image("rekar.jpg");
    if(key_rekar==NULL)
    {
        return false;
    }

    key_aekar=load_image("aekar.jpg");
    if(key_rekar==NULL)
    {
        return false;
    }

    key_aaikar=load_image("aaikar.jpg");
    if(key_aaikar==NULL)
    {
        return false;
    }

    key_wokar=load_image("wokar.jpg");
    if(key_wokar==NULL)
    {
        return false;
    }

    key_aukar=load_image("aukar.jpg");
    if(key_aukar==NULL)
    {
        return false;
    }

    key_anuswar=load_image("anuswar.jpg");
    if(key_anuswar==NULL)
    {
        return false;
    }

    key_bisarga=load_image("bisarga.jpg");
    if(key_bisarga==NULL)
    {
        return false;
    }


    // assigning images for the wrong input answers
    wrong_1=load_image("bg_wrong.png");
    if(wrong_1==NULL)
    {
        return false;
    }

    wrong_2=load_image("bg_wrong.png");
    if(wrong_2==NULL)
    {
        return false;
    }

    wrong_3=load_image("bg_wrong.png");
    if(wrong_3==NULL)
    {
        return false;
    }

    wrong_4=load_image("bg_wrong.png");
    if(wrong_4==NULL)
    {
        return false;
    }

    wrong_5=load_image("bg_wrong.png");
    if(wrong_5==NULL)
    {
        return false;
    }

    wrong_6=load_image("bg_wrong.png");
    if(wrong_6==NULL)
    {
        return false;
    }


// Loading ttf types
    font=TTF_OpenFont("ALGER.ttf",28);
    if(font==NULL)
    {
        return false;
    }

    mistakes=TTF_OpenFont("madan.ttf",28);
    if(mistakes==NULL)
    {
        return false;
    }

    ans_ka=TTF_OpenFont("ALGER.ttf",28);
    if(ans_ka==NULL)
    {
        return false;
    }



   /* answer=TTF_OpenFont("ALGER.ttf",28);
    if(answer==NULL)
    {
        return false;
    }
*/

    return true;
}



void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface(background );
    SDL_FreeSurface(stkman );
    SDL_FreeSurface(score);
    SDL_FreeSurface(splashscreen);

   //clean up for the keys(nepali charatcers)
    SDL_FreeSurface(key_ka);
    SDL_FreeSurface(key_kha);
    SDL_FreeSurface(key_ga);
    SDL_FreeSurface(key_gha);
    SDL_FreeSurface(key_nha);
    SDL_FreeSurface(key_cha);
    SDL_FreeSurface(key_chha);
    SDL_FreeSurface(key_ja);
    SDL_FreeSurface(key_jha);
    SDL_FreeSurface(key_yea);
    SDL_FreeSurface(key_ta);
    SDL_FreeSurface(key_tha);
    SDL_FreeSurface(key_da);
    SDL_FreeSurface(key_dha);
    SDL_FreeSurface(key_na);
    SDL_FreeSurface(key_taa);
    SDL_FreeSurface(key_thaa);
    SDL_FreeSurface(key_daa);
    SDL_FreeSurface(key_dhaa);
    SDL_FreeSurface(key_anaa);
    SDL_FreeSurface(key_pa);
    SDL_FreeSurface(key_fa);
    SDL_FreeSurface(key_ba);
    SDL_FreeSurface(key_va);
    SDL_FreeSurface(key_ma);
    SDL_FreeSurface(key_ya);
    SDL_FreeSurface(key_ra);
    SDL_FreeSurface(key_la);
    SDL_FreeSurface(key_wo);
    SDL_FreeSurface(key_sha_moto);
    SDL_FreeSurface(key_sha_kha);
    SDL_FreeSurface(key_sha_patulo);
    SDL_FreeSurface(key_ha);
    SDL_FreeSurface(key_chya);
    SDL_FreeSurface(key_tra);
    SDL_FreeSurface(key_zya);

    // cleaning surfaces for vowels Nepali letter

    SDL_FreeSurface(key_a);
    SDL_FreeSurface(key_aa);
    SDL_FreeSurface(key_e);
    SDL_FreeSurface(key_ee);
    SDL_FreeSurface(key_u);
    SDL_FreeSurface(key_uu);
    SDL_FreeSurface(key_ae);
    SDL_FreeSurface(key_ai);
    SDL_FreeSurface(key_o);
    SDL_FreeSurface(key_au);
    SDL_FreeSurface(key_am);
    SDL_FreeSurface(key_aaa);
    SDL_FreeSurface(key_re);

    //clear surfaces for the signs
    SDL_FreeSurface(key_akar);
    SDL_FreeSurface(key_hraswa_ekar);
    SDL_FreeSurface(key_dirga_ekar);
    SDL_FreeSurface(key_hraswa_ukar);
    SDL_FreeSurface(key_dirga_ukar);
    SDL_FreeSurface(key_rekar);
    SDL_FreeSurface(key_aekar);
    SDL_FreeSurface(key_aaikar);
    SDL_FreeSurface(key_wokar);
    SDL_FreeSurface(key_aukar);
    SDL_FreeSurface(key_anuswar);
    SDL_FreeSurface(key_bisarga);

    //surface cleanup for the wrong inputs
    SDL_FreeSurface(wrong_1);
    SDL_FreeSurface(wrong_2);
    SDL_FreeSurface(wrong_3);
    SDL_FreeSurface(wrong_4);
    SDL_FreeSurface(wrong_5);
    SDL_FreeSurface(wrong_6);

    //text cleanup
    TTF_CloseFont(font);
    TTF_CloseFont(ansque);
    TTF_CloseFont(mistakes);
    TTF_CloseFont(answer);
    TTF_CloseFont(ans_ka);
    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

  /*
    if(splash()==false)
    {
        return 1;
    }
    */

    /* if( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                case SDLK_a:

                    break;
                }
            }
        }
*/


   //Load the files
if( load_files() == false )
{
        return 1;
}





    //Apply the surfaces to the screen
    apply_surface(0,0,background,screen );
    apply_surface(750,70,stkman,screen );
    apply_surface(790,10,score,screen);
   // apply_surface(0,0,splashscreen,screen);

    //message rendering
    message = TTF_RenderText_Solid( font, "नेपाल को बस्", textColor );
    if(message==NULL)
    {
        return 1;
    }

    nooqa=TTF_RenderText_Solid(font,"No of questions answered", textColor);
    if(nooqa==NULL)
    {
        return 1;
    }

    text_mistakes=TTF_RenderText_Solid(font,"मगगगउयउय",textColor);
    if(text_mistakes==NULL)
    {
        return 1;
    }

    text_ans_ka=TTF_RenderText_Solid(font,"ABC",textColor);
            if(text_ans_ka==NULL)
            {
                return 1;
            }
/*
    char ans[100]="kathmandu university";
    int x;
    int i=0;
    x=strlen(ans);

    text_answer=TTF_RenderText_Solid(font,,textColor);
    if(text_answer==NULL)
    {
        return 1;
    }
    */

    // Section for the keys( Nepali keyboard)
    apply_surface(10,450,key_ka,screen);
    apply_surface(70,450,key_kha,screen);
    apply_surface(130,450,key_ga,screen);
    apply_surface(190,450,key_gha,screen);
    apply_surface(250,450,key_nha,screen);
    apply_surface(310,450,key_cha,screen);
    apply_surface(370,450,key_chha,screen);
    apply_surface(430,450,key_ja,screen);
    apply_surface(490,450,key_jha,screen);
    apply_surface(550,450,key_yea,screen);
    apply_surface(610,450,key_ta,screen);
    apply_surface(670,450,key_tha,screen);
    apply_surface(10,515,key_da,screen);
    apply_surface(70,515,key_dha,screen);
    apply_surface(130,515,key_na,screen);
    apply_surface(190,515,key_taa,screen);
    apply_surface(250,515,key_thaa,screen);
    apply_surface(310,515,key_dhaa,screen);
    apply_surface(370,515,key_anaa,screen);
    apply_surface(430,515,key_pa,screen);
    apply_surface(490,515,key_fa,screen);
    apply_surface(550,515,key_ba,screen);
    apply_surface(610,515,key_va,screen);
    apply_surface(670,515,key_ma,screen);
    apply_surface(10,580,key_ya,screen);
    apply_surface(70,580,key_ra,screen);
    apply_surface(130,580,key_wo,screen);
    apply_surface(190,580,key_sha_moto,screen);
    apply_surface(250,580,key_sha_kha,screen);
    apply_surface(310,580,key_sha_patulo,screen);
    apply_surface(370,580,key_ha,screen);
    apply_surface(430,580,key_chya,screen);
    apply_surface(490,580,key_tra,screen);
    apply_surface(550,580,key_zya,screen);

//surface memory allocation for the Nepali vowel letters
    apply_surface(10,645,key_a,screen);
    apply_surface(80,645,key_aa,screen);
    apply_surface(150,645,key_e,screen);
    apply_surface(220,645,key_ee,screen);
    apply_surface(290,645,key_u,screen);
    apply_surface(360,645,key_uu,screen);
    apply_surface(430,645,key_ae,screen);


    apply_surface(500,645,key_ai,screen);
    apply_surface(570,645,key_o,screen);
    apply_surface(640,645,key_au,screen);
    apply_surface(710,645,key_am,screen);
    apply_surface(780,645,key_aaa,screen);
    apply_surface(850,645,key_re,screen);

    //applying surface fr the Nepali signs
    apply_surface(730,515,key_akar,screen);
    apply_surface(800,515,key_hraswa_ekar,screen);
    apply_surface(870,515,key_dirga_ekar,screen);
    apply_surface(940,515,key_hraswa_ukar,screen);
    apply_surface(610,580,key_rekar,screen);
    apply_surface(680,580,key_aekar,screen);
    apply_surface(750,580,key_aaikar,screen);
    apply_surface(820,580,key_wokar,screen);
    apply_surface(890,580,key_aukar,screen);
    apply_surface(960,580,key_anuswar,screen);
    apply_surface(920,645,key_bisarga,screen);

    //applying surface for the wrong answers boxes
    apply_surface(430,50,wrong_1,screen);
    apply_surface(480,50,wrong_2,screen);
    apply_surface(530,50,wrong_2,screen);
    apply_surface(580,50,wrong_2,screen);
    apply_surface(630,50,wrong_2,screen);
    apply_surface(680,50,wrong_2,screen);

    //applying surface for the message
    apply_surface(230,170,message,screen);
    apply_surface(0,20,nooqa,screen);
    apply_surface(500,5,text_mistakes,screen);
    apply_surface(230,250,text_answer,screen);
    //apply_surface(500,200,text_ans_ka,screen);


    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }

    //While the user hasn't quit
    while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
    }

    int x=0,y=0;

    if( event.type == SDL_MOUSEBUTTONDOWN )
    {
        //If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            x = event.button.x;
            y = event.button.y;

            //If the mouse is over the button
            if( ( x >0 ) && ( x < 1024) && ( y > 0) && ( y < 700) )
            {
            //Set the button sprite
            apply_surface(500,200,text_ans_ka,screen);
            }
        }
    }


SDL_EnableUNICODE(0);

    //Free the surfaces and quit SDL
    clean_up();

    return 0;
}
