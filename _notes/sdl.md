# Simple DirectMedia Layer

Simple DirectMedia Layer is a cross-platform software development library designed to provide a hardware abstraction layer for computer multimedia hardware components.

SDL renderer supports 2D graphics, it does not support 3D.


## Setup on Mac
```
  brew insall sdl2
  brew insall sdl2_image
  brew insall sdl2_ttf

  /usr/local/Cellar/sdl2/2.0.12_1
```

Using SDL2 with CMake(https://trenki2.github.io/blog/2017/06/02/using-sdl2-with-cmake/)

Using SDL2_image with CMake(https://trenki2.github.io/blog/2017/07/04/using-sdl2-image-with-cmake/)

https://github.com/tcbrindle/sdl2-cmake-scripts


## SDL Subsystem Flags
SDL_INIT_AUDIO          Audio device management, playback, and recording
SDL_INIT_VIDEO          Video subsystem for creating a window, interfacing with OpenGL, and 2D graphics
SDL_INIT_HAPTIC         Force feedback subsystem
SDL_INIT_GAMECONTROLLER Subsystem for supporting controller input devices


## Window Creation Flags

SDL_WINDOW_FULLSCREEN          Use full-screen mode
SDL_WINDOW_FULLSCREEN_DESKTOP  Use full-screen mode at the current desktop resolution
SDL_WINDOW_OPENGL              Add support for the OpenGL graphics library
SDL_WINDOW_RESIZABLE           Allow the user to resize the window


## SDL destroy
```
void Game::Shutdown()
{
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}
```
## Input process
```
void Game::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
      // If we get an SDL_QUIT event, end loop
      case SDL_QUIT:
        mIsRunning = false;
        break;
		}
	}

	// Get state of keyboard
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	// If escape is pressed, also end loop
	if (state[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}

	// Update paddle direction based on W/S keys
	mPaddleDir = 0;
	if (state[SDL_SCANCODE_W])
	{
		mPaddleDir -= 1;
	}
	if (state[SDL_SCANCODE_S])
	{
		mPaddleDir += 1;
	}
}
```


## Draw
```
	// Renderer for 2D drawing
  SDL_Renderer *mRenderer;


	// Clear back buffer
	SDL_RenderClear(mRenderer);

	// Draw walls
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	// Draw top wall
	SDL_Rect wall{
			0,				// Top left x
			0,				// Top left y
			1024,			// Width
			thickness // Height
	};
	SDL_RenderFillRect(mRenderer, &wall);
```

## Load Image to Texture
```
	IMG_Init(IMG_INIT_PNG)


	SDL_Surface* IMG_Load( const char* file // Image file name);


```