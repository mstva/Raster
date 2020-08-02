#include "Screen.h"

int main(int argc, char** argv) {

	Screen screen;

	if (screen.initScreen()) { screen.runScreen(); }

	screen.closeScreen();

	return 0;
}

