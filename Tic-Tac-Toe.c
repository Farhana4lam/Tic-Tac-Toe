#include <stdio.h>

#include <stdlib.h>

char m[3][3];

void initialization()
{
    int i,j;

    for (i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            m[i][j]= ' ';
        }
    }
}

void hum()
{
    int x,y;

    printf("Enter the position for your move:");
    scanf("%d %d",&x,&y);
    x--;
    y--;

    if(m[x][y]!= ' ')
    {
        printf("Invalid move\n");
        hum();
    }
    else
    {
        m[x][y] = 'X';
    }
}

void comp()
{

    /*int i,j;
    for(i=0;i<3;i++)
    {
    for(j=0;j<3;j++)
    if (m[i][j]==' ')
    break;
    if(m[i][j]==' ')
    break;
    }
    if(i*j == 9)
       {
           printf("Draw\n");

           exit(0);
       }
        else
        {
            m[i][j] = 'O';
        }*/
    int x,y;
    time_t t;
    srand((unsigned) time(&t));
    x=rand()%3;
    y=rand()%3;
    if(m[x][y]==' ')
    {
         m[x][y]='O';
    }
    else
    {
        comp();
    }

}

void disp()
{
    int i;
printf("     1   2   3\n\n");
for(i=0;i<3;i++)
   {
   printf("%d   %c | %c | %c \n",i+1,m[i][0],m[i][1],m[i][2]);
   if(i<2)
    printf("   ---|---|---\n");
   }
}

char check()
{
    int i;
    for (i=0;i<3;i++)
    {
        if(m[i][0]==m[i][1] && m[i][0]==m[i][2])
        {
            return m[i][0];
        }
    }

    for(i=0;i<3;i++)
    {
        if(m[0][i]==m[1][i] && m[0][i]==m[2][i])
        {
            return m[0][i];
        }
    }

    if (m[0][0]==m[1][1] && m[1][1]==m[2][2])
    {
        return m[0][0];
    }

    if (m[0][2]==m[1][1] && m[1][1]==m[2][0])
    {
        return m[0][2];
    }

    return ' ';
}


int main()
{
    char result;
    printf("   Tic-Tac-Toe\n\n");

    result=' ';

    initialization();

    do
    {
        disp();
        hum();
        result = check();

        if (result!= ' ')
        {
            break;
        }

        comp();
        result = check();
    }
    while (result == ' ');
if (result == 'X')
{
    printf("\nYou won\n");

}
else
{
    printf("\nComputer won\n");
}

disp();

return 0;
}
