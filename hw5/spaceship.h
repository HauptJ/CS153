/* @file: spaceship.h
 * Definition of Abstract class Spaceship
 * @C - Earth Space Navy
 * 
 * Version 13.1.2
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <string>

using namespace std; 

//----------------------------------------
// Auxiliary enumeration type for representing weapon types.
//
enum weapon {
  LASER,
  MISSILE,
  PLASMA
};



//----------------------------------------
// Auxiliary enumeration type for representing ship types
//
enum shiptype {
  FRIGATE,          // no armor, no shields
  DESTROYER,        // armor
  BATTLECRUISER,    // shields
  DREADNOUGHT,      // armor and shields
  DROPSHIP          // armor and personnel
};


//----------------------------------------
/* _________________
  /                 \
  | Spaceship Class |
  \_________________/
   
    ABSTRACT CLASS

    PURPOSE: Base class for all Earth Space-Navy ship classes.
 
*/
class Spaceship {
protected:
  string m_name;      // the name of the ship
  int m_hull;         // the hull strenght
   

public:  

// Purpose: Default Constructor
// Postconditions: name and hull strength set to parameters
// -- INLINE
   Spaceship(string n, int h){
       m_name = n;
       m_hull = h;
   }
   
// Purpose: Tells if a ship is alive.
// Postconditions: 'true' if a ship's hull strength is above zero, 
//                 'false' otherwize.
// -- INLINE
  bool isAlive() const 
  {
    return (m_hull > 0);
  }

// Purpose: Accessor for member variable m_name.
// Returns: The name of the Spaceship.
// -- INLINE, VIRTUAL
  virtual string getName() { return m_name; }

// Purpose: Accessor for member variable m_hull.
// Returns: The hull strenght of the Spaceship.
// -- INLINE, VIRTUAL
  virtual int getHull() { return m_hull; }


// Purpose: Prints the status of a ship.
// -- PURE VIRTUAL
  virtual void status() const = 0;

// Purpose: Changes the status of a ship, when hit by a 
//    weapon 's' with power level 'power'
// -- PURE VIRTUAL
  virtual void hit(weapon s, int power) = 0;

// Purpose: Fire action!. 
//   Returns the weapon 's' and power level the ship will fire
//   and updates the ships status, 
//   (for example: number of missiles left)  
// -- PURE VIRTUAL
  virtual void fire() = 0;
  virtual void fire(weapon& s, int& power) = 0;


// ----------------

// Purpose: Destructor
// -- VIRTUAL
	virtual ~Spaceship() {};
  
}; //Spaceship


#endif