//Josh Haupt
//HW4 Spaceship Simulator using Inheritence in classes
//3/9

#include <string>
#include <iostream>
using namespace std;

#include "spaceship.h"


class Frigate: public Spaceship
{
public:
    Frigate(string name, int hull): Spaceship(name, hull) {};
    void status() const;
    void hit(weapon s, int power);
};

class Destroyer: public Spaceship
{
  int m_armor;
public:
  Destroyer(string name, int hull, int armor): Spaceship(name, hull), m_armor(armor) {};
  void status() const;
  void hit(weapon s, int power);
};

class Battlecruiser: public Spaceship
{
  int m_shields;
public:
  Battlecruiser(string name, int hull, int shields): Spaceship(name, hull), m_shields(shields) {};
    void status() const;
    void hit(weapon s, int power);
};

class Dreadnought: public Spaceship
{
  int m_shields;
  int m_armor;
public:
  Dreadnought(string name, int hull, int shields, int armor): Spaceship(name, hull), m_shields(shields), m_armor(armor) {};
    void status() const;
    void hit(weapon s, int power);
};

class Dropship: public Spaceship
{
  int m_armor;
  int m_personel;
public:
  Dropship(string name, int hull, int armor, int personel): Spaceship(name, hull), m_armor(armor), m_personel(personel) {};
    void status() const;
    void hit(weapon s, int power);
};


int main()
{
  //variables
  int numships;
  int shipclass;
  string sname;
  int shull;
  int sarmor;
  int sshields;
  int spersonel;
  
  
  //input # ships
  cout <<"# ships"<< endl;
  cin >> numships;
  Spaceship* ship;
  
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
        
        ship = new Frigate(sname, shull);
                
      }  
      break;
      
      case 1: //destroyer
      {
        cout <<"Ship name"<< endl;
        cin >> sname;
        
        cout <<"Ship hull"<< endl;
        cin >> shull;
        
        cout <<"Ship armor"<< endl;
        cin >> sarmor;
                
        ship = new Destroyer(sname, shull, sarmor);
        

      }  
        break;
      
      case 2: //battlecruiser
      {
        cout <<"Ship name"<< endl;
        cin >> sname;
        
        cout <<"Ship hull"<< endl;
        cin >> shull;
        
        cout <<"Ship shields"<< endl;
        cin >> sshields;
                
        ship = new Battlecruiser(sname, shull, sarmor);
                
        
      }  
        break;
    
      case 3: //dreadnought
      {
        cout <<"Ship name"<< endl;
        cin >> sname;
        
        cout <<"Ship hull"<< endl;
        cin >> shull;
        
        cout <<"Ship armor"<< endl;
        cin >> sarmor;
        
        cout <<"Ship shields"<< endl;
        cin >> sshields;
                
        ship = new Dreadnought(sname, shull, sshields, sarmor);
        
        
      }  
        break;
      
      case 4: //dropship
      {
        cout <<"Ship name"<< endl;
        cin >> sname;
        
        cout <<"Ship hull"<< endl;
        cin >> shull;
        
        cout <<"Ship armor"<< endl;
        cin >> sarmor;
        
        cout <<"Personel"<< endl;
        cin >> spersonel;
        
        ship = new Dropship(sname, shull, sarmor, spersonel);
                
      }
        break;
      
      default:
      {
        cout <<"Error"<< endl;
      }
        break;
    }
    //call the hits
    ship -> hit(laser,5);
    ship -> hit(laser,10);
    ship -> hit(laser,15);
    ship -> hit(missile,20);
    ship -> hit(plasma,25);
  }
  return 0;
}


///////////////////////////////////////////////////Frigate

void Frigate::hit(weapon s, int power) 
{
  //variables for number to weapon conversion
  string weapon;
  //number to weapon conversion
  if(s == 0)
  {
    weapon = "Laser";
  }
  else if(s == 1)
  {
    weapon = "Missile";
  }
  else if(s == 2)
  {
    weapon = "Plasma Bolt";
  }
  else
  {
    weapon = "Error";
  }

  if(isAlive() == true)
  {
    m_hull = m_hull - power;
    if( m_hull <= 0)
    
    
    cout << "Frigate " <<m_name<< " destroyed after " <<weapon<< " power " <<power<< endl; // add enum for matching weapon
  }
  else
  {    
    status();
  }
  return;
}

void Frigate::status() const
{
  cout<< "status: Frigate " <<m_name<<" hull " <<m_hull<< endl;
}
/////////////////////////////////////////////////////Destroyer

void Destroyer::hit(weapon s, int power)  //FIX FIX FIX FIX FIX FIX
{
  //variables for number to weapon conversion
  string weapon;
  //number to weapon conversion
  if(s == 0)
  {
    weapon = "Laser";
  }
  else if(s == 1)
  {
    weapon = "Missile";
  }
  else if(s == 2)
  {
    weapon = "Plasma Bolt";
  }
  else
  {
    weapon = "Error";
  }
  
  if(isAlive() == true)
  {
    if(m_armor > 0)
    {
      m_armor = m_armor - power/2;
      if(m_armor < 0)
      {
        m_hull = m_hull + m_armor;
        m_armor = 0;
        if( m_hull <= 0)
        {
          cout << "Destroyer " <<m_name<< " destroyed after " <<weapon<< " power " <<power<< endl; 
          status();
        }
        else if(m_hull > 0)
        {
          cout << "Destroyer " <<m_name<< " survived " <<weapon<< " power " <<power<< endl; 
        }
      }
    }
    else
    {
      m_hull = m_hull - power;
      if( m_hull <= 0)
      {
        cout << "Destroyer " <<m_name<< " destroyed after " <<weapon<< " power " <<power<< endl; 
        status();
      }
    }
  }
  return;
}
    
