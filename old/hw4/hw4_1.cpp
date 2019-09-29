//main.cpp

#include <string>
#include <iostream>
using namespace std;

#include "spaceship.h"
#include "frigate.h"
#include "destroyer.h"
#include "battlecruiser.h"
#include "dreadnought.h"
#include "dropship.h"


int main()
{
  //variables
  int numships;
  int shipclass;
  string sname;
  int shull;
  int spersonel;
  
  
  //input # ships
  cout <<"# ships"<< endl;
  cin >> numships;
  for(int i = 0; i < numships; i++)
  {
    cout <<"Ship class"<< endl;
    cin >> shipclass;
    switch (shipclass)
    {
      case 0: //frigate
      {
        cout <<"Ship name"<< endl;
        cin >> sname;
        
        cout <<"Ship hull"<< endl;
        cin >> shull;
        
        frigate a(sname, shull);
        
        break;
      }
      case 1: //destroyer
      {
        cout <<"Ship name"<< endl;
        cin >> sname;
        
        cout <<"Ship hull"<< endl;
        cin >> shull;
        
        destroyer a(sname, shull);
        
        break;
      }
      case 2: //battlecruiser
      {
        cout <<"Ship name"<< endl;
        cin >> sname;
        
        cout <<"Ship hull"<< endl;
        cin >> shull;
        
        battlecruiser a(sname, shull);
        
        break;
      }
      case 3: //dreadnought
      {
        cout <<"Ship name"<< endl;
        cin >> sname;
        
        cout <<"Ship hull"<< endl;
        cin >> shull;
        
        dreadnought a(sname , shull);
        
        break;
      }
      case 4: //dropship
      {
        cout <<"Ship name"<< endl;
        cin >> sname;
        
        cout <<"Ship hull"<< endl;
        cin >> shull;
        
        cout <<"Personel"<< endl;
        cin >> spersonel;
        
        dropship a(sname, shull, spersonel);

        break;
      }
      default:
      {
        cout <<"meow"<< endl;
        break;
      }
    }
    //i++; //increment at end
  }
  return 0;
}
