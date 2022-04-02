//Accessories



#include "header.h"
int writetofile(char comp[20][12])
{
    FILE* temp;
    int i,j;
    char ch;
    if ((temp=fopen("temp.lvl","w"))==NULL) return no;
    for (i=0;i<20;i++)
     {
        for (j=0;j<12;j++)
        {           
             if ((ch=='a' || ch=='b' || ch=='c' || ch=='d' || ch=='e' || ch=='f' )) ch=comp[i][j];
        }
    }
    for (i=0;i<20;i++)
     {
        for (j=0;j<12;j++)
        {
            ch='#';
           if ((ch=='a' || ch=='b' || ch=='c' || ch=='d' || ch=='e' || ch=='f' )) ch=comp[i][j];
                   fprintf(temp,"%d %d %c ",i,j,ch);
        }
     }
    fclose(temp);
    return yes;
}
void load_array(char comp[20][12],SDL_Surface* screen)
{
    int i,j;
    SDL_Surface* border_pic=load_image("borders.gif");
    SDL_Rect left_top,right_top,left_bottom,right_bottom,horizontal,vertical;
    SDL_Rect plotter;  //stores cursor to where pic to be loaded
    left_top.x=0;left_top.y=0;left_top.w=24;left_top.h=24;
    right_top.x=24;right_top.y=0;right_top.w=24;right_top.h=24;
    left_bottom.x=48;left_bottom.y=0;left_bottom.w=24;left_bottom.h=24;
    right_bottom.x=72;right_bottom.y=0;right_bottom.w=24;right_bottom.h=24;
    horizontal.x=96;horizontal.y=0;horizontal.w=24;horizontal.h=24;
    vertical.x=120;vertical.y=0;vertical.w=24;vertical.h=24;
    for (i=0;i<20;i++)
        for (j=0;j<12;j++)
        {
            plotter.x=10+i*24;
            plotter.y=11+j*24;
            if (comp[i][j]=='a')  SDL_BlitSurface(border_pic,&left_top,screen,&plotter);
            else if (comp[i][j]=='b')  SDL_BlitSurface(border_pic,&right_top,screen,&plotter);
            else if (comp[i][j]=='c')  SDL_BlitSurface(border_pic,&left_bottom,screen,&plotter);
            else if (comp[i][j]=='d')  SDL_BlitSurface(border_pic,&right_bottom,screen,&plotter);
            else if (comp[i][j]=='e')  SDL_BlitSurface(border_pic,&horizontal,screen,&plotter);
            else if (comp[i][j]=='f')  SDL_BlitSurface(border_pic,&vertical,screen,&plotter);
        }
}




//Map



