#include <windows.h> 
#include <iostream> 
#include "funkcie.h"
#include "game.h"

using namespace std;


int Game::mapa(int x, int y)
	{
		int mapaX,mapaY,menuX,menuY,sizeX,sizeY,posunX;
		mapaX=(int)(x/2)-33;
		mapaY=2;
		menuX=90;
		menuY=22;
		gotoxy(mapaX,mapaY); 
		cout<<char(201);
		for (sizeX=0;sizeX<68;sizeX++) {cout<<char(205);}	// vykreslenie obdåžnika ohranièujúceho hernú plochu
		cout<<char(187)<<endl;
		for (sizeY=0;sizeY<y-3;sizeY++)
		{
			for(posunX=0;posunX<mapaX-1;posunX++){cout<<" ";}
			cout<<" "<<char(186);
			for (sizeX=0;sizeX<68;sizeX++) {cout<<" ";}
			cout<<char(186)<<endl;
		}
		for(posunX=0;posunX<mapaX;posunX++){cout<<" ";}
		cout<<char(200);
		for (sizeX=0;sizeX<68;sizeX++) {cout<<char(205);}
		cout<<char(188);
		// vykreslenie nápovedy napravo od hernej plochy
		gotoxy(mapaX+menuX+3,mapaY+menuY);cout<<char(218)<<char(196)<<char(196)<<char(196)<<char(191);
		gotoxy(mapaX+menuX+3,mapaY+menuY+1);cout<<char(179)<<" "<<char(30)<<" "<<char(179);
		gotoxy(mapaX+menuX+3,mapaY+menuY+2);cout<<char(192)<<char(196)<<char(196)<<char(196)<<char(217);
		gotoxy(mapaX+menuX+4,mapaY+menuY+3);cout<<"Oto"<<char(159);
		
		gotoxy(mapaX+menuX+3,mapaY+menuY+5);cout<<char(218)<<char(196)<<char(196)<<char(196)<<char(191);
		gotoxy(mapaX+menuX+3,mapaY+menuY+6);cout<<char(179)<<" "<<char(31)<<" "<<char(179);
		gotoxy(mapaX+menuX+3,mapaY+menuY+7);cout<<char(192)<<char(196)<<char(196)<<char(196)<<char(217);
		gotoxy(mapaX+menuX+3,mapaY+menuY+8);cout<<"R"<<char(236)<<"chlo";
		gotoxy(mapaX+menuX+4,mapaY+menuY+9);cout<<"dole";
		
		gotoxy(mapaX+menuX-7,mapaY+menuY+5);cout<<char(218)<<char(196)<<char(196)<<char(196)<<char(191);
		gotoxy(mapaX+menuX-7,mapaY+menuY+6);cout<<char(179)<<" "<<char(17)<<" "<<char(179);
		gotoxy(mapaX+menuX-7,mapaY+menuY+7);cout<<char(192)<<char(196)<<char(196)<<char(196)<<char(217);
		gotoxy(mapaX+menuX-8,mapaY+menuY+8);cout<<"Do"<<char(150)<<"ava";
		
		gotoxy(mapaX+menuX+13,mapaY+menuY+5);cout<<char(218)<<char(196)<<char(196)<<char(196)<<char(191);
		gotoxy(mapaX+menuX+13,mapaY+menuY+6);cout<<char(179)<<" "<<char(16)<<" "<<char(179);
		gotoxy(mapaX+menuX+13,mapaY+menuY+7);cout<<char(192)<<char(196)<<char(196)<<char(196)<<char(217);
		gotoxy(mapaX+menuX+12,mapaY+menuY+8);cout<<"Doprava";	
		
		gotoxy(mapaX+menuX-7,mapaY+menuY+12);cout<<char(218)<<char(196)<<char(196)<<char(196)<<char(191);
		gotoxy(mapaX+menuX-7,mapaY+menuY+13);cout<<char(179)<<"ESC"<<char(179)<<" Ukon"<<char(159)<<"i"<<char(156)<<" hru";
		gotoxy(mapaX+menuX-7,mapaY+menuY+14);cout<<char(192)<<char(196)<<char(196)<<char(196)<<char(217);
		
		return sizeY;
	}
	