void Destroyer::status() const
{
  cout<< "status: Destroyer " <<m_name<<" hull " <<m_hull<< " armor " <<m_armor<< endl;
}

////////////////////////////////////////////////////////////////////Battlecruiser

void Battlecruiser::hit(weapon s, int power)
{
  //variables for number to weapon conversion
  string weapon;
  //number to weapon conversion
  if(s == 0)
  {
    weapon = "Laser";
  }
  else if(s == 1)
  {
    weapon = "Missile";
  }
  else if(s == 2)
  {
    weapon = "Plasma Bolt";
  }
  else
  {
    weapon = "Error";
  }
  
  
  if(isAlive() == true)
  {
      m_shields = m_shields - (power/3); //reduce shields
      if(m_shields <=0) //hull 0
      {
        m_hull = m_hull + m_shields;
        if( m_hull <= 0)
        cout << "Frigate " <<m_name<< " destroyed after " <<weapon<< " power " <<power<< endl; // add enum for matching weapon
        status();
      }
    }
      
    else if(s == 3) //plasma
    {
      m_shields = m_shields - power;
      m_hull = (power/2);
      if(m_shields <=0)
      {
        m_hull = m_hull + m_shields;
        if( m_hull <= 0)
        cout << "Frigate " <<m_name<< " destroyed after " <<weapon<< " power " <<power<< endl; // add enum for matching weapon
        status();
      }
    }
    
    else if(s == 2) //missile
    {
      m_hull = m_hull - power;
      if( m_hull <= 0)
      cout << "Frigate " <<m_name<< " destroyed after " <<weapon<< " power " <<power<< endl; // add enum for matching weapon
      status();
    }
  return;
}

void Battlecruiser::status() const
{
  cout<< "status: Batlecruiser" <<m_name<<" hull " <<m_hull<< " shields " <<m_shields<< endl;
}


/////////////////////////////////////////////////////Dreadnought

void Dreadnought::hit(weapon s, int power)
{
  //variables for number to weapon conversion
  string weapon;
  //number to weapon conversion
  if(s == 0)
  {
    weapon = "Laser";
  }
  else if(s == 1)
  {
    weapon = "Missile";
  }
  else if(s == 2)
  {
    weapon = "Plasma Bolt";
  }
  else
  {
    weapon = "Error";
  }

  if(isAlive() == true)
  {
    if(s == 1) //laser
    {
      m_shields = m_shields - (power/3); //reduce shields
      if(m_shields <=0) //hull 0
      {
        m_hull = m_hull + m_shields;
        if( m_hull <= 0)
        cout << "Dreadnought" <<m_name<< " destroyed after " <<weapon<< " power " <<power<< endl; // add enum for matching weapon
        status();
      }
    }
  }
      
    else if(s == 3) //plasma
    {
      m_shields = m_shields - power;
      m_hull = (power/2);
      if(m_shields <=0)
      {
        m_hull = m_hull + m_shields;
        if( m_hull <= 0)
        cout << "Dreadnought" <<m_name<< " destroyed after " <<weapon<< " power " <<power<< endl; // add enum for matching weapon
        status();
      }
    }
    
    else if(s == 2) //missile
    {
      if(m_armor < 0)
      {
        m_armor = m_armor - power/2;
        if(m_armor < 0)
        {
          m_hull = m_hull + m_armor;
          m_armor = 0;
          if( m_hull <= 0)
          cout << "Dreadnought" <<m_name<< " destroyed after " <<weapon<< " power " <<power<< endl; // add enum for matching weapon
          status();
        }
      }
      else
      {
        m_hull = m_hull - power;
        if( m_hull <= 0)
        cout << "Dreadnought" <<m_name<< " destroyed after " <<weapon<< " power " <<power<< endl; // add enum for matching weapon
        status();
      }
  return;
  }
}
  
void Dreadnought::status() const
{
  cout<< "status: Dreadnought" <<m_name<<" hull " <<m_hull<< " shields " <<m_shields<< " armor " <<m_armor<< endl;
}

/////////////////////////////////////////////////////Dropship

void Dropship::hit(weapon s, int power)
{
  //variables for number to weapon conversion
  string weapon;
  //number to weapon conversion
  if(s == 0)
  {
    weapon = "Laser";
  }
  else if(s == 1)
  {
    weapon = "Missile";
  }
  else if(s == 2)
  {
    weapon = "Plasma Bolt";
  }
  else
  {
    weapon = "Error";
  }

  if(isAlive() == true)
  {
    if(m_armor < 0)
    {
      m_armor = m_armor - power/2;
      if(m_armor < 0)
      {
        m_hull = m_hull + m_armor;
        m_personel = (m_personel/4);
        m_armor = 0;
        if( m_hull <= 0)
        cout << " Frigate " <<m_name<< " destroyed after " <<weapon<< " power " <<power<< endl; // add enum for matching weapon
        status();
      }
    }
    else
    {
      m_hull = m_hull - power;
      m_personel = (m_personel/4);
      if( m_hull <= 0)
      cout << " Frigate " <<m_name<< " destroyed after " <<weapon<< " power " <<power<< endl; // add enum for matching weapon
      status();
    }
  }
  return;
}

void Dropship::status() const
{
  cout<< "status: Dreadnought " <<m_name<<" hull " <<m_hull<< " armor " <<m_armor<<" personel " <<m_personel<< endl;
  return;
}



