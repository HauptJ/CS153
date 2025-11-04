/* @file: spaceship.h
 * Definition of Abstract class Spaceship
 * @C - Earth Space Navy
 * 
 * Version 0.001
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <string>

using namespace std; 

//----------------------------------------
// Auxiliary enumeration type for representing weapon types.
//
enum weapon {
  laser,
  missile,
  plasma
};


//----------------------------------------
// Auxiliary enumeration type for representing ship types
//
enum shiptype {
  frigate,          // no armor, no shields
  destroyer,        // armor
  battlecruiser,    // shields
  dreadnought,      // armor and shields
  dropship          // armor and personnel
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
  bool isAlive() 
  {
    return (m_hull > 0);
  }

// Purpose: Prints the status of a ship.
// -- VIRTUAL
virtual void status() const = 0;

// Purpose: Changes the status of a ship, when hit by a 
//    weapon 's' with power level 'power'
// -- VIRTUAL
virtual void hit(weapon s, int power) = 0;
  
}; //Spaceship


#endif