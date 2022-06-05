#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// This function counts with a counter the number of mines around a box by checking one by one the boxes around.
int numberofminesaround ( int **grid, int gridsize, int row, int column )
{
    int counter=0;
    if ( row != 0 && column !=0 && row!=gridsize && column!=gridsize )
    {
        if ( grid[row][column-1] ==9 )
        { 
            counter++;
        }
        if ( grid[row][column+1] ==9 )
        { 
            counter++;
        }
        if ( grid[row-1][column] ==9 )
        { 
            counter++;
        }
        if ( grid[row+1][column] ==9 )
        { 
            counter++;
        }
        if ( grid[row-1][column-1] ==9)
        { 
            counter++;
        }
        if ( grid[row-1][column+1] ==9)
        { 
            counter++;
        }
        if ( grid[row+1][column-1] ==9)
        { 
            counter++;
        }
        if ( grid[row+1][column+1] ==9)
        { 
            counter++;
        }
    }
    else if ( row == gridsize && column !=0 && column !=gridsize )
    {
        if ( grid[row][column-1] ==9 )
        { 
            counter++;
        }
        if ( grid[row][column+1] ==9 )
        { 
            counter++;
        }
        if ( grid[row-1][column] ==9 )
        { 
            counter++;
        }
        if ( grid[row-1][column-1] ==9)
        { 
            counter++;
        }
        if ( grid[row-1][column+1] ==9)
        { 
            counter++;
        }
    }
    else if ( row == 0 && column != 0 && column !=gridsize )
    {
        if ( grid[row][column-1] ==9 )
        { 
            counter++;
        }
        if ( grid[row][column+1] ==9 )
        { 
            counter++;
        }
        if ( grid[row+1][column] ==9 ){ 
            counter++;
        }
        if ( grid[row+1][column-1] ==9)
        { 
            counter++;
        }
        if ( grid[row+1][column+1] ==9)
        { 
            counter++;
        }
    }
    else if ( column == gridsize && row!=0 && row!=gridsize )
    {
        if ( grid[row][column-1] ==9 )
        { 
            counter++;
        }
        if ( grid[row-1][column] ==9 )
        { 
            counter++;
        }
        if ( grid[row+1][column] ==9 )
        { 
            counter++;
        }
        if ( grid[row-1][column-1] ==9)
        { 
            counter++;
        }
        if ( grid[row+1][column-1] ==9)
        { 
            counter++;
        }
    }
    else if ( column == 0 && row !=0 && row!=gridsize )
    {
        if ( grid[row][column+1] ==9 )
        { 
            counter++;
        }
        if ( grid[row-1][column] ==9 )
        { 
            counter++;
        }
        if ( grid[row+1][column] ==9 )
        { 
            counter++;
        }
        if ( grid[row-1][column+1] ==9)
        { 
            counter++;
        }
        if ( grid[row+1][column+1] ==9)
        { 
            counter++;
        }
    }
    else if ( row == 0 && column == gridsize )
    {
        if ( grid[row+1][column] ==9 )
        { 
            counter++;
        }
        if ( grid[row][column-1] ==9 )
        { 
            counter++;
        }
        if ( grid[row+1][column-1] ==9)
        { 
            counter++;
        }
    }
    else if ( row ==0 && column == 0 )
    {
        if ( grid[row][column+1] ==9 )
        { 
            counter++;
        }
        if ( grid[row+1][column] ==9 )
        { 
            counter++;
        }
        if ( grid[row+1][column+1] ==9)
        { 
            counter++;
        }
    }
    else if ( row == gridsize && column == gridsize )
    {
        if ( grid[row-1][column-1] ==9)
        { 
            counter++;
        }
        if ( grid[row][column-1] ==9 )
        { 
            counter++;
        }
        if ( grid[row-1][column] ==9 )
        { 
            counter++;
        }
    }
    else if ( row == gridsize && column == 0)
    {
        if ( grid[row-1][column] ==9 )
        { 
            counter++;
        }
        if ( grid[row-1][column+1] ==9)
        { 
            counter++;
        }
        if ( grid[row][column+1] ==9 )
        { 
            counter++;
        }
    }
    return counter;
}


