#ifndef GRAPHIC_H
#define GRAPHIC_H

#define CLEANUP "x1b[H\x1b[2J"
#define WIDTH 50
#define HEIGHT 50

//*******************************
// METHODS TO DRAW ON TERMINAL
//*******************************
void clearScreen();
void drawScreen(char** screenContent, char** prevScreenContent);


#endif // !GRAPHIC_H

