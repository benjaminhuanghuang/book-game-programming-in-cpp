
## Real Time and Game Time


## deltaTime
```
// Update x position by 5 pixels
enemy.mPosition.x += 5;
```
If this code moves the enemy at the desired speed on an 8 MHz processor, what happens on a
16 MHz processor? Well, because the game loop now runs twice as fast, the enemy will now also
move twice as fast.

To solve this issue, games use `delta time`: the amount of elapsed `game time` since the last
frame. To convert the preceding code to using delta time, instead of thinking of movement as
pixels per frame, you should think of it as pixels per second. So, if the ideal movement speed is
150 pixels per second, the following code is much more flexible:
```
// Update x position by 150 pixels/second
enemy.mPosition.x += 150 * deltaTime;
```

```
void Game::UpdateGame()
{
  // Delta time is the difference in ticks from last frame
  // (converted to seconds)
  float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;

  // Update tick counts (for next frame)
  mTicksCount = SDL_GetTicks();


  // TODO: Update objects in game world as function of delta time!
  // ...
}
```

## frame limiting
forces the game loop to wait until a target delta time has elapsed

For example, suppose that the target frame rate is 60 FPS. If a frame completes after only 15ms,
frame limiting says to wait an additional ~1.6ms to meet the 16.6ms target time.

```
  //ensure that at least 16ms elapses between frames
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16))
  ;
```

## watch out for a delta time that’s too high

if you pause at a breakpoint in the debugger for five seconds, you’ll end up with a huge delta time, and everything will jump far forward in the simulation.

To fix this problem, you can clamp the delta time to a maximum value (such as 0.05f).


The perfet version
```
  void Game::UpdateGame()
  {
    // Wait until 16ms has elapsed since last frame
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16))
    ;

    // Delta time is the difference in ticks from last frame
    // (converted to seconds)
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    
    // Clamp maximum delta time value
    if (deltaTime > 0.05f)
    {
      deltaTime = 0.05f;
    }
    // TODO: Update objects in game world as function of delta time!
  }
```