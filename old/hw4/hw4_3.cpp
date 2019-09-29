I keep getting expected ";" compiler errors that I cannot seem to figure out. 

    //main.cpp

    #include <string>
    #include <iostream>
    using namespace std;

    #include "spaceship.h"
    /*#include "frigate.h"
    #include "destroyer.h"
    #include "battlecruiser.h"
    #include "dreadnought.h"
    #include "dropship.h"*/

    class frigate: public Spaceship
    {
    public:
      frigate(string name, int hull): Spaceship(name, hull) {};
      void status();
      void hit(weapon s, int power);
    };

    class destroyer: public Spaceship
    {
      int m_armor;
    public:
      destroyer(string name, int hull, int armor): Spaceship(name, hull), m_armor(armor) {};
      void status();
      void hit(weapon s, int power);
    };

    class battlecruiser: public Spaceship
    {
      int m_shields;
    public:
      battlecruiser(string name, int hull, int shields): Spaceship(name, hull), m_shields(shields) {};
      void status();
      void hit(weapon s, int power);
    };

    class dreadnought: public Spaceship
    {
      int m_shields;
      int m_armor;
    public:
      dreadnought(string name, int hull, int shields, int armor): Spaceship(name, hull), m_shields(shields), m_armor(armor) {};
      void status();
      void hit(weapon s, int power);
    };

    class dropship: public Spaceship
    {
      int m_armor;
      int m_personel;
    public:
      dropship(string name, int hull, int armor, int personel): Spaceship(name, hull), m_armor(armor), m_personel(personel) {};
      void status();
      void hit(weapon s, int power);
    };


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
           cout <<"Error"<< endl;
           break;
          }
        }
      }
    return 0;
   }


