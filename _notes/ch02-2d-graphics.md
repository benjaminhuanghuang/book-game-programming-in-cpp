


## Game object
- Object update the game world and draw every frame
- Static object: draw but do not update
- Camera: update but don't draw
- trigger: causes something to occur based on another object’s intersection



## Game Object Models
- monolithic class hierarchy:  all game objects inherit from one base class.

Suppose Actor Class is the base class of all object, this assumes that every Actor can update and draw. 
But as discussed, there may be objects that aren’t visible, and thus calling Draw on these objects is a waste of time.

Some objects need method Move(), but some objects not. you could extend the hierarchy with a new MovingActor that exists between Actor and any subclasses that need movement. However, this adds more complexity to the class hierarchy.

Furthermore, having one big class hierarchy can cause difficulties when two sibling classes later need to have features shared between them. that caused `diamond inheritance`

- component-based game object model
Unity game engine uses it

In this approach, there is a game object class, but there are no subclasses of the game object. 
Instead, the game object class has-a collection of `component objects` that implement needed functionality.

For example, in the monolithic hierarchy we looked at earlier, Pinky is a subclass of Ghost,
which is a subclass of Actor. 
In a component-based model, Pinky is a GameObject instance containing four components: PinkyBehavior, CollisionComponent, TransformComponent, and DrawComponent.


A disadvantage of pure component systems is that `dependencies` between components in the same game object are not clear.
For instance, it’s likely that the `DrawComponent` needs to know about the `TransformComponent` in order know where the object should draw. This means that the DrawComponent likely needs to ask the owning `GameObject` about its TransformComponent. The querying can become a noticeable performance bottleneck.

- hybrid of the monolithic hierarchy and the component object models
The base Actor class with a handful of virtual functions, but each actor also has a vector of components.

the Actor class needs access to the Game class. There are 2 approace:
1. make the game object a globally singleton
2. use dependency injection. the actor constructor receives a pointer to the Game class
```
class Actor
{
  public:
  // Used to track state of actor
  enum State
  {
    EActive,
    EPaused,
    EDead
  };
  // Constructor/destructor
  Actor(class Game* game);
  virtual ~Actor();
  // Update function called from Game (not overridable)
  void Update(float deltaTime);
  // Updates all the components attached to the actor (not overridable)
  void UpdateComponents(float deltaTime);
  // Any actor-specific update code (overridable)
  virtual void UpdateActor(float deltaTime);
  // Getters/setters
  // ...
  // Add/remove components
  void AddComponent(class Component* component);
  void RemoveComponent(class Component* component);
  private:
  // Actor's state
  State mState;
  // Transform
  Vector2 mPosition; // Center position of actor
  float mScale; // Uniforms scale of actor (1.0f for 100%)
  float mRotation; // Rotation angle (in radians)
  // Components held by this actor
  std::vector<class Component*> mComponents;
  class Game* mGame;
};
```
```
  class Component
  {
    public:
    // Constructor
    // (the lower the update order, the earlier the component updates)
    Component(class Actor* owner, int updateOrder = 100);
    // Destructor
    virtual ~Component();
    // Update this component by delta time
    virtual void Update(float deltaTime);
    int GetUpdateOrder() const { return mUpdateOrder; }
    protected:
    // Owning actor
    class Actor* mOwner;
    // Update order of component
    int mUpdateOrder;
  }
```


## Integrating Game Objects into the Game Loop



## Sprites
Exercise 2.2
single animation: composed of all the sprites in the vector

support several different animations. Define each animation as a range of textures in the vector. 

non-looping animations. When defining an animation as a range of textures, also allow specification of looping or non-looping. When a non-looping animation finishes, it should not wrap back to the initial texture.

## Scrolling background
```
  class BGSpriteComponent : public SpriteComponent

```

The background is a generic Actor (not a subclass) that has two BGSpriteComponents.
The different scroll speeds of these two backgrounds create a parallax effect. 

All these actors, including the ship, are created in the Game::LoadData function.


Exercise 2.3
Create a new component called `TileMapComponent` that inherits from SpriteComponent.
This class needs a function to load and read in a tile map CSV file. 

Then override Draw to draw each tile from the tile set texture. 
In order to draw only part of a texture, instead of the entire texture, use the srcrect parameter of `SDL_RenderCopyEx`. This can then draw only a single tile square from the tile set texture rather than the entire tile set.

