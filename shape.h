#ifndef shape_h
#define shape_h

class Shape
{
	public:
	int polohaX, polohaY, tvar,natoc,polohapoleriadok,polohapolestlpec;
	// premenné polohaX a polohaY uchovávajú súradnice polohy tvaru vzh¾adom na hernú mapu/obrazovka/konzola
	// premenné polohariadok a polohastlpec uchovávajú súradnice polohy tvaru vzh¾adom na vector pole s názvom pole/toto pole uchováva polohy už dopadnutých predchádzajúcich tvarov
	// premenná natoc uchováva aktuálne natocenie tvaru - tvar sa otaca v smere hodinovych ruciciek vzdy o 90stupnov/ toto predstavujú hodnoty 1,2,3,4
	void drawcube(int x, int y);	// vykreslenie kocky so zadaním súradníc prvého bodu
	void erasecube(int x, int y);
	void drawhalfplus(int x, int y, int rot);
	void erasehalfplus(int x, int y, int rot);
	void drawbigL(int x, int y, int rot);
	void erasebigL(int x, int y, int rot);
	void drawsmallL(int x, int y, int rot);
	void erasesmallL(int x, int y, int rot);
	void drawstick(int x, int y, int rot);
	void erasestick(int x, int y, int rot);
	Shape(int x, int y, int t, int rot);
	void godown(int tvar, int rot);	// posunutie tvaru na hernej ploche doprava
	void goleft(int tvar, int rot);	// posunutie tvaru na hernej ploche dolava
	void goright(int tvar, int rot);	// posunutie tvaru na hernej ploche dole/urýchlenie padania tvaru
	void drawnextshape(int x, int y, int t, int rot); // iba nakrelenie, aky tvar bude nasledovat
	void eraseshape(int t, int rot);	// vymazanie tvaru po dopade/na hernu plochu sa dopadnute tvary potom vykresluju cez vector pole 
};


#endif
