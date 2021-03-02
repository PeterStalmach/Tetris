#include "includelib.h"

using namespace std;

int main(int argc, char** argv) {
	int rychlosthry=10; // rychlost hry: 0 - najnizsia rychlost, 19 - najvyzsia rychlost
	int vysledok;
 	vysledok = 200000-rychlosthry*10000;
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);	
	ShowConsoleCursor(false);	// skrytie kurzora
    screensize(columns,rows);
    srand (time(NULL));  
	welcomescreen(columns,rows);
	getchar();
	system("cls");  
	Game MyGame(columns, rows);
	vector<Shape>MyShape;
	gotoxy(MyGame.mapaX-6,MyGame.mapaY+2);
	cout<<MyGame.score;
	akytvar=MyGame.NextShape(MyGame.firstshape);
 	if (akytvar==3) natocenie=4;
 	if (akytvar==5) natocenie=2;
 	if (akytvar==1 or akytvar==2 or akytvar==4) natocenie=1;
	MyShape.push_back(Shape((int)columns/2,3,akytvar,natocenie));
	MyShape[0].polohapoleriadok=1;
	MyShape[0].polohapolestlpec=33;
	counterloop=0;
	nasledujucitvar=MyGame.NextShape(akytvar);
	MyShape[0].drawnextshape((int)columns/2+45,8,nasledujucitvar,1);
	
	while(MyGame.end!=true){	//hlavna slucka hry
	counterloop++;
	if (counterloop==vysledok)
	{
		MyShape[0].godown(akytvar,natocenie);
		if (MyGame.checkdown(MyShape[0].polohapoleriadok,MyShape[0].polohapolestlpec,akytvar,natocenie)==true)
		{
			MyGame.zapisdopola(MyShape[0].polohapoleriadok,MyShape[0].polohapolestlpec,akytvar,natocenie);
			MyShape[0].eraseshape(akytvar,natocenie);
			MyShape.pop_back();
			if (MyGame.checkend()==true) {MyGame.GameEnd(columns, rows,MyGame.score);getchar();}
			MyGame.checkline(rows);
			MyGame.drawfromfield(rows,columns);
			gotoxy(MyGame.mapaX-6,MyGame.mapaY+2);
			cout<<MyGame.score;
			akytvar=nasledujucitvar;
			nasledujucitvar=MyGame.NextShape(akytvar);
			MyShape[0].drawnextshape((int)columns/2+45,8,nasledujucitvar,1);
 			if (akytvar==3) natocenie=4;
 			if (akytvar==5) natocenie=2;
 			if (akytvar==1 or akytvar==2 or akytvar==4) natocenie=1;
			MyShape.push_back(Shape((int)columns/2,3,akytvar,natocenie));
			MyShape[0].polohapoleriadok=1;
			MyShape[0].polohapolestlpec=33;
		}
		counterloop=0;
	}
	if (GetAsyncKeyState(VK_LEFT) & (0x8000 != 0))
	{
		if(MyGame.checkleft(MyShape[0].polohapoleriadok,MyShape[0].polohapolestlpec,akytvar,natocenie)==false) MyShape[0].goleft(akytvar,natocenie);
	}
	if (GetAsyncKeyState(VK_RIGHT) & (0x8000 != 0))
	{
		if(MyGame.checkright(MyShape[0].polohapoleriadok,MyShape[0].polohapolestlpec,akytvar,natocenie)==false) MyShape[0].goright(akytvar,natocenie);
	}
	if (GetAsyncKeyState(VK_UP) & (0x8000 != 0))
	{
		natocenie=MyGame.otoc(MyShape[0].polohapoleriadok,MyShape[0].polohapolestlpec,akytvar,natocenie,MyShape[0].polohaX,MyShape[0].polohaY,rows,columns);
	}
	if (GetAsyncKeyState(VK_DOWN) & (0x8000 != 0))
	{
		MyShape[0].godown(akytvar,natocenie);
		if (MyGame.checkdown(MyShape[0].polohapoleriadok,MyShape[0].polohapolestlpec,akytvar,natocenie)==true)
		{
			MyGame.zapisdopola(MyShape[0].polohapoleriadok,MyShape[0].polohapolestlpec,akytvar,natocenie);
			MyShape[0].eraseshape(akytvar,natocenie);
			MyShape.pop_back();
			if (MyGame.checkend()==true) {MyGame.GameEnd(columns, rows,MyGame.score);getchar();} 
			MyGame.checkline(rows);
			MyGame.drawfromfield(rows,columns);
			gotoxy(MyGame.mapaX-6,MyGame.mapaY+2);
			cout<<MyGame.score;
			akytvar=nasledujucitvar;
			nasledujucitvar=MyGame.NextShape(akytvar);
			MyShape[0].drawnextshape((int)columns/2+45,8,nasledujucitvar,1);
 			if (akytvar==3) natocenie=4;
 			if (akytvar==5) natocenie=2;
 			if (akytvar==1 or akytvar==2 or akytvar==4) natocenie=1;
			MyShape.push_back(Shape((int)columns/2,3,akytvar,natocenie));
			MyShape[0].polohapoleriadok=1;
			MyShape[0].polohapolestlpec=33;
		}
	}
	if (GetAsyncKeyState(VK_ESCAPE) & (0x8000 != 0)){MyGame.GameEnd(columns, rows,MyGame.score);getchar();}  
	}
	return 0;
}
