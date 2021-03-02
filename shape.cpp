#include <windows.h> 
#include <iostream> 
#include "funkcie.h"
#include "shape.h"

using namespace std;



void Shape::drawcube(int x, int y)
	{
		drawpoint(x,y);
		drawpoint(x+4,y);
		drawpoint(x,y+2);
		drawpoint(x+4,y+2);
	}
void Shape::erasecube(int x, int y)
	{
		erasepoint(x,y);
		erasepoint(x+4,y);
		erasepoint(x,y+2);
		erasepoint(x+4,y+2);
		
	}
void Shape::drawhalfplus(int x, int y, int rot)
	{
		drawpoint(x,y);
		if (rot==1){;} else {drawpoint(x,y-2);}
		if (rot==4){;} else {drawpoint(x-4,y);}
		if (rot==2){;} else {drawpoint(x+4,y);}
		if (rot==3){;} else {drawpoint(x,y+2);}
	}
void Shape::erasehalfplus(int x, int y, int rot)
	{
		erasepoint(x,y);
		if (rot==1){;} else {erasepoint(x,y-2);}
		if (rot==4){;} else {erasepoint(x-4,y);}
		if (rot==2){;} else {erasepoint(x+4,y);}
		if (rot==3){;} else {erasepoint(x,y+2);}
	}
void Shape::drawbigL(int x, int y, int rot)
	{
		drawpoint(x,y);
		if (rot==1) {drawpoint(x-4,y);drawpoint(x,y+2);drawpoint(x,y+4);}
		if (rot==2) {drawpoint(x-8,y);drawpoint(x-4,y);drawpoint(x,y-2);}
		if (rot==3) {drawpoint(x,y-4);drawpoint(x,y-2);drawpoint(x+4,y);}
		if (rot==4) {drawpoint(x,y+2);drawpoint(x+4,y);drawpoint(x+8,y);}
	}	
void Shape::erasebigL(int x, int y, int rot)
	{
		erasepoint(x,y);
		if (rot==1) {erasepoint(x-4,y);erasepoint(x,y+2);erasepoint(x,y+4);}
		if (rot==2) {erasepoint(x-8,y);erasepoint(x-4,y);erasepoint(x,y-2);}
		if (rot==3) {erasepoint(x,y-4);erasepoint(x,y-2);erasepoint(x+4,y);}
		if (rot==4) {erasepoint(x,y+2);erasepoint(x+4,y);erasepoint(x+8,y);}
	}
void Shape::drawsmallL(int x, int y, int rot)
	{
		drawpoint(x,y);
		if (rot==1) {drawpoint(x-4,y);drawpoint(x,y+2);}
		if (rot==2) {drawpoint(x-4,y);drawpoint(x,y-2);}
		if (rot==3) {drawpoint(x,y-2);drawpoint(x+4,y);}
		if (rot==4) {drawpoint(x,y+2);drawpoint(x+4,y);}
	}	
void Shape::erasesmallL(int x, int y, int rot)
	{
		erasepoint(x,y);
		if (rot==1) {erasepoint(x-4,y);erasepoint(x,y+2);}
		if (rot==2) {erasepoint(x-4,y);erasepoint(x,y-2);}
		if (rot==3) {erasepoint(x,y-2);erasepoint(x+4,y);}
		if (rot==4) {erasepoint(x,y+2);erasepoint(x+4,y);}
	}
void Shape::drawstick(int x, int y, int rot)
	{
		drawpoint(x,y);
		if (rot==1 or rot==3) {drawpoint(x,y-4);drawpoint(x,y-2);drawpoint(x,y+2);drawpoint(x,y+4);}
		if (rot==2 or rot==4) {drawpoint(x-8,y);drawpoint(x-4,y);drawpoint(x+4,y);drawpoint(x+8,y);}
	}	
void Shape::erasestick(int x, int y, int rot)
	{
		erasepoint(x,y);
		if (rot==1 or rot==3) {erasepoint(x,y-4);erasepoint(x,y-2);erasepoint(x,y+2);erasepoint(x,y+4);}
		if (rot==2 or rot==4) {erasepoint(x-8,y);erasepoint(x-4,y);erasepoint(x+4,y);erasepoint(x+8,y);}
	}
Shape::Shape(int x, int y, int t, int rot)
	{
		polohaX=x;
		polohaY=y;
		tvar=t;
		natoc=rot;
		switch (tvar)
		{
			case 1:
			{
				drawcube(polohaX,polohaY);
				break;
			}
			case 2:
			{
				drawhalfplus(polohaX,polohaY,natoc);
				break;
			}
			case 3:
			{
				drawbigL(polohaX,polohaY,natoc);
				break;
			}
			case 4:
			{
				drawsmallL(polohaX,polohaY,natoc);
				break;
			}
			case 5:
			{
				drawstick(polohaX,polohaY,natoc);
				break;
			}
		}
	}
