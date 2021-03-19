# First-Person Shoot project 
from "Game programming in C++ ch9: Cameras"

## Refercence
https://github.com/gameprogcpp/code

The W/S keys move forward and backward, while the A/D keys strafe the character (that is, move left and right). Moving the mouse left and right rotates the character about the up axis, but moving the mouse up and down pitches only the view, not the character.


##  Basic First-Person Movement
The forward/back movement is implemented in MoveComponent
strafing is implemented in Vector3 Actor::GetRight()
```
  Vector3 Actor::GetRight() const
  {
    // Rotate right axis using quaternion rotation
    return Vector3::Transform(Vector3::UnitY, mRotation);
  }
```

in FPSActor::ActorInput, you can detect the A/D keys and adjust the strafe speed as needed. Now the
character can move with standard first-person WASD controls.

## convert mouse left/right movements to angular speed.
First, the game needs to enable relative mouse mode via SDL_RelativeMouseMode.
SDL_GetRelativeMouseState retrieves the (x, y) motion. 
The maxMouseSpeed constant is an expected maximum amount of relative motion possible per frame
maxAngularSpeed converts the motion into a rotation per second.
```
  int x, y;
  Uint32 buttons = SDL_GetRelativeMouseState(&x, &y);
  // Assume mouse movement is usually between -500 and +500
  const int maxMouseSpeed = 500;
  // Rotation/sec at maximum speed
  const float maxAngularSpeed = Math::Pi * 8;
  float angularSpeed = 0.0f;
  if (x != 0)
  {
    // Convert to approximately [-1.0, 1.0]
    angularSpeed = static_cast<float>(x) / maxMouseSpeed;
    // Multiply by rotation/sec
    angularSpeed *= maxAngularSpeed;
  }
  mMoveComp->SetAngularSpeed(angularSpeed);  
```
## Camera
```
  void CameraComponent::SetViewMatrix(const Matrix4& view)
  {
    // Pass view matrix to renderer and audio system
    Game* game = mOwner->GetGame();
    game->GetRenderer()->SetViewMatrix(view);
    game->GetAudioSystem()->SetListener(view);
  }
```
