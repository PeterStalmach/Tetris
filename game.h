#ifndef mapa_h
#define mapa_h
#include<vector>

class Game
{
	public:
	int score,mapaY,mapaX,firstshape;
	std::vector <int> row;	// jednorozmerné vector pole, ktoré vyuijem na vytvorenie dvojrozmerného vector pola
	std::vector<std::vector<int> > pole; // pole do ktorého sa zapisuje zaplnenos hernej plochy a aj urèuje hranice hernej plochy
	bool end;	// premenná urèujúca koniec hry, keï je nastavená na tru hra skonèí/hlavná herná sluèka sa ukonèí 
	
	int mapa(int x, int y);			// vykreslenie obdånika ohranièujúceho hernu plochu
	void GameEnd(int x, int y, int body);					// nastavı premennú end na true a zobrazí závereènú obrazovku s bodmi
	Game(int a, int b);				// konštruktor
	int NextShape(int before);		// náhodné vygenerovanie nového tvaru s podmienkou, e novı tvar sa nesmie rovna poslednému predošlému tvaru
	bool checkdown(int x, int y, int tvar, int rot);	// kontrola dvojrozmerného pola pod tvarom
	bool checkleft(int x, int y, int tvar, int rot);	// kontrola dvojrozmerného pola na¾avo od tvaru
	bool checkright(int x, int y, int tvar, int rot);	// kontrola dvojrozmerného pola napravo od tvaru
	void vypispole(int x, int a, int b);				// zobrazenie vnútorného pola - len zobrazované len pri vıvoji hry
	void zapisdopola(int x, int y, int tvar, int rot);	// zaznaèenie tvarov do pola, tam kde sa zastavili
	int otoc(int x, int y, int tvar, int rot, int shapeX, int shapeY, int rows, int columns); // otáèanie tvaru s kontrolou okolia okolo tvaru
	bool checkend();	// kontrola zaplnenia pola/ kontroluje sa druhı riadok v poli
	void checkline(int rows);	// kontrola èi bol vytvorenı súvislı riadok cez celú šírku pola
	void drawfromfield(int rows,int columns);	// vykreslovanie znakov na hernú plochu/ ak je v poli 1 - vykreslí sa znak, ake je v poli 0 - vykreslí sa medzera
};


#endif
