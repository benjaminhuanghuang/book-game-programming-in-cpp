
## Vectors
A mathematical vector (not std::vector) represents both a magnitude
and direction in an n-dimensional space, with one component per dimension. This means that
a two-dimensional (2D) vector has x and y components.

A vector has no concept of a position. 
This means that two vectors are equivalent if they have the `same magnitude and same direction`



Forward vector 
is the vector that represents the “straight ahead” direction for the object.

### Getting a Vector between Two Points: Subtraction
![](./_images/vector-subtraction.png)
```
  Vector2 target, ship;
  Vector2 result = target - ship;
```

### Scaling a Vector: Scalar Multiplication
Multiplying a vector by a positive scalar only changes the magnitude of the vector, 
while multiplying by a negative scalar also inverts the direction of the vector

### Combining Two Vectors: Addition
suppose the player is at point p, and the player’s forward vector is f . 
The point that is 150 units “in front” of the player is then p + 150 *f 


### Determining a Distance: Length
length squared (the square of the length) of each vector


### Determining Directions: Unit Vectors and Normalization 
A `unit vector` is a vector with a length of one.
To normalize a vector, divide each component by the length of the vector:
```
  Vector2 a;
  a.Normalize(); // a is now normalized

  Vector2 a;
  Vector2 result = Vector2::Normalize(a);
```

### Converting from an Angle to a Forward Vector

Actor class has a rotation represented by an angle in radians.
This allows you to rotate the way an actor faces. 

In 2D for now, the angle directly corresponds to an angle on the unit circle,
x = cos()
unit circle has +y as up, whereas SDL 2D graphics use +y down
```
  Vector3 Actor::GetForward() const
  {
    return Vector2(Math::Cos(mRotation), - Math::Sin(mRotation));
  }
```


## Converting a Forward Vector to an Angle:
Want a ship to face toward an asteroid. 
1. construct the vector from the ship to the asteroid and normalize this vector.
2. use atan2 to convert the new forward vector to an angle. 
3. set the ship actor’s rotation to this new angle. 
Note that you must negate the y component to account for +y down in SDL’s 2D coordinate system
```
  // (ship and asteroid are Actors)
  Vector2 shipToAsteroid = asteroid->GetPosition() - ship->GetPosition();
  shipToAsteroid.Normalize();

  // Convert new forward to angle with atan2 (negate y-component for SDL)
  float angle = Math::Atan2(-shipToAsteroid.y, shipToAsteroid.x);
  
  ship->SetRotation(angle);
```
## Determining the Angle Between Two Vectors: Dot Product
dot productis 0 means that they are perpendicular to each other because cos(π / 2)= 0 . 

dot product of 1 means the two vectors are parallel and face the same direction. 

dot product of −1 means they are antiparallel
```
  float dotResult = Vector2::Dot(origForward, newForward);
  float angle = Math::Acos(dotResult);
```

### Calculating a Normal: Cross Product
```
  A x B = - B x A
```
The cross product does not work with 2D vectors. However, to convert a 2D vector into a 3D vector, just add a z component of 0.

Using the left-hand rule is a quick way to figure out the direction the cross product result faces
