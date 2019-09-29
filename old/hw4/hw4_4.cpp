//main.cpp

#include <string>
#include <iostream>
using namespace std;

#include "spaceship.h"


class Frigate: public Spaceship
{
public:
    Frigate(string name, int hull): Spaceship(name, hull) {};
    void status() const {};
    void hit(weapon s, int power) {};
    void Frigate::hitcalls() {};
};

class Destroyer: public Spaceship
{
  int m_armor;
public:
  //Destroyer(string name = "Name", int hull = 1, int armor = 1);
  Destroyer(string name, int hull, int armor): Spaceship(name, hull), m_armor(armor) {};
  void status() const {};
  void hit(weapon s, int power) {};
  void Destroyer::hitcalls() {};
};

class Battlecruiser: public Spaceship
{
  int m_shields;
public:
  //Battlecruiser(string name = "Name", int hull = 1, int shields = 1);
  Battlecruiser(string name, int hull, int shields): Spaceship(name, hull), m_shields(shields) {};
    void status() const {};
    void hit(weapon s, int power) {};
    void Battlecruiser::hitcalls() {};
};

class Dreadnought: public Spaceship
{
  int m_shields;
  int m_armor;
public:
  //Dreadnought(string name = "Name", int hull = 1, int shields = 1, int armor = 1);
  Dreadnought(string name, int hull, int shields, int armor): Spaceship(name, hull), m_shields(shields), m_armor(armor) {};
    void status() const {};
    void hit(weapon s, int power) {};
    void Dreadnought::hitcalls() {};
};

class Dropship: public Spaceship
{
  int m_armor;
  int m_personel;
public:
  //Dropship(string name = "Name", int hull = 1, int armor = 1, int personel = 1);
  Dropship(string name, int hull, int armor, int personel): Spaceship(name, hull), m_armor(armor), m_personel(personel) {};
    void status() const {};
    void hit(weapon s, int power) {};
    void Dropship::hitcalls() {};
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
        
        Frigate::ship -> hitcalls()
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
        
        //Destroyer a(sname, shull, sarmor);
        
        ship = new Destroyer(sname, shull, sarmor);
        
        Destroyer::ship -> hitcalls()
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
        
        //Battlecruiser a(sname, shull, sshields);
        
        ship = new Battlecruiser(sname, shull, sarmor);
        
        Battlecruiser::ship -> hitcalls()
        
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
        
        //Dreadnought a(sname , shull, sarmor, sshields);
        
        ship = new Dreadnought(sname, shull, sshields, sarmor);
        
        Dreadnought::ship -> hitcalls()
        
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
        
        Dropship::ship -> hitcalls()
      }
        break;
      
      default:
      {
        cout <<"Error"<< endl;
      }
        break;
    }
  }
  return 0;
}