void Game::GameEnd(int x, int y, int body)
	{
		end=true;
		int mapaX,mapaY,sizeX,sizeY,sirka,vyska;
		mapaX=(int)(x/2)-20;
		mapaY=10;
		sirka=42;
		vyska=10;
		gotoxy(mapaX,mapaY); 
		cout<<char(201);
		for (sizeX=0;sizeX<sirka;sizeX++) {cout<<char(205);}
		cout<<char(187);
		for (sizeY=1;sizeY<vyska;sizeY++)
		{
			gotoxy(mapaX,mapaY+sizeY);cout<<char(186);
			for (int a=0;a<sirka;a++) {cout<<" ";}
			gotoxy(mapaX+sizeX+1,mapaY+sizeY);cout<<char(186);
		}
		gotoxy(mapaX,mapaY+vyska); 
		cout<<char(200);
		for (sizeX=0;sizeX<sirka;sizeX++) {cout<<char(205);}
		cout<<char(188);
		gotoxy(mapaX+17,mapaY+3);cout<<"KONIEC HRY";
		gotoxy(mapaX+10,mapaY+5);cout<<"Po"<<char(159)<<"et z"<<char(161)<<"skan"<<char(236)<<"ch bodov: "<<body;
		gotoxy(mapaX+4,mapaY+vyska-1);cout<<"...stla"<<char(159)<<" [Enter] pre vypnutie hry...";
	}
Game::Game(int a, int b)
	{
		row.resize(70,0);	// nastavenie jednorozmerného vector pola row na 70 buniek a nastevenie všetkých buniek na nulu/ nula znaèí neobsadenú bunku 
		pole.resize(b-1,row);	// vytvorenie dvojrozmerného vector pola s názvom pole, pomocou pola row/ toto pole vytvara neviditelnu hranicu pre hernu plochu
		for (int i=0;i<70;i++)	// nastavenie buniek v hornom a dolnom riadku na 1
		{
			pole[0][i]=1;
			pole[b-2][i]=1;
		}
		for (int j=1;j<b-2;j++)	// nastavenie buniek v prvom a poslednom stlpci pola na 1
		{
			pole[j][0]=1;
			pole[j][69]=1;
		}
		end=false;	
		mapaX=(int)(a/2)-33;	// nastavenie X-ovej suradnice pre zaciatok hernej plochy 
		mapaY=1;				// nastavenie Y-ovej suradnice pre zaciatok hernej plochy 
		mapa(a,b);
		gotoxy(mapaX+70,mapaY+2);
		cout<<" Nasleduj"<<char(163)<<"ci tvar";
		gotoxy(mapaX-12,mapaY+2);
		cout<<"Body:";
		firstshape=(int)rand() % 5+1;
		score=0;
	}
int Game::NextShape(int before)
	{
		int shape;
		bool correct;
		while (correct!=true)
		{
			shape = (int)rand() % 5+1;
			if (shape!=before) {correct=true;}
			else correct=false;	
		}
		return shape;		
	}
void Game::vypispole( int x, int a, int b)
{
	gotoxy(a,b);
	for (int i=0;i<x-1;i++)
	{
		for (int j=0;j<70;j++)
		{
			cout<<pole[i][j];
		}
		cout<<endl;
	}
}