//This function is the main function, it serves to be compiled without calling it and it has all the instructions for the game to work.
//It also finalizes the game by saying if the player has won or lost.
int main()
{
    int size;
    int minenb;
    int i;
    int numberoffreesquares;
    printf("Taille : ");
    scanf("%d", &size);
    numberoffreesquares = size *size;
    int **grid;
    grid = (int** ) malloc(size * sizeof(int*));
    for (i=0;i<size;i++)
    {
        grid[i] = (int*) malloc ( size * sizeof(int));
    }
    minenb=minenumber (size);
    srand(time(NULL));
    initializemines ( grid, size, minenb);
    while ( numberoffreesquares != -1 || numberoffreesquares !=0)
    {
        displaygrid( grid,size);
        numberoffreesquares = play ( grid, size, minenb, numberoffreesquares);
        if (numberoffreesquares == 0 )
        {
            printf("Bien joué \n");
            break;
        }
        if (numberoffreesquares == -1 )
        {
             printf("BOUM, dommage c'est perdu \n");
             break;
        }
    }
}


// This procedure is used to ask the user for his choice for the move, then the row and the column.
void seizure( char shot[4],int **grid, int gridsize, int *row, int *column )
{
    while (strcmp(shot,"b") != 0 && strcmp(shot,"c") != 0 && strcmp(shot,"a") != 0 ){
        menu();
        scanf("%c", shot);
    }
 
}

// This procedure is used to place the mines randomly by putting the free squares equal to -3 and the squares with mines equal to 9.
void initializemines ( int **grid, int size, int minenb)
{
    int row;
    int column;
    int i;
    for (i=0;i<size;i++)
    {
        int j;
        for(j=0;j<size;j++)
        {
            grid[i][j] = -3;
        }
    }
    for ( i=0 ; i<minenb ; i++ )
    {
        do
        {
        row = (int)((rand()/(double)RAND_MAX) * size);
        column = (int)((rand()/(double)RAND_MAX) * size);
        }while (grid[row][column] == 9 );
        grid[row][column] = 9;
    }
}


// This procedure makes it possible to display the grid with for the hidden boxes "X", for the revealed boxes numbers from 1 to 7 and finally for the boxes mark "D".
void displaygrid ( int **grid, int gridsize)
{
    int i;
    for ( i=0 ; i<gridsize ; i++ )
    {
        int j;
        if ( i == 0 )
        {
            printf("    ");
            for ( j=0;j<gridsize;j++)
            {
                printf(" %d ",j);
            }
            printf("\n");
        }
         
        printf(" %d  ",i);
        for ( j=0 ; j<gridsize ; j++ )
        {
            if ( grid[i][j] == -2 ) printf(" D ");
            else if ( grid[i][j] == 9 || grid[i][j] == -3)
            {
                printf(" X ");
            }
            else if ( grid[i][j] >=0 && grid[i][j] <9)
            {
                printf(" %d ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

// This function makes it possible to make the actions of the game according to the choices made by the user and then according to the choice of the user to ask him the column and the row of his choice.
int play (int **grid, int gridsize, int minenb, int numberoffreesquares)
{
    char shot[4];
    int row=0;
    int column=0;
    menu();
    scanf("%s", shot);
    seizure(shot,grid,gridsize,&row,&column);
    if ( strcmp(shot,"b") == 0)
    {
        printf("Colonne : ");
        scanf ("%d", &column);
        printf("\nLigne : ");
        scanf("%d", &row);
        seizure(shot, grid, gridsize, &row, &column );
        if ( grid[row][column]== 9 ) 
        {
            return -1;
        }
        else
        {
            grid[row][column] = numberofminesaround(grid, gridsize,row,column);
            numberoffreesquares -1;
            return numberoffreesquares;
        }
    }
    else if ( strcmp(shot,"a") == 0 )
    {
        return -1;
    }
    else if ( strcmp(shot,"c") == 0)
    {
        printf("Colonne : ");
        scanf ("%d", &column);
        printf("\nLigne : ");
        scanf("%d", &row);
        seizure(shot,grid, gridsize, &row, &column);
        grid[row][column]=-2;
        return numberoffreesquares;
    } 
}


// This procedure is used to display the different choices that the user will have to make.
void menu()
{
    printf(" *a* Abandonner de la partie \n");
    printf(" *b* Decouvrir une case du jeu \n");
    printf(" *c* Marqueur une case du jeu\n\n");
    printf("A vous de jouer : \n");
}

 
// This function is used to ask the user how many mines he wants in his grid.
int minenumber ( int gridsize )
{
    int minenb;
    printf("Combien de mines choisissez-vous ?\n");
    scanf("%d", &minenb);

    if ( (minenb <= gridsize * gridsize -1) || (minenb>=1) ){
        return minenb;
    }
    else return -1;
}     