void Frigate::hitcalls()
{
  for(int i = 0; i < 5; i++)
  {
    if(s = 1)
    {
      hit(1, 5)
    }
    else if(s = 2)
    {
      hit(1, 10)
    }
    else if(s = 3)
    {
      hit(1, 15)
    }
    else if(s = 4)
    {
      hit(2, 20)
    }
    else if(s = 5)
    {
      hit(3, 25)
    }
    else
    {
      cout<<"Error"<< endl;
    }
  return;
}


void Destroyer::hitcalls()
{
  for(int i = 0; i < 5; i++)
  {
    if(s = 1)
    {
      hit(1, 5)
    }
    else if(s = 2)
    {
      hit(1, 10)
    }
    else if(s = 3)
    {
      hit(1, 15)
    }
    else if(s = 4)
    {
      hit(2, 20)
    }
    else if(s = 5)
    {
      hit(3, 25)
    }
    else
    {
      cout<<"Error"<< endl;
    }
  return;
}

void Battlecruiser::hitcalls()
{
  for(int i = 0; i < 5; i++)
  {
    if(s = 1)
    {
      hit(1, 5)
    }
    else if(s = 2)
    {
      hit(1, 10)
    }
    else if(s = 3)
    {
      hit(1, 15)
    }
    else if(s = 4)
    {
      hit(2, 20)
    }
    else if(s = 5)
    {
      hit(3, 25)
    }
    else
    {
      cout<<"Error"<< endl;
    }
  return;
}

void Dreadnought::hitcalls()
{
  for(int i = 0; i < 5; i++)
  {
    if(s = 1)
    {
      hit(1, 5)
    }
    else if(s = 2)
    {
      hit(1, 10)
    }
    else if(s = 3)
    {
      hit(1, 15)
    }
    else if(s = 4)
    {
      hit(2, 20)
    }
    else if(s = 5)
    {
      hit(3, 25)
    }
    else
    {
      cout<<"Error"<< endl;
    }
  return;
}

void Dropship::hitcalls()
{
  for(int i = 0; i < 5; i++)
  {
    if(s = 1)
    {
      hit(1, 5)
    }
    else if(s = 2)
    {
      hit(1, 10)
    }
    else if(s = 3)
    {
      hit(1, 15)
    }
    else if(s = 4)
    {
      hit(2, 20)
    }
    else if(s = 5)
    {
      hit(3, 25)
    }
    else
    {
      cout<<"Error"<< endl;
    }
  return;
}


void Frigate::hit(weapon s, int power) 
{
  if( ship -> isAlive() == true)
  {
    m_hull = m_hull - power;
    if( m_hull <= 0)
    cout << "Frigate" <<m_name<< "destroyed after" <<s<< "power" <<power<< endl; // add enum for matching weapon
    status() const
  }
  return;
}

void Frigate::status() const;
{
  if( ship -> isAlive() == true)
  {
    cout<< "status: hull" <<m_hull<< endl;
  }
  else
  {
    cout<< "Ship got destroyed" << endl;
  return;
}  

void Destroyer::hit(weapon s, int power)
{
  if( ship -> isAlive() == true)
  {
    if(m_armor < 0)
    {
      m_armor = m_armor - power/2;
      if(m_armor < 0)
      {
        m_hull = m_hull + m_armor;
        m_armor = 0;
        if( m_hull <= 0)
        cout << "Frigate" <<m_name<< "destroyed after" <<s<< "power" <<power<< endl; // add enum for matching weapon
        status() const
      }
    }
    else
    {
      m_hull = m_hull - power;
      if( m_hull <= 0)
      cout << "Frigate" <<m_name<< "destroyed after" <<s<< "power" <<power<< endl; // add enum for matching weapon
      status() const
    }
  }
  return;
}
    
void Destroyer::status() const;
{
  if( ship -> isAlive() == true)
  {
    cout<< "status: hull" <<m_hull<< "armor" <<m_armor<< endl;
  }
  else
  {
    cout<< "Ship got destroyed" << endl;
  return;
}

void Battlecruiser::hit(weapon s, int power)
{
  if( ship -> isAlive() == true)
  {
    if(s == 1) //laser
    {
      m_shields = m_shields - (power/3) //reduce shields
      if(shields <=0) //hull 0
      {
        m_hull = m_hull + m_shields;
        if( m_hull <= 0)
        cout << "Frigate" <<m_name<< "destroyed after" <<s<< "power" <<power<< endl; // add enum for matching weapon
        status() const
      {
    {
      
    else if(s == 3) //plasma
    {
      m_shields = m_shields - power;
      m_hull = (m_power/2);
      if(shields <=0)
      {
        m_hull = m_hull + m_shields;
        if( m_hull <= 0)
        cout << "Frigate" <<m_name<< "destroyed after" <<s<< "power" <<power<< endl; // add enum for matching weapon
        status() const
      }
    }
    
    else if(s == 2) //missile
    {
      m_hull = m_hull - power;
      if( m_hull <= 0)
      cout << "Frigate" <<m_name<< "destroyed after" <<s<< "power" <<power<< endl; // add enum for matching weapon
      status() const
    }
  return;
}

void Battlecruiser::status() const;
{
  if( ship -> isAlive() == true)
  {
    cout<< "status: hull" <<m_hull<< "shields" <<m_shields<< endl;
  }
  else
  {
    cout<< "Ship got destroyed" << endl;
  return;
}

void Dreadnought::hit(weapon s, int power)
{
  if( ship -> isAlive() == true)
  {
    if(s == 1) //laser
    {
      m_shields = m_shields - (power/3) //reduce shields
      if(shields <=0) //hull 0
      {
        m_hull = m_hull + m_shields;
        if( m_hull <= 0)
        cout << "Dreadnought" <<m_name<< "destroyed after" <<s<< "power" <<power<< endl; // add enum for matching weapon
        status() const
      {
    {
      
    else if(s == 3) //plasma
    {
      m_shields = m_shields - power;
      m_hull = (m_power/2);
      if(shields <=0)
      {
        m_hull = m_hull + m_shields;
        if( m_hull <= 0)
        cout << "Dreadnought" <<m_name<< "destroyed after" <<s<< "power" <<power<< endl; // add enum for matching weapon
        status() const
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
          cout << "Dreadnought" <<m_name<< "destroyed after" <<s<< "power" <<power<< endl; // add enum for matching weapon
          status() const
        }
      }
      else
      {
        m_hull = m_hull - power;
        if( m_hull <= 0)
        cout << "Dreadnought" <<m_name<< "destroyed after" <<s<< "power" <<power<< endl; // add enum for matching weapon
        status() const
      }
  return;
}
  
void Dreadnought::status() const;
{
  if( ship -> isAlive() == true)
  {
    cout<< "status: hull" <<m_hull<< "armor" <<m_armor<<"shields" <<m_shields<< endl;
  }
  else
  {
    cout<< "Ship got destroyed" << endl;
  return;
}

void Destroyer::hit(weapon s, int power)
{
  if( ship -> isAlive() == true)
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
        cout << "Frigate" <<m_name<< "destroyed after" <<s<< "power" <<power<< endl; // add enum for matching weapon
        status() const
      }
    }
    else
    {
      m_hull = m_hull - power;
      m_personel = (m_personel/4);
      if( m_hull <= 0)
      cout << "Frigate" <<m_name<< "destroyed after" <<s<< "power" <<power<< endl; // add enum for matching weapon
      status() const
    }
  }
  return;
}

void Dropship::status() const;
{
  if( ship -> isAlive() == true)
  {
    cout<< "status: hull" <<m_hull<< "armor" <<m_armor<<"persons" <<m_personel<< endl;
  }
  else
  {
    cout<< "Ship got destroyed" << endl;
  return;
}