#include "header.h"
void createmap(SDL_Surface* screen,char comp[20][12]) //plots the map from database
{
    int i,j,k;
    char  ch;
    FILE *fp;
    if ((fp=fopen("temp.lvl","r"))==NULL) return;
    SDL_Rect left_top,right_top,left_bottom,right_bottom,horizontal,vertical;
    SDL_Rect plotter;  //stores cursor to where pic to be loaded
    left_top.x=0;left_top.y=0;left_top.w=24;left_top.h=24;
    right_top.x=24;right_top.y=0;right_top.w=24;right_top.h=24;
    left_bottom.x=48;left_bottom.y=0;left_bottom.w=24;left_bottom.h=24;
    right_bottom.x=72;right_bottom.y=0;right_bottom.w=24;right_bottom.h=24;
    horizontal.x=96;horizontal.y=0;horizontal.w=24;horizontal.h=24;
    vertical.x=120;vertical.y=0;vertical.w=24;vertical.h=24;
    SDL_Surface* border_pic;
    border_pic=load_image("borders.gif");
   //while (1)
    for (k=0;k<240;k++)
    {
        fscanf(fp,"%d %d %c ",&i,&j,&ch);
       // if (i==-1 && j==-1 && ch=='z') break;
        comp[i][j]=ch;
    }
     for (i=0;i<20;i++)
        for (j=0;j<12;j++)
        {
            plotter.x=10+i*24;
            plotter.y=11+j*24;
            if (comp[i][j]=='a')  SDL_BlitSurface(border_pic,&left_top,screen,&plotter);
            else if (comp[i][j]=='b')  SDL_BlitSurface(border_pic,&right_top,screen,&plotter);
            else if (comp[i][j]=='c')  SDL_BlitSurface(border_pic,&left_bottom,screen,&plotter);
            else if (comp[i][j]=='d')  SDL_BlitSurface(border_pic,&right_bottom,screen,&plotter);
            else if (comp[i][j]=='e')  SDL_BlitSurface(border_pic,&horizontal,screen,&plotter);
            else if (comp[i][j]=='f')  SDL_BlitSurface(border_pic,&vertical,screen,&plotter);
        }
fclose(fp);
}
void build_map(SDL_Surface* screen) // map maker...it saves the map to database
{
    extern int quit;
    int what_key;
    char comp[20][12]   ,   ch;
    int i,j;
  /*for (i=0;i<20;i++)
    {
             ch='*' ;
             for (j=0;j<12;j++)
        {
            comp[i][j]=ch ;
        }
    }
*/
    SDL_Rect left_top,right_top,left_bottom,right_bottom,horizontal,vertical;
    SDL_Rect plotter={10,11};  //stores cursor to where pic to be loaded
    left_top.x=0;left_top.y=0;left_top.w=24;left_top.h=24;
    right_top.x=24;right_top.y=0;right_top.w=24;right_top.h=24;
    left_bottom.x=48;left_bottom.y=0;left_bottom.w=24;left_bottom.h=24;
    right_bottom.x=72;right_bottom.y=0;right_bottom.w=24;right_bottom.h=24;
    horizontal.x=96;horizontal.y=0;horizontal.w=24;horizontal.h=24;
    vertical.x=120;vertical.y=0;vertical.w=24;vertical.h=24;
    SDL_Surface* border_pic;
    border_pic=load_image("borders.gif");
    SDL_Surface* tick_mark;
    tick_mark=load_image("tick_mark.gif");
    SDL_Rect tick_up, tick_over,tick_location;
    tick_up.x=0;tick_up.y=0; tick_up.w=50;tick_up.h=30;
    tick_over.x=50;tick_over.y=0; tick_over.w=50;tick_over.h=30;
    tick_location.x=445; tick_location.y=315;
    SDL_BlitSurface(tick_mark,&tick_up,screen,&tick_location);
    SDL_Event key_pressed;
    while (quit==no)
    {
           while(SDL_PollEvent(&key_pressed))
           {
                if(key_pressed.type==SDL_QUIT) quit=yes;
                if (key_pressed.type==SDL_KEYDOWN) what_key=key_pressed.key.keysym.sym;
                if (key_pressed.type==SDL_MOUSEMOTION)
                {
                    if (key_pressed.motion.x >= tick_location.x && key_pressed.motion.x <= tick_location.x+50 && key_pressed.motion.y >= tick_location.y && key_pressed.motion.y <= tick_location.y+30)
                                SDL_BlitSurface(tick_mark,&tick_over,screen,&tick_location);
                    else SDL_BlitSurface(tick_mark,&tick_up,screen,&tick_location);

                }
                 if (key_pressed.type== SDL_MOUSEBUTTONDOWN)
                 {
                     if (key_pressed.button.button==SDL_BUTTON_LEFT && key_pressed.button.x>=tick_location.x && key_pressed.button.x<=tick_location.x+50 && key_pressed.button.y>=tick_location.y && key_pressed.button.y<=tick_location.y+30)
                            { writetofile(comp);   }
                 }
            }
            switch (what_key)
                {
                    case SDLK_UP:
                    plotter.y-=24;
                    break;
                    case SDLK_DOWN:
                    plotter.y+=24;
                    break;
                    case SDLK_RIGHT:
                    plotter.x+=24;
                    break;
                    case SDLK_LEFT:
                    plotter.x-=24;
                    break;
                    case SDLK_a:
                                    comp[(plotter.x-10)/24][(plotter.y-11)/24]='a';
                    break;
                    case SDLK_b:
                                        comp[(plotter.x-10)/24][(plotter.y-11)/24]='b';
                    break;
                    case SDLK_c:
                                        comp[(plotter.x-10)/24][(plotter.y-11)/24]='c';
                    break;
                    case SDLK_d:
                                        comp[(plotter.x-10)/24][(plotter.y-11)/24]='d';
                    break;
                    case SDLK_e:
                                        comp[(plotter.x-10)/24][(plotter.y-11)/24]='e';
                    break;
                    case SDLK_f:
                                        comp[(plotter.x-10)/24][(plotter.y-11)/24]='f';
                    break;
                    default:
                    SDL_BlitSurface(load_image("builder_cursor.gif"),NULL,screen,&plotter);
                    SDL_Flip(screen);
                    SDL_Delay(50);
                    SDL_BlitSurface(load_image("builder_cursor_follow.gif"),NULL,screen,&plotter);
                    break;
                }
//limits editor_cursor upto editor portion only
                if (plotter.x<10) plotter.x=466;
                if (plotter.x>466) plotter.x=10;
                if (plotter.y<11) plotter.y=275;
                if (plotter.y>275) plotter.y=11;
//end of limit
            SDL_Flip(screen);
            what_key=(int)NULL;
            load_array(comp,screen);
            SDL_Flip(screen);
    }
    SDL_FreeSurface(border_pic);
return;
}




