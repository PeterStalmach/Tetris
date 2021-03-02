#ifndef funkcie_h
#define funkcie_h

void gotoxy(short x, short y);				// funkcia na umiestnenie kurzora na konzolu, súradnice sú zadávané v poètoch znakov - z netu
void ShowConsoleCursor(bool showFlag); 		// funkcia na skrytie kurzora na konzole - z netu
void drawpoint(int x, int y);				// vykreslenie základného štvorca na obrazovku s urèením jeho polohy
void erasepoint(int x, int y);				// zmazanie základného štvorca z obrazovky s urèením polohy
void screensize(int &columns, int &rows);	// zistenie šírky a výšky obrazovky v znakoch - z netu
void welcomescreen(int x, int y);			// úvodná obrazovka s nápisom TETRIS

#endif
