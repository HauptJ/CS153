//Josh Haupt
//Create and process a dynamic 2d array
//CS 153 HW 1

#include <iostream>
using namespace std;

int main()
{  
  //gen variables
  int highestclams = 0; //value for highest clams
    
  //input variables    
  int T; //1st line of input
  int H; //matrix hight / columns
  int W; //matrix width /rows
  //int Z; //# of cells in matrix
  
  //arrays
  int numclams;
  int carray[T]; //array for c
  int xarray[T]; //array for x
  int yarray[T];  //array for y
  
  
  //input for # of matrixes
  cout << "Enter # of matrixes" << endl;
  cin >> T; 
  
  //for loop for T / # of matrixes
  for(int a =0; a<T; a++) 
  {
    //user inputs
    cout << "Enter matrix height" << endl;
    cin >> H; //input for matrix hight
    cout << "Enter matrix width" << endl;
    cin >> W; //input for matrix width
  
    //allocate 2d array
    int **m; 
    m = new int*[W]; //new array
    for(int i = 0; i < W; i++) 
    {
      m[i] = new int[H]; 
    }
    
    for (int row = 0; row < W; row++) //row = width
    {
      for(int col = 0; col < H; col++) //col = height
      {
      cout <<"Enter row" <<row<< "col" <<col << endl;
      cin >> m[row][col]; //insert matrix values
	    carray[T] += m[row][col]; // total number of clams
//cout << carray[T] << "Total test" << endl; // ISSUE --- carray  doesn't output correctly in end
      }
    }
  
    //find highest value in matrix
    for (int col = 1; col < H; col++)
    {
      for(int row = 1; row < W; row++)
      {
        numclams = m[row][col];
        if(numclams > highestclams)
        {
          highestclams = numclams;
          xarray[T] = row;
          yarray[T] = col;
        }
      }
    }
    
    
    //de-allocate 2d array
    for(int j = 1; j < W; j++) 
    {
      delete[]m[j];
    }
    delete[]m;
    } //end T loop
  
  
    //output results -- should remove 1
    for(int z = 0; z < T; z++)
    {
      cout << "#" << z << "(" << xarray[T+1] << "," << yarray[T+1] << ")" << carray[T] << endl;
    }
    
    /*for(int j = 0; j < T; j++) 
    {
      cout << "#" << j << "(" << xarray[j] << "," << yarray[j] << ")" << carray[j] << endl;
    }*/
   
  return 0;
}

