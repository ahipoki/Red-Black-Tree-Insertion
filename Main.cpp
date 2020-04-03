#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "Node.h"
#include "RBT.h"

#define CC_RED "\033[31m"
#define CC_CLR "\033[0m"
//Color text

using namespace std;

void strupper(char* str);
int strToInt(char* str);
void Insert(RBT*);
void Read(RBT*);
void PrintTree(RBT*);

int main()
{
  RBT* rbt = new RBT();
  //New red-black tree
  char input[80];
  //User input
  bool running = true;
  //Program running
  while (running == true){//While program is running
    cout<<"Do you want to add a single number, read in a series of numbers from a file, print out a representation of the tree, or quit?"<<endl;
    //Ask user if they want to add a single number, read in a series of numbers from a file, print out the tree, or quit
    cin.getline(input, sizeof(input));
    //Take in the user's input
    strupper(input);
    //Make it uppercase
    if (strcmp(input, "ADD") == 0){//If they said ADD
      Insert(rbt);
      //Call Insert
    }
    else if (strcmp(input, "READ") == 0){//If they said READ
      Read(rbt);
      //Call Read
    }
    else if (strcmp(input, "PRINT") == 0){//If they said PRINT
      PrintTree(rbt);
      //Call PrintTree
    }
    else if (strcmp(input, "QUIT") == 0){//If they said QUIT
      running = false;
      //Stop the program
    }
    else{//Anything else
      cout<<"That's an invalid option"<<endl;
      //Tell the user that's an invalid option
    }
  }
  delete rbt;
  //Delete the red-black tree
}

void strupper(char* str){//Make input uppercase
  int len = strlen(str);
  //Length of user's input
  for (int i = 0; i < len; i++){//For loop looping through user's input
    str[i] = toupper(str[i]);
    //Make each letter uppercase
  }
}

int strToInt(char* str){//Str to int function
    int num = 0;
    for (int i = 0; i < strlen(str); i++){//Loop through length of str
        if (!isdigit(str[i])){//If it's not a digit
          continue;
          //Continue
        }
        num *= 10;
        num += str[i] - '0';
    }
    return num;
}

void Insert(RBT* rbt){//Insert
  int key;
  //Key
  cout<<"What number do you want to add to the tree?"<<endl;
  //Ask the user what number they want to add
  cin>>key;
  //Take in their input
  cin.clear();
  cin.ignore(999, '\n');
  rbt->Insert(key);
  //Call Insert passing in the key
}

void Read(RBT* rbt){//Read
  char fileName[80];
  //File name
  char line[100];
  cout<<"Enter a file name"<<endl;
  //Ask user for a file name
  cin.getline(fileName, sizeof(fileName));
  //Get user's input
  ifstream fileStream;
  fileStream.open(fileName);
  //Try and open the file
  if (fileStream){//If it worked
    fileStream.getline(line, sizeof(line));
    //Get the numbers from the file
  }
  else{//If it didn't work
    cout<<"Couldn't find that file"<<endl;
    //Tell the user the file couldn't be found
  }
  fileStream.close();
  //Close the file
}

void PrintTree(RBT* rbt){//Print
  rbt->PrintTree();
  //Call PrintTree
}
