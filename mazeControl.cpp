#include <stdio.h>
#include <stdlib.h>

/* UNDECLARED FUNCTIONS, TO BE WRITTEN */

bool checkBounds(int x,int y);
void setHighScore(char name[], double time);
void getHighScore();

int maze[25][40];
int x=1;
int y=0; // STARTING POSITION, CHANGE LATER
void getMaze(FILE* fp)
{
    int i=0,j=0;
    char ch;
    while(feof(fp)==0)
    {
        ch=fgetc(fp);
        if(ch=='\n')
        {
            i++;
            j=0;
        }
        else
            maze[i][j++]=ch;
    }
}

void moveToken(char dir)
{
    switch(dir)
    {
        case 'w':
            x--;
            //checkBounds(x,y);
            break;
        case 's':
            x++;
            //checkBounds(x,y);
            break;
        case 'a':
            y--;
            //checkBounds(x,y);
            break;
        case 'd':
            y++;
            //checkBounds(x,y);
            break;
        default:
            break;
    }
}

void display()
{
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

int main()
{
    FILE* fp=fopen("maze1.txt","r");
    getMaze(fp);
    display();
    return 0;
}
