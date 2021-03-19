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
#include "GameMath.h"
#include "SoundEvent.h"
#include "Font.h"
#include "TextResource.h"
class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor *actor);
	void RemoveActor(class Actor *actor);

	class Renderer *GetRenderer() { return mRenderer; }
	class AudioSystem *GetAudioSystem() { return mAudioSystem; }
	class PhysWorld *GetPhysWorld() { return mPhysWorld; }
	class HUD *GetHUD() { return mHUD; }

	class Font *GetFont(const std::string &fileName);

	void LoadText(const std::string &fileName);
	const std::string &GetText(const std::string &key);

	class Skeleton *GetSkeleton(const std::string &fileName);

	class Animation *GetAnimation(const std::string &fileName);

	TextResource *mTextResource;

	// Manage UI stack
	const std::vector<class UIScreen *> &GetUIStack() { return mUIStack; }
	void PushUI(class UIScreen *screen);

	class FPSActor* GetPlayer() { return mFPSActor; }

	enum GameState
	{
		EGameplay,
		EPaused,
		EQuit
	};

	GameState GetState() const { return mGameState; }
	void SetState(GameState state) { mGameState = state; }

	const std::vector<class Actor *> &GetActors() const { return mActors; }
	// Game-specific
	void AddPlane(class PlaneActor *plane);
	void RemovePlane(class PlaneActor *plane);
	std::vector<class PlaneActor *> &GetPlanes() { return mPlanes; }

private:
	void ProcessInput();
	void HandleKeyPress(int key);
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();

	// All the actors in the game
	std::vector<class Actor *> mActors;
	// Any pending actors
	std::vector<class Actor *> mPendingActors;

	std::vector<class UIScreen *> mUIStack;
	// Map for fonts
	std::unordered_map<std::string, class Font *> mFonts;
	// Map of loaded skeletons
	std::unordered_map<std::string, class Skeleton *> mSkeletons;
	// Map of loaded animations
	std::unordered_map<std::string, class Animation *> mAnims;

	class Renderer *mRenderer;
	class AudioSystem *mAudioSystem;
	class PhysWorld *mPhysWorld;
	class HUD *mHUD;

	Uint32 mTicksCount;
	bool mIsRunning;
	GameState mGameState;
	// Track if we're updating actors right now
	bool mUpdatingActors;

	// Game-specific code
	std::vector<class PlaneActor *> mPlanes;
	class FPSActor *mFPSActor;
	class SpriteComponent *mCrosshair;

	SoundEvent mMusicEvent;
	SoundEvent mReverbSnap;

	static const int SCREEN_WIDTH = 1280;
	static const int SCREEN_HEIGHT = 720;
};