//Main



#include "header.h"
SDL_Rect cor={24,25};
int quit=no;
SDL_Surface *load_image( char filename[] )
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    //Load the image
    char file[]="sprites/";
    strcat(file,filename);
    loadedImage = IMG_Load( file);
    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
     //Return the optimized image
    return optimizedImage;
}
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface* screen;
    screen=SDL_SetVideoMode(500,350,32,SDL_SWSURFACE);
    SDL_Surface* bg=load_image("dark.jpg");
    int key_press;
    SDL_WM_SetIcon(IMG_Load("pacman_16X16.png"), NULL);
    SDL_WM_SetCaption("Pacman","pacman_16X16.png");
    SDL_Event event;
    extern int quit;
    SDL_BlitSurface(bg,NULL,screen,NULL);
  // build_map(screen);
    gameplay(screen);
    return 0;
}
void pacman_sprites(SDL_Rect location,int direction,SDL_Surface* screen,char comp[20][12])
{
    SDL_Rect char_up,char_down,char_left,char_right,char_neutral,char_dead;
//definition of sprites
    char_up.x=0; char_up.y=20;  char_up.w=20;  char_up.h=20;
    char_down.x=20; char_down.y=20;  char_down.w=20;  char_down.h=20;
    char_left.x=20; char_left.y=0;  char_left.w=20;  char_left.h=20;
    char_right.x=40; char_right.y=0;  char_right.w=20;  char_right.h=20;
    char_neutral.x=0; char_neutral.y=0;  char_neutral.w=20;  char_neutral.h=20;
    char_dead.x=40; char_dead.y=20;  char_dead.w=20;  char_dead.h=20;
// end def of sprites
    SDL_Surface *one,*two;
    one=load_image("pacman.gif");
    two=load_image("pacman_follow.gif");
    if  (legibility(comp,&direction)==yes)
    {
        moveit(direction); // it just changes  the co-ordinates.....doesnt animate sprites
    switch(direction)
    {
        case SDLK_UP:
        SDL_BlitSurface(one,&char_up,screen,&location);
        SDL_Flip(screen);
        break;
        case SDLK_DOWN:
        SDL_BlitSurface(one,&char_down,screen,&location);
        SDL_Flip(screen);
        break;
        case SDLK_RIGHT:
        SDL_BlitSurface(one,&char_right,screen,&location);
        SDL_Flip(screen);
        break;
        case SDLK_LEFT:
        SDL_BlitSurface(one,&char_left,screen,&location);
        SDL_Flip(screen);
        break;
    }
    SDL_Delay(75);
    SDL_BlitSurface(one,&char_neutral,screen,&location);
    SDL_Flip(screen);
    SDL_Delay(75);
    SDL_BlitSurface(two,NULL,screen,&location);
    SDL_Flip(screen);
    }
    else
    {
        //SDL_Delay(1000);
        SDL_BlitSurface(one,&char_neutral,screen,&location);
        SDL_Flip(screen);
    }
    SDL_FreeSurface(one);
    SDL_FreeSurface(two);

}
void gameplay(SDL_Surface* screen)
{
    extern int quit;
    char comp[20][12];
    extern SDL_Rect cor;
    SDL_Event event;
    int key_press;
    createmap(screen,comp);
    while (quit==no)
    {
           while(SDL_PollEvent(&event))
           {
                if(event.type==SDL_QUIT) quit=yes;
                if (event.type==SDL_KEYDOWN)   key_press=event.key.keysym.sym;
            }
            pacman_sprites(cor,key_press,screen,comp);
    }
}




