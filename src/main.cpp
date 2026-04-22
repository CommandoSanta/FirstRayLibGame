#include "raylib.h"
//#include <GameObject.h>

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	const int screenWidth = 800;
	const int screenHeight = 600; 
	InitWindow(screenWidth, screenHeight, "Game Testing");

	const int targetFPS = 60;
	SetTargetFPS(targetFPS);

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");
	
	// game loop
	while (!WindowShouldClose())	
	{
		BeginDrawing();
		ClearBackground(WHITE);

		// draw some text using the default font
		const int textX = 0;
		const int textY = 0;
		const int textSize = 20;
		const Color textColor = BLACK;
		DrawText("Hello", textX, textY, textSize, textColor);

		DrawTexture(wabbit, 400, 200, WHITE);
		
		EndDrawing();
	}

	// cleanup
	UnloadTexture(wabbit);
	CloseWindow();

	return 0;
}
