#include <windows.h> 
#include <iostream>  
#include "funkcie.h"

using namespace std;

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} 

	// funkcia na skrytie blikajúceho kurzora - z netu
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void drawpoint(int x, int y)
{
	gotoxy(x,y);cout<<char(219)<<char(219)<<char(219)<<char(219);
	gotoxy(x,y+1);cout<<char(219)<<char(219)<<char(219)<<char(219);
}

void erasepoint(int x, int y)
{
	gotoxy(x,y);cout<<"    ";
	gotoxy(x,y+1);cout<<"    ";
}

void screensize(int &columns, int &rows)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; 	
}

void welcomescreen(int x, int y)
{
	int a,b,zaciatokstlpec,zaciatokriadok;
	zaciatokstlpec=(int)x/2-54;
	zaciatokriadok=(int)y/2-6;
	
	gotoxy(zaciatokstlpec,zaciatokriadok-2);cout<<"C++ console...";
	gotoxy(zaciatokstlpec+81,zaciatokriadok+13);cout<<"Developed by Peter "<<char(230)<<"talmach";
	gotoxy(zaciatokstlpec+40,zaciatokriadok+20);cout<<"...stla"<<char(159)<<" [Enter] pre pokra"<<char(159)<<"ovanie...";
	
	// vykreslenie písmena T
	for (int o=0;o<2;o++)
	{
		gotoxy(zaciatokstlpec+o*42,zaciatokriadok);for(a=0;a<20;a++) cout<<char(219);
		gotoxy(zaciatokstlpec+o*42,zaciatokriadok+1);for(a=0;a<20;a++) cout<<char(219);
		for (b=0;b<10;b++)
		{
			gotoxy(zaciatokstlpec+8+o*42,zaciatokriadok+2+b);for(a=0;a<4;a++) cout<<char(219);
		}	
	}
	
	// vykreslenie písmena E
	for (b=0;b<12;b++)
	{
		gotoxy(zaciatokstlpec+24,zaciatokriadok+b);for(a=0;a<4;a++) cout<<char(219);
	}
	for (b=0;b<3;b++)
	{
		gotoxy(zaciatokstlpec+28,zaciatokriadok+b*5);for(a=0;a<10;a++) cout<<char(219);
		gotoxy(zaciatokstlpec+28,zaciatokriadok+b*5+1);for(a=0;a<10;a++) cout<<char(219);
	}
	
	// vykreslenie písmena R
	for (b=0;b<12;b++)
	{
		gotoxy(zaciatokstlpec+66,zaciatokriadok+b);for(a=0;a<4;a++) cout<<char(219);
	}
	for (b=0;b<2;b++)
	{
		gotoxy(zaciatokstlpec+70,zaciatokriadok+b*5);for(a=0;a<8;a++) cout<<char(219);
		gotoxy(zaciatokstlpec+70,zaciatokriadok+b*5+1);for(a=0;a<8;a++) cout<<char(219);
	}
	for (b=0;b<7;b++)
	{
		gotoxy(zaciatokstlpec+78,zaciatokriadok+b);for(a=0;a<4;a++) cout<<char(219);
	}
	for (b=0;b<3;b++)
	{
		gotoxy(zaciatokstlpec+70+b*4,zaciatokriadok+6+b*2);for(a=0;a<4;a++) cout<<char(219);
		gotoxy(zaciatokstlpec+70+b*4,zaciatokriadok+6+b*2+1);for(a=0;a<4;a++) cout<<char(219);
	}
	
	//  vykreslenie písmena I
	for (b=0;b<12;b++)
	{
		gotoxy(zaciatokstlpec+86,zaciatokriadok+b);for(a=0;a<4;a++) cout<<char(219);
	}
	
	//  vykreslenie písmena S
	for (b=0;b<7;b++)
	{
		gotoxy(zaciatokstlpec+94,zaciatokriadok+b);for(a=0;a<4;a++) cout<<char(219);
	}
	for (b=0;b<3;b++)
	{
		gotoxy(zaciatokstlpec+94,zaciatokriadok+b*5);for(a=0;a<14;a++) cout<<char(219);
		gotoxy(zaciatokstlpec+94,zaciatokriadok+b*5+1);for(a=0;a<14;a++) cout<<char(219);
	}
	for (b=0;b<7;b++)
	{
		gotoxy(zaciatokstlpec+104,zaciatokriadok+b+5);for(a=0;a<4;a++) cout<<char(219);
	}
}












    
