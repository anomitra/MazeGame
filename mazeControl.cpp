#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

bool checkBounds(int x,int y);
void setHighScore(char name[], double time);
void getHighScore();
void gameOver();

int maze[25][40];
int x=2,y,x_end,y_end;
clock_t t;
void getMaze(FILE* fp)
{
    int i=0,j=0;
    char ch;
    fscanf(fp,"%c %d %d",&ch,&x,&y);
    printf("%d %d",x,y);
    getch();
    while(feof(fp)==0)
    {
        ch=fgetc(fp);
        if(ch=='\n')
        {
            i++;
            j=0;
        }
        else if(ch=='*')
        {
            x=i;
            y=j;
            maze[i][j++]=ch;
        }
        else if(ch=='p')
        {
            x_end=i;
            y_end=j;
            maze[i][j++]=ch;
        }
        else
            maze[i][j++]=ch;
    }
}

void moveToken(char dir)
{
    maze[x][y]=' ';
    switch(dir)
    {
        case 'w':
            x--;
            checkBounds(x,y);
            break;
        case 's':
            x++;
            checkBounds(x,y);
            break;
        case 'a':
            y--;
            checkBounds(x,y);
            break;
        case 'd':
            y++;
            checkBounds(x,y);
            break;
        default:
            break;
    }
    maze[x][y]='*';
}

void display()
{
    printf("---%*s%*s---\n",25,"BEHOLD THE MAZE!",9,"");
    printf("\n\n");
    int i,j;
    for(i=0;i<23;i++)
    {
        if(i==0)
            continue;
        int temp=16;
        char cc=(char)temp;
        for(j=0;j<40;j++)
        {
            if(maze[i][j]=='@')
                printf("%c",'\u00b2');
            else if(maze[i][j]=='p')
                printf("%c",cc);
            else
                printf("%c",maze[i][j]);
        }
        printf("\n");
    }
}

bool checkBounds(int k,int l)
{
    /*if(maze[k][l]=='\u00b2')
        gameOver();*/
    if(maze[k][l]=='p')
    {
        printf("You have won the game!\n");
        t=clock()-t;
        float tim=((float)t/CLOCKS_PER_SEC);
        printf("Time taken is: %.2f",tim);
        getch();
        exit(0);
    }
    if(maze[k][l]!=' ')
        gameOver();
}

void gameOver()
{
    printf("You have hit the wall!\a\a\a");
    t=clock()-t;
    float tim=((float)t/CLOCKS_PER_SEC);
    printf("Time taken is: %.2f",tim);
    exit(0);
}

int main()
{
    FILE* fp=fopen("maze1.txt","r");
    getMaze(fp);
    //printf("---%*s%*s---\n",25,"BEHOLD THE MAZE!",9,"");
    printf("\n\n");
    display();
    int f=0;
    while(1)
    {
        int ch;
        //scanf("%c",ch);
        ch=getch();
        moveToken(ch);
        if(f==0)
        {
            t=clock();
            f--;
        }
        system("cls");
        display();
    }
    return 0;
}
