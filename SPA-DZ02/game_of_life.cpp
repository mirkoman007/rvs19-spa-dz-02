#include"game_of_life.h"
#include<ctime>

bool game_of_life::slucajna_vrijednost()
{
	int test = rand() % (4 - 1+1)+1;//25%
	if (test == 1)
		return true;
	else
		return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	return _generacija[i][j];
}

int game_of_life::br_susjeda(int x, int y)
{
	int brojac = 0;


	for (int i = x-1; i <= x+1; i++)
	{
		if (i >= 0 || i < REDAKA)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (j >= 0 || j < STUPACA)
				{
					if (!(i == x && j == y))
					{
						if (celija_zauzeta(i, j))
							brojac++;
					}

				}

			}
		}
	}



	return brojac;
}

game_of_life::game_of_life()
{

	srand(time(nullptr));
	for (unsigned i = 0; i < REDAKA; i++)
	{
		for (unsigned j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
	for (unsigned i = 0; i < REDAKA; i++)
	{
		for (unsigned j = 0; j < STUPACA; j++)
		{
			_sljedeca_generacija[i][j]=false;
		}
	}
}



void game_of_life::sljedeca_generacija()
{
	for (unsigned i = 0; i < REDAKA; i++)
	{
		for (unsigned j = 0; j < STUPACA; j++)
		{
			if (celija_zauzeta(i, j) == false)
			{
				if (br_susjeda(i,j) == 3)
					_sljedeca_generacija[i][j] = true;
			}
			else
			{
				if (br_susjeda(i, j) == 2 || br_susjeda(i, j) == 3) {
					_sljedeca_generacija[i][j] = _generacija[i][j];
				}
				else
				{
					_sljedeca_generacija[i][j] = false;
				}
			}
		}
	}
	
	for (unsigned i = 0; i < REDAKA; i++)
	{
		for (unsigned j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	for (unsigned i = 0; i < REDAKA; i++)
	{
		for (unsigned j = 0; j < STUPACA; j++)
		{
			if (celija_zauzeta(i, j) == false)
				cout << '-';
			else
				cout << '*';
		}
		cout << endl;
	}
}