//Move_guide



#include "header.h"
int legibility(char comp[20][12],int *direction)
{
    int x,y;// equivalent of cor to array-no
    char around[4];   // stores the values around pacman
    static int prev_direction;
    SDL_Rect cordinate;
    extern SDL_Rect cor;
    if (cor.x>500) cor.x=0;
    if (cor.y>350) cor.y=0;
    if (cor.x<0) cor.x=500;
    if (cor.y<0) cor.y=350;
    cordinate.x=cor.x+10;
    cordinate.y=cor.y+10;
    x=(cor.x-10-1)/24;
    y=(cor.x-11-1)/24;
    what_is_around(around,comp);
     switch(*direction)
    {
        case SDLK_UP:
                if ((around[0]=='a') || (around[0]=='e') || (around[1]=='b'))
                {
                    *direction=prev_direction;
                }
        break;
        case SDLK_DOWN:
                /*if ((around[7]=='e' && around[7]=='a' && around[7]=='b'))
                {
                    *direction=prev_direction;
                }*/
         break;
        case SDLK_RIGHT:
        break;
        case SDLK_LEFT:
        break;
    }
    prev_direction=*direction;
    return yes;
}
void moveit(int key_press)
{
    extern SDL_Rect cor;
    int i;
//    static int prev_key;
 //   if (prev_key==key_press)   {
            switch (key_press)
            {
            case SDLK_UP:               cor.y-=speed; break;
            case SDLK_DOWN:            cor.y+=speed; break;
            case SDLK_RIGHT:            cor.x+=speed; break;
            case SDLK_LEFT:            cor.x-=speed; break;
            }
   /* }
    else
    {
        switch (key_press)
            {
            case SDLK_UP:
            if ((cor.x+10)%24==0 && (cor.y+11)%24==0)   cor.y-=speed;
            else
            {
                for (i=cor.y+10;(cor.y+10)%24!=0;i++)   cor.y++;
            }
             break;
            case SDLK_DOWN:            cor.y+=speed; break;
            case SDLK_RIGHT:            cor.x+=speed; break;
            case SDLK_LEFT:            cor.x-=speed; break;
            }
    }
    prev_key=key_press;         */
}
void what_is_around(char a[],char comp[20][12])
{
    extern SDL_Rect cor;
    char ch;
    SDL_Rect box;
    box.x=(cor.x-10+10-1)/24;
    box.y=(cor.y-11+10-1)/24;
    ch=comp[box.x-1][box.y-1];
    if ((ch=='a' || ch=='b' || ch=='c' || ch=='d' || ch=='e' || ch=='f' )) a[0]=ch;
    else a[0]='$';
    ch=comp[box.x+1][box.y-1];
    if ((ch=='a' || ch=='b' || ch=='c' || ch=='d' || ch=='e' || ch=='f' )) a[1]=ch;
    else a[1]='$';
    ch=comp[box.x-1][box.y+1];
    if ((ch=='a' || ch=='b' || ch=='c' || ch=='d' || ch=='e' || ch=='f' )) a[3]=ch;
    else a[2]='$';
    ch=comp[box.x+1][box.y+1];
    if ((ch=='a' || ch=='b' || ch=='c' || ch=='d' || ch=='e' || ch=='f' )) a[5]=ch;
    else a[3]='$';
}