bool Game::checkdown(int x, int y, int tvar, int rot)
{
	bool check=false;
	int stick;
	
	switch (tvar)
	{
		case 1:
		{
			for (int i=0; i<8; i++)
			{
				if (pole[x+4][y+i]==1) {check=true;break;}
				else check=false;
			}
			break;
		}
		case 2:
		{
			switch(rot)
			{
				case 1:
				{
					for (int i=1; i<5; i++)
					{		
						if ((pole[x+2][y-i] or pole[x+4][y+i-1] or pole[x+2][y+i+3])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 2:
				{
					for (int i=1; i<5; i++)
					{		
						if ((pole[x+2][y-i] or pole[x+4][y+i-1])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 3:
				{
					for (int i=0; i<12; i++)
					{		
						if (pole[x+2][y+i-4]==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 4:
				{
					for (int i=1; i<5; i++)
					{		
						if ((pole[x+4][y+i-1] or pole[x+2][y+i+3])==1) {check=true;break;}
						else check=false;
					}
					break;
				}	
			}
				
			break;
		}
		case 3:
		{
			switch(rot)
			{
				case 1:
				{
					for (int i=1; i<5; i++)
					{		
						if ((pole[x+2][y-i] or pole[x+6][y+i-1])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 2:
				{
					for (int i=1; i<13; i++)
					{		
						if ((pole[x+2][y+4-i])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 3:
				{
					for (int i=0; i<8; i++)
					{		
						if (pole[x+2][y+i]==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 4:
				{
					for (int i=0; i<4; i++)
					{		
						if ((pole[x+4][y+i] or pole[x+2][y+i+4] or pole[x+2][y+i+8])==1) {check=true;break;}
						else check=false;
					}
					break;
				}	
			}	
			break;
		}
		case 4:
		{
			switch(rot)
			{
				case 1:
				{
					for (int i=1; i<5; i++)
					{		
						if ((pole[x+2][y-i] or pole[x+4][y+i-1])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 2:
				{
					for (int i=0; i<8; i++)
					{		
						if ((pole[x+2][y+i-4])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 3:
				{
					for (int i=0; i<8; i++)
					{		
						if (pole[x+2][y+i]==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 4:
				{
					for (int i=0; i<4; i++)
					{		
						if ((pole[x+4][y+i] or pole[x+2][y+i+4])==1) {check=true;break;}
						else check=false;
					}
					break;
				}	
			}		
			break;
		}
		case 5:
		{
			if (rot==2 or rot==4) stick=1;
			if (rot==1 or rot==3) stick=2;
			switch(stick)
			{
				case 1:
				{
					for (int i=0; i<20; i++)
					{		
						if ((pole[x+2][y+i-8])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 2:
				{
					for (int i=0; i<4; i++)
					{		
						if ((pole[x+6][y+i])==1) {check=true;break;}
						else check=false;
					}
					break;
				}	
			}		
			break;
		}
	}
	return check;
}

bool Game::checkleft(int x, int y, int tvar, int rot)
{
	bool check=false;
	int stick;
	
	switch (tvar)
	{
		case 1:
		{
			for (int i=0; i<4; i++)
			{
				if (pole[x+i][y-1]==1) {check=true;break;}
				else check=false;
			}
			break;
		}
		case 2:
		{
			switch(rot)
			{
				case 1:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x+i][y-5] or pole[x+3][y-1])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 2:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x-i-1][y-1] or pole[x+i][y-5] or pole[x+3][y-1])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 3:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x-i-1][y-1] or pole[x+i][y-5])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 4:
				{
					for (int i=0; i<6; i++)
					{		
						if (pole[x+i-2][y-1]==1) {check=true;break;}
						else check=false;
					}
					break;
				}	
			}	
			break;
		}
		case 3:
		{
			switch(rot)
			{
				case 1:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x+i][y-5] or pole[x+i+3][y-1] or pole[x+5][y-1])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 2:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x-i][y-9] or pole[x-i-1][y-1])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 3:
				{
					for (int i=0; i<6; i++)
					{		
						if ((pole[x+i-4][y-1])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 4:
				{
					for (int i=0; i<4; i++)
					{		
						if (pole[x+i][y-1]==1) {check=true;break;}
						else check=false;
					}
					break;
				}	
			}		
			break;
		}
		case 4:
		{
			switch(rot)
			{
				case 1:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x+i][y-5] or pole[x+3][y-1])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 2:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x+i][y-5] or pole[x-i-1][y-1])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 3:
				{
					for (int i=0; i<4; i++)
					{		
						if ((pole[x+i-2][y-1])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 4:
				{
					for (int i=0; i<4; i++)
					{		
						if (pole[x+i][y-1]==1) {check=true;break;}
						else check=false;
					}
					break;
				}	
			}			
			break;
		}
		case 5:
		{
			if (rot==2 or rot==4) stick=1;
			if (rot==1 or rot==3) stick=2;
			switch(stick)
			{
				case 1:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x+i][y-9])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 2:
				{
					for (int i=0; i<10; i++)
					{		
						if ((pole[x+i-4][y-1])==1) {check=true;break;}
						else check=false;
					}
					break;
				}	
			}			
			break;
		}
	}
	return check;
}

bool Game::checkright(int x, int y, int tvar, int rot)
{
	bool check=false;
	int stick;
	
	switch (tvar)
	{
		case 1:
		{
			for (int i=0; i<4; i++)
			{
				if (pole[x+i][y+8]==1) {check=true;break;}
				else check=false;
			}
			break;
		}
		case 2:
		{
			switch(rot)
			{
				case 1:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x+i][y+8] or pole[x+3][y+4])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 2:
				{
					for (int i=0; i<6; i++)
					{		
						if (pole[x+i-2][y+4]==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 3:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x-1-i][y+4] or pole[x+i][y+8])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 4:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x-1-i][y+4] or pole[x+i][y+8] or pole[x+3][y+4])==1) {check=true;break;}
						else check=false;
					}
					break;
				}	
			}		
			break;
		}
		case 3:
		{
			switch(rot)
			{
				case 1:
				{
					for (int i=0; i<6; i++)
					{		
						if ((pole[x+i][y+4])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 2:
				{
					for (int i=0; i<4; i++)
					{		
						if (pole[x+i-2][y+4]==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 3:
				{
					for (int i=1; i<5; i++)
					{		
						if ((pole[x-i][y+4] or pole[x][y+8] or pole[x+1][y+8])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 4:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x+i][y+12] or pole[x+3][y+4])==1) {check=true;break;}
						else check=false;
					}
					break;
				}	
			}			
			break;
		}
		case 4:
		{
			switch(rot)
			{
				case 1:
				{
					for (int i=0; i<4; i++)
					{		
						if ((pole[x+i][y+4])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 2:
				{
					for (int i=0; i<4; i++)
					{		
						if (pole[x+i-2][y+4]==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 3:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x-i-1][y+4] or pole[x][y+8])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 4:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x+i][y+8] or pole[x+3][y+4])==1) {check=true;break;}
						else check=false;
					}
					break;
				}	
			}		
			break;
		}
		case 5:
		{
			if (rot==2 or rot==4) stick=1;
			if (rot==1 or rot==3) stick=2;
			switch(stick)
			{
				case 1:
				{
					for (int i=0; i<2; i++)
					{		
						if ((pole[x+i][y+12])==1) {check=true;break;}
						else check=false;
					}
					break;
				}
				case 2:
				{
					for (int i=0; i<10; i++)
					{		
						if ((pole[x+i-4][y+4])==1) {check=true;break;}
						else check=false;
					}
					break;
				}	
			}				
			break;
		}
	}
	return check;
}

void Game::zapisdopola(int x, int y, int tvar, int rot)
{
	bool check=false;
	int stick;
	
	switch (tvar)
	{
		case 1:
		{
			for (int i=x;i<x+4;i++)
			{
				for (int j=y;j<y+8;j++)
				{
					pole[i][j]=1;
				}
			}
			break;
		}
		case 2:
		{
			switch (rot)
			{
				case 1:
				{
					for (int i=x;i<x+2;i++)
					{		
						for (int j=y-4;j<y+8;j++)
						{
							pole[i][j]=1;
						}
					}
					for (int i=x+2;i<x+4;i++)
					{		
						for (int j=y;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}
				case 2:
				{
					for (int i=x-2;i<x+4;i++)
					{		
						for (int j=y;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					for (int i=x;i<x+2;i++)
					{		
						for (int j=y-4;j<y;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}	
				case 3:
				{
					for (int i=x-2;i<x;i++)
					{		
						for (int j=y;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					for (int i=x;i<x+2;i++)
					{		
						for (int j=y-4;j<y+8;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}	
				case 4:
				{
					for (int i=x-2;i<x+4;i++)
					{		
						for (int j=y;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					for (int i=x;i<x+2;i++)
					{		
						for (int j=y+4;j<y+8;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}		
			}	
			break;
		}
		case 3:
		{
			switch (rot)
			{
				case 1:
				{
					for (int i=x;i<x+6;i++)
					{		
						for (int j=y;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					for (int i=x;i<x+2;i++)
					{		
						for (int j=y-4;j<y;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}
				case 2:
				{
					for (int i=x-2;i<x;i++)
					{		
						for (int j=y;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					for (int i=x;i<x+2;i++)
					{		
						for (int j=y-8;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}	
				case 3:
				{
					for (int i=x-4;i<x+2;i++)
					{		
						for (int j=y;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					for (int i=x;i<x+2;i++)
					{		
						for (int j=y+4;j<y+8;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}	
				case 4:
				{
					for (int i=x;i<x+2;i++)
					{		
						for (int j=y;j<y+12;j++)
						{
							pole[i][j]=1;
						}
					}
					for (int i=x+2;i<x+4;i++)
					{		
						for (int j=y;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}		
			}	
			break;
		}
		case 4:
		{
			switch (rot)
			{
				case 1:
				{
					for (int i=x;i<x+4;i++)
					{		
						for (int j=y;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					for (int i=x;i<x+2;i++)
					{		
						for (int j=y-4;j<y;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}
				case 2:
				{
					for (int i=x-2;i<x;i++)
					{		
						for (int j=y;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					for (int i=x;i<x+2;i++)
					{		
						for (int j=y-4;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}	
				case 3:
				{
					for (int i=x-2;i<x+2;i++)
					{		
						for (int j=y;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					for (int i=x;i<x+2;i++)
					{		
						for (int j=y+4;j<y+8;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}	
				case 4:
				{
					for (int i=x;i<x+2;i++)
					{		
						for (int j=y;j<y+8;j++)
						{
							pole[i][j]=1;
						}
					}
					for (int i=x+2;i<x+4;i++)
					{		
						for (int j=y;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}		
			}	
			break;
		}
		case 5:
		{
			if (rot==2 or rot==4) stick=1;
			if (rot==1 or rot==3) stick=2;
			switch (stick)
			{
				case 1:
				{
					for (int i=x;i<x+2;i++)
					{		
						for (int j=y-8;j<y+12;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}
				case 2:
				{
					for (int i=x-4;i<x+6;i++)
					{		
						for (int j=y;j<y+4;j++)
						{
							pole[i][j]=1;
						}
					}
					break;
				}			
			}	
			break;
		}
	}
}
int Game::otoc(int x, int y, int tvar, int rot, int shapeX, int shapeY, int rows, int columns)
{
	int natoc;
	int stick;
	
	switch (tvar)
	{
		case 1:
		{
			natoc=1;
			break;
		}
		case 2:
		{
			switch (rot)
			{
				case 1:
				{
					if (x<3) natoc=1;
					else
					{
						if ((pole[x-1][y] or pole[x-1][y+1] or pole[x-1][y+2] or pole[x-1][y+3])==1) natoc=1;
						else
						{
							natoc=2;
							erasepoint(shapeX+4,shapeY);
							drawpoint(shapeX,shapeY-2);	
						}	
					}
					break;
				}
				case 2:
				{
					if ((pole[x][y+4] or pole[x+1][y+4])==1) natoc=2;
					else 
					{
						natoc=3;
						erasepoint(shapeX,shapeY+2);
						drawpoint(shapeX+4,shapeY);
					}
						
					break;
				}	
				case 3:
				{
					if ((pole[x+2][y] or pole[x+2][y+1] or pole[x+2][y+2] or pole[x+2][y+3])==1) natoc=3;
					else 
					{
						natoc=4;
						erasepoint(shapeX-4,shapeY);
						drawpoint(shapeX,shapeY+2);	
					}
					
					break;
				}	
				case 4:
				{
					if ((pole[x][y-1] or pole[x+1][y-1])==1) natoc=4;
					else 
					{
						natoc=1;
						erasepoint(shapeX,shapeY-2);
						drawpoint(shapeX-4,shapeY);
					}
					
					break;
				}		
			}	
			break;
		}
		case 3:
		{
			switch (rot)
			{
				case 1:
				{
					if (y<8 or x<3) natoc=1;
					else 
					{
						if ((pole[x][y-8] or pole[x+1][y-8] or pole[x][y-4] or pole[x+1][y-4])==1) natoc=1;
						else
						{
							natoc=2;
							erasepoint(shapeX,shapeY+2);
							erasepoint(shapeX,shapeY+4);
							drawpoint(shapeX-8,shapeY);
							drawpoint(shapeX,shapeY-2);	
						} 	
					}	
					break;
				}
				case 2:
				{
					if (x<4) natoc=2;
					else
					{
						if ((pole[x-2][y+4] or pole[x-1][y+4] or pole[x][y+4] or pole[x+1][y+4] or pole[x-4][y])==1) natoc=2;
						else 
						{
							natoc=3;
							erasepoint(shapeX-8,shapeY);
							erasepoint(shapeX-4,shapeY);
							drawpoint(shapeX+4,shapeY);
							drawpoint(shapeX,shapeY-4);
						}	
					}	
					break;
				}	
				case 3:
				{
					if (y>57 or x>rows-2) natoc=3;
					else
					{
						if ((pole[x][y+4] or pole[x+1][y+4] or pole[x][y+8] or pole[x+1][y+8] or pole[x+2][y])==1) natoc=3;
						else 
						{
							natoc=4;
							erasepoint(shapeX,shapeY-4);
							erasepoint(shapeX,shapeY-2);
							drawpoint(shapeX+8,shapeY);
							drawpoint(shapeX,shapeY+2);	
						}	
					}	
					break;
				}	
				case 4:
				{
					if (y<2 or x>rows-9) natoc=4;
					else
					{
						if ((pole[x][y+4] or pole[x+1][y+4] or pole[x][y-1] or pole[x+1][y-1])==1) natoc=4;
						else 
						{
							natoc=1;
							erasepoint(shapeX+4,shapeY);
							erasepoint(shapeX+8,shapeY);
							drawpoint(shapeX,shapeY+4);
							drawpoint(shapeX-4,shapeY);
						}	
					}	
					break;
				}		
			}	
			break;
		}
		case 4:
		{
			switch (rot)
			{
				case 1:
				{
					if (x<3) natoc=1;
					else 
					{
						if ((pole[x+3][y-4] or pole[x+3][y-3] or pole[x+3][y-2] or pole[x+3][y-1])==1) natoc=1;
						else
						{
							natoc=2;
							erasepoint(shapeX,shapeY+2);
							drawpoint(shapeX,shapeY-2);	
						} 	
					}	
					break;
				}
				case 2:
				{
						if ((pole[x-2][y+4] or pole[x-1][y+4] or pole[x][y+4] or pole[x+1][y+4])==1) natoc=2;
						else 
						{
							natoc=3;
							erasepoint(shapeX-4,shapeY);
							drawpoint(shapeX+4,shapeY);
						}	
					break;
				}	
				case 3:
				{
					if (x>rows-2) natoc=3;
					else
					{
						if ((pole[x+3][y] or pole[x+3][y+1] or pole[x+3][y+2] or pole[x+3][y+3])==1) natoc=3;
						else 
						{
							natoc=4;
							erasepoint(shapeX,shapeY-2);
							drawpoint(shapeX,shapeY+2);	
						}	
					}	
					break;
				}	
				case 4:
				{
						if ((pole[x][y-1] or pole[x+1][y-1])==1) natoc=4;
						else 
						{
							natoc=1;
							erasepoint(shapeX+4,shapeY);
							drawpoint(shapeX-4,shapeY);
						}		
					break;
				}		
			}	
			break;
		}
		case 5:
		{
			if (rot==2 or rot==4) stick=1;
			if (rot==1 or rot==3) stick=2;
			switch (stick)
			{
				case 1:
				{
					if (x<5 or x>rows-9) natoc=2;
					else 
					{
						if ((pole[x-4][y] or pole[x-2][y] or pole[x+2][y] or pole[x+4][y])==1) natoc=1;
						else
						{
							natoc=1;
							erasepoint(shapeX-8,shapeY);
							erasepoint(shapeX-4,shapeY);
							erasepoint(shapeX+4,shapeY);
							erasepoint(shapeX+8,shapeY);
							drawpoint(shapeX,shapeY-4);
							drawpoint(shapeX,shapeY-2);
							drawpoint(shapeX,shapeY+2);
							drawpoint(shapeX,shapeY+4);
								
						} 	
					}	
					break;
				}
				case 2:
				{
					if (y<8 or y>57) natoc=1;
					else
					{
						if ((pole[x][y-8] or pole[x+1][y-8] or pole[x][y-4] or pole[x+1][y-4] or pole[x][y+4] or pole[x+1][y+4] or pole[x][y+8] or pole[x+1][y+8])==1) natoc=1;
						else 
						{
							natoc=2;
							erasepoint(shapeX,shapeY-4);
							erasepoint(shapeX,shapeY-2);
							erasepoint(shapeX,shapeY+2);
							erasepoint(shapeX,shapeY+4);
							drawpoint(shapeX-8,shapeY);
							drawpoint(shapeX-4,shapeY);
							drawpoint(shapeX+4,shapeY);
							drawpoint(shapeX+8,shapeY);
						}	
					}	
					break;
				}		
			}	
			break;
		}
	}
	return natoc;
}
bool Game::checkend()
{
	bool finish;
	
	for (int i=1;i<69;i++)
	{
		if(pole[2][i]==1) 
		{
			finish=true;
			break;	
		}
		else finish=false;
	}
	return finish;
}
void Game::checkline(int rows)
{
	int pocitadlobodov=0;
	int counter=0;
	for (int i=1;i<rows-2;i++)
	{
		for (int j=1;j<69;j++)
		{
			if (pole[i][j]==1) counter++;
		}
		if (counter==68)
		{
			for (int j=1;j<69;j++)
			{
				pole[i][j]=0;	
			}
			pocitadlobodov++;
			if (pocitadlobodov==2)
			{
				score++;
				pocitadlobodov=0;
			}
			for (int r=i-1;r>1;r--)
			{
				for (int j=1;j<69;j++)
				{
					if (pole[r][j]==1)
					{
						pole[r+1][j]=1;
						pole[r][j]=0;
					}
				}
			}
		} 
		counter=0;
	}
}
void Game::drawfromfield(int rows,int columns)
{
	for (int i=1;i<rows-2;i++)
	{
		for (int j=1;j<69;j++)
		{
			if (pole[i][j]==0)
			{
				gotoxy(((int)columns/2-33+j),i+2);
				cout<<" ";
			} 
			if (pole[i][j]==1)
			{
				gotoxy(((int)columns/2-33+j),i+2);
				cout<<char(219);
			}
		}
	}
}