void Shape::godown(int tvar, int rot)
	{
		switch (tvar)
		{
			case 1:
			{
				erasecube(polohaX,polohaY);
				polohaY++;
				polohapoleriadok++;
				drawcube(polohaX,polohaY);
				break;
			}
			case 2:
			{
				erasehalfplus(polohaX,polohaY,rot);
				polohaY++;
				polohapoleriadok++;
				drawhalfplus(polohaX,polohaY,rot);
				break;
			}
			case 3:
			{
				erasebigL(polohaX,polohaY,rot);
				polohaY++;
				polohapoleriadok++;
				drawbigL(polohaX,polohaY,rot);
				break;
			}
			case 4:
			{
				erasesmallL(polohaX,polohaY,rot);
				polohaY++;
				polohapoleriadok++;
				drawsmallL(polohaX,polohaY,rot);
				break;
			}
			case 5:
			{
				erasestick(polohaX,polohaY,rot);
				polohaY++;
				polohapoleriadok++;
				drawstick(polohaX,polohaY,rot);
				break;
			}
		}
	}
	
void Shape::goleft(int tvar, int rot)
	{
		switch (tvar)
		{
			case 1:
			{
				erasecube(polohaX,polohaY);
				polohaX=polohaX-4;
				polohapolestlpec=polohapolestlpec-4;
				drawcube(polohaX,polohaY);
				break;
			}
			case 2:
			{
				erasehalfplus(polohaX,polohaY,rot);
				polohaX=polohaX-4;
				polohapolestlpec=polohapolestlpec-4;
				drawhalfplus(polohaX,polohaY,rot);
				break;
			}
			case 3:
			{
				erasebigL(polohaX,polohaY,rot);
				polohaX=polohaX-4;
				polohapolestlpec=polohapolestlpec-4;
				drawbigL(polohaX,polohaY,rot);
				break;
			}
			case 4:
			{
				erasesmallL(polohaX,polohaY,rot);
				polohaX=polohaX-4;
				polohapolestlpec=polohapolestlpec-4;
				drawsmallL(polohaX,polohaY,rot);
				break;
			}
			case 5:
			{
				erasestick(polohaX,polohaY,rot);
				polohaX=polohaX-4;
				polohapolestlpec=polohapolestlpec-4;
				drawstick(polohaX,polohaY,rot);
				break;
			}
		}
	}
	
void Shape::goright(int tvar, int rot)
	{
		switch (tvar)
		{
			case 1:
			{
				erasecube(polohaX,polohaY);
				polohaX=polohaX+4;
				polohapolestlpec=polohapolestlpec+4;
				drawcube(polohaX,polohaY);
				break;
			}
			case 2:
			{
				erasehalfplus(polohaX,polohaY,rot);
				polohaX=polohaX+4;
				polohapolestlpec=polohapolestlpec+4;
				drawhalfplus(polohaX,polohaY,rot);
				break;
			}
			case 3:
			{
				erasebigL(polohaX,polohaY,rot);
				polohaX=polohaX+4;
				polohapolestlpec=polohapolestlpec+4;
				drawbigL(polohaX,polohaY,rot);
				break;
			}
			case 4:
			{
				erasesmallL(polohaX,polohaY,rot);
				polohaX=polohaX+4;
				polohapolestlpec=polohapolestlpec+4;
				drawsmallL(polohaX,polohaY,rot);
				break;
			}
			case 5:
			{
				erasestick(polohaX,polohaY,rot);
				polohaX=polohaX+4;
				polohapolestlpec=polohapolestlpec+4;
				drawstick(polohaX,polohaY,rot);
				break;
			}
		}
	}
void Shape::drawnextshape(int x, int y,int t, int rot)
{
		for (int i=-4;i<8;i++)
		{
			for (int j=-4;j<6;j++)
			{
				erasepoint(x+i,y+j);
			}
		}
		switch (t)
		{
			case 1:
			{
				drawcube(x,y);
				break;
			}
			case 2:
			{
				drawhalfplus(x,y,rot);
				break;
			}
			case 3:
			{
				drawbigL(x,y,rot);
				break;
			}
			case 4:
			{
				drawsmallL(x,y,rot);
				break;
			}
			case 5:
			{
				drawstick(x,y,rot);
				break;
			}
		}
}

void Shape::eraseshape(int t, int rot)
{
		switch (t)
		{
			case 1:
			{
				erasecube(polohaX,polohaY);
				break;
			}
			case 2:
			{
				erasehalfplus(polohaX,polohaY,rot);
				break;
			}
			case 3:
			{
				erasebigL(polohaX,polohaY,rot);
				break;
			}
			case 4:
			{
				erasesmallL(polohaX,polohaY,rot);
				break;
			}
			case 5:
			{
				erasestick(polohaX,polohaY,rot);
				break;
			}
		}
}
