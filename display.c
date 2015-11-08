#include <stdlib.h>
#include <SDL2/SDL.h>


struct display{
    int imagewidth,  imageheigth;
    SDL_Surface *surface;
    SDL_Window *window;
    SDL_Surface *image[128];
    SDL_Event *event;
};

typedef struct display display;
void drawEnity(display *d,int what,int x, int y);
void drawFrame(display *d);
static void SDL_Fail(char *s);
static void loadImage(display *d, int what, char *filename);


int main(void)
{
    
    
    display *d=malloc(sizeof(display));
    int w=d->imageheigth=20;
    int h=d->imagewidth=20;
    
    int result=SDL_Init(SDL_INIT_VIDEO);
    if (result<0) {
        SDL_Fail("Bad SDL");
    }
    d->window=SDL_CreateWindow("niconiconi", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 600, 400,SDL_WINDOW_SHOWN);
    if (d->window==NULL) {
        SDL_Fail("Could not create window");
    }
    d->surface=SDL_GetWindowSurface(d->window);
    if (d->surface==NULL) {
        SDL_Fail("Could not create surface");
    }
    loadImage(d,1,"img.bmp");
    SDL_Rect box_structure={100,100,20,20};
    SDL_Rect *box=&box_structure;
    
    drawEnity( d,2, 8, 9);
    drawFrame(d);
    
    return 0;
}

int r=SDL_BlitSurface(img,NULL,d->surface,box);
if (r<0) {
    SDL_Fail("Bad window");
}

static void loadImage(display *d, int what, char *filename){
    /* char path[100];*/
    /*  strcpy(filename);*/
    SDL_Surface *image=SDL_LoadBMP(filename);
    if (image==NULL) {
        SDL_Fail("Bad image file");
    }
}

void drawFrame(display *d){
    int r=SDL_UpdateWindowSurface(d->window);
    if (r<0) {
        SDL_Fail("Bad window repaint");
    }
    SDL_Delay(15000);
    SDL_Quit();
}

void drawEnity( display *d,int what,int x, int y){
    int px=x*d->imagewidth;
    int py=y*d->imageheigth;
    SDL_Surface *image=d->image[what];
    if (image==NULL) {
        SDL_Fail("No image");
    }
    
    SDL_Rect box_structure={px,py,20,20};
    SDL_Rect *box=&box_structure;
    int r=SDL_BlitSurface(image,NULL,d->surface,box);
    if (r<0) {
        SDL_Fail("Bad image display");
    }
}

static void SDL_Fail(char *s) {
    fprintf(stderr,"%s %s \n",s,SDL_GetError());
    SDL_Quit();
    exit(1);
}
