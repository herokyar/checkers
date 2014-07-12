checkers
========
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

char position[8][8];		//define all the positions on the board
 
void board()
{
	system("cls");	//refresh the screen each time, you call the function
	cout << "WELCOME TO CHECKERS GAME 8X8 ..." << endl << endl;

	cout << "  " << "1" << " " << "2" << " " << "3" << " " << "4" << " " << "5" << " " << "6" << " " << "7" << " " << "8" << " " << endl;      
	for (int i=0; i<8; i++)
	{
		cout << i+1 << " " ;
		for (int j=0; j<8; j++)
		{
			cout << position[i][j] << "|";
		}
		cout << endl;
	}


}

int checkwin()
{
	if (position[0][0] == position[0][1] && position[0][1] == position[0][2] && position[0][2] == position[0][3])
	{
		return 1;
	}
	else if (position[1][0] == position[1][1] && position[1][1] == position[1][2] && position[1][2] == position[1][3])
	{
		return 1;
	}
	else if (position[2][0] == position[2][1] && position[2][1] == position[2][2] && position[2][2] == position[2][3])
	{
		return 1;
	}
	else if (position[3][0] == position[3][1] && position[3][1] == position[3][2] && position[3][2] == position[3][3])
	{
		return 1;
	}
	else if (position[0][0] == position[1][0] && position[1][0] == position[2][0] && position[2][0] == position[3][0])
	{
		return 1;
	}
	else if (position[0][1] == position[1][1] && position[1][1] == position[2][1] && position[2][1] == position[3][1])
	{
		return 1;
	}
	else if (position[0][2] == position[1][2] && position[1][2] == position[2][2] && position[2][2] == position[3][2])
	{
		return 1;
	}
	else if (position[0][3] == position[1][3] && position[1][3] == position[2][3] && position[2][3] == position[3][3])
	{
		return 1;
	}
		else if (position[0][0] == position[1][1] && position[1][1] == position[2][2] && position[2][2] == position[3][3])
	{
		return 1;
	}
		else if (position[0][3] == position[1][2] && position[1][2] == position[2][1] && position[2][1] == position[3][0])
	{
		return 1;		
	}
	else if (position[0][0] != 1 && position[0][1] != 2 && position[0][2] != 3 && position[0][3] != 4 && position[1][0] != 5 && position[1][1] != 6 && position[1][2] != 7 &&  position[1][3] != 8 && position[2][0] != 9 && position[2][1] != 10 && position[2][2] != 11 && position[2][3] != 12 && position[3][0] != 13 && position[3][1] != 14 && position[3][2] != 15 && position[3][3] != 16)
	{
		return 2;		//its a tie game 
	}

	else
	{
		return 0;		//game continues....
	}


}


int main()
{
	//define the characters on the board...
	position[0][1] = 'x';
	position[0][3] = 'x';
	position[0][5] = 'x';
	position[0][7] = 'x';
	position[1][0] = 'x';
	position[1][2] = 'x';
	position[1][4] = 'x';
	position[1][6] = 'x';
	position[2][1] = 'x';
	position[2][3] = 'x';
	position[2][5] = 'x';
	position[2][7] = 'x';

	position[5][0] = 'o';
	position[5][2] = 'o';
	position[5][4] = 'o';
	position[5][6] = 'o';
	position[6][1] = 'o';
	position[6][3] = 'o';
	position[6][5] = 'o';
	position[6][7] = 'o';
	position[7][0] = 'o';
	position[7][2] = 'o';
	position[7][4] = 'o';
	position[7][6] = 'o';

	// all the positions on the board should be defined...thats the programming basics....
	for(int i=0; i<8; i++)
	{
		for (int j=0; j<8; j++)
		{
			if( position[i][j] != 'x' && position[i][j] != 'o')		//if the position is not equal to x and o 
			{
				position[i][j] = ' ';		//define a blank space for all the other positions
			}

		}

	}



	int game_condition=0;		//initial value
	int player=1;				//initial value of player 
	
	string first_index;		//define first index
	string second_index;		//define second index
	string third_index;		//define third index
	string fourth_index;		//define fourth index

	char delimiter = ' ';   //define the user input as (a,b) //use comma in between

	char mark;			//define a char ((not int:)))
 

	board();

	 
	 while ( game_condition == 0)
	 {
		 
		 player = (player % 2) ? 1 : 2;		//select player procedure 

		 cout << endl << "current player " << player << endl;
		 cout << "enter a move ex: 6 3 5 4 :"  ;

		 
		 getline(cin, first_index, delimiter);	//it only reads in string
		 getline(cin, second_index, delimiter);	//it only reads in string
		 getline(cin, third_index, delimiter);	//it only reads in string
		 getline(cin, fourth_index);			//it only reads in string
		 // we have to convert string to integer in order to use them in the position

		 int first_index_int;		//convert string to integer
		 int second_index_int;		//convert string to integer
		 int third_index_int;		//convert string to integer
		 int fourth_index_int;		//convert string to integer

		 stringstream(first_index) >> first_index_int;		//here do the conversion from string to int
		 stringstream(second_index) >> second_index_int;
		 stringstream(third_index) >> third_index_int;
		 stringstream(fourth_index) >> fourth_index_int;


		  mark = (player == 1) ? 'o' : 'x';		//select mark procedure
			
		int input;
		  

		 
		//start from here , remember to initialize all the values.........
		if(  position[third_index_int-1][fourth_index_int-1] == ' ' && abs(first_index_int-third_index_int) == 1)
		 {
			 position[first_index_int-1][second_index_int-1] = ' ';
			 position[third_index_int-1][fourth_index_int-1] = mark;

		 }
		else if (position[third_index_int-1][fourth_index_int-1] != ' ' && position[(first_index_int+third_index_int)/2-1][(second_index_int+fourth_index_int)/2-1] == (player == 1) ? 'x' : 'o'  && abs(first_index_int-third_index_int) == 2)
		  {
			  position[first_index_int-1][second_index_int-1] = ' ' ;
			  position[(first_index_int+third_index_int)/2-1][(second_index_int+fourth_index_int)/2-1] = ' ';
			  position[third_index_int-1][fourth_index_int-1] = mark;
			  
		  }
	 	else 
		{
			cout << "invalid move, try again.." << endl;
			player++;

		}

		  //cin >> first_index_int;
		  //cin >> second_index_int;
		  //position[first_index_int-1][second_index_int-1] = 'k';

			   board();

			   player++;

			   //temporarily removed from the program
			   //game_condition = checkwin();
	 }

	 if (game_condition == 1)
	 {
		
		 --player;
		 player = (player % 2) ? 1 : 2;
		 cout << "player " << player << "wins..." << endl;
	 }
	 
	 if (game_condition == 2)
	 {
		 cout << "its a tie game! " << endl;
	 }
	 
 
	 

	return 0;
}


//the program is not finished....(most of the coding is done...)
//check for legal moves
//and check whether the game is over.
//and then support kinging....



 
