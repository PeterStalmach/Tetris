#ifndef funkcie_h
#define funkcie_h

void gotoxy(short x, short y);				// funkcia na umiestnenie kurzora na konzolu, s�radnice s� zad�van� v po�toch znakov - z netu
void ShowConsoleCursor(bool showFlag); 		// funkcia na skrytie kurzora na konzole - z netu
void drawpoint(int x, int y);				// vykreslenie z�kladn�ho �tvorca na obrazovku s ur�en�m jeho polohy
void erasepoint(int x, int y);				// zmazanie z�kladn�ho �tvorca z obrazovky s ur�en�m polohy
void screensize(int &columns, int &rows);	// zistenie ��rky a v��ky obrazovky v znakoch - z netu
void welcomescreen(int x, int y);			// �vodn� obrazovka s n�pisom TETRIS

#endif
