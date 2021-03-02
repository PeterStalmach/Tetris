#ifndef mapa_h
#define mapa_h
#include<vector>

class Game
{
	public:
	int score,mapaY,mapaX,firstshape;
	std::vector <int> row;	// jednorozmern� vector pole, ktor� vyu�ijem na vytvorenie dvojrozmern�ho vector pola
	std::vector<std::vector<int> > pole; // pole do ktor�ho sa zapisuje zaplnenos� hernej plochy a aj ur�uje hranice hernej plochy
	bool end;	// premenn� ur�uj�ca koniec hry, ke� je nastaven� na tru hra skon��/hlavn� hern� slu�ka sa ukon�� 
	
	int mapa(int x, int y);			// vykreslenie obd�nika ohrani�uj�ceho hernu plochu
	void GameEnd(int x, int y, int body);					// nastav� premenn� end na true a zobraz� z�vere�n� obrazovku s bodmi
	Game(int a, int b);				// kon�truktor
	int NextShape(int before);		// n�hodn� vygenerovanie nov�ho tvaru s podmienkou, �e nov� tvar sa nesmie rovna� posledn�mu predo�l�mu tvaru
	bool checkdown(int x, int y, int tvar, int rot);	// kontrola dvojrozmern�ho pola pod tvarom
	bool checkleft(int x, int y, int tvar, int rot);	// kontrola dvojrozmern�ho pola na�avo od tvaru
	bool checkright(int x, int y, int tvar, int rot);	// kontrola dvojrozmern�ho pola napravo od tvaru
	void vypispole(int x, int a, int b);				// zobrazenie vn�torn�ho pola - len zobrazovan� len pri v�voji hry
	void zapisdopola(int x, int y, int tvar, int rot);	// zazna�enie tvarov do pola, tam kde sa zastavili
	int otoc(int x, int y, int tvar, int rot, int shapeX, int shapeY, int rows, int columns); // ot��anie tvaru s kontrolou okolia okolo tvaru
	bool checkend();	// kontrola zaplnenia pola/ kontroluje sa druh� riadok v poli
	void checkline(int rows);	// kontrola �i bol vytvoren� s�visl� riadok cez cel� ��rku pola
	void drawfromfield(int rows,int columns);	// vykreslovanie znakov na hern� plochu/ ak je v poli 1 - vykresl� sa znak, ake je v poli 0 - vykresl� sa medzera
};


#endif
