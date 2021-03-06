// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once

#include <SDL.h>
#include <unordered_map>
#include <string>
#include <vector>
#include "VertexArray.h"
#include "Renderer.h"
#include "PlaneActor.h"
#include "PhysWorld.h"

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor *actor);
	void RemoveActor(class Actor *actor);

	Renderer *GetRenderer() { return mRenderer; }
	PhysWorld *GetPhysWorld() { return mPhysWorld; }

	// Game-specific
	void AddPlane(class PlaneActor *plane);
	void RemovePlane(class PlaneActor *plane);
	std::vector<class PlaneActor *> &GetPlanes() { return mPlanes; }

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();

	// All the actors in the game
	std::vector<class Actor *> mActors;
	// Any pending actors
	std::vector<class Actor *> mPendingActors;

	class Renderer *mRenderer;
	class PhysWorld *mPhysWorld;

	Uint32 mTicksCount;
	bool mIsRunning;
	// Track if we're updating actors right now
	bool mUpdatingActors;

	// Game-specific code
	std::vector<class PlaneActor *> mPlanes;
	class FPSActor *mFPSActor;
};