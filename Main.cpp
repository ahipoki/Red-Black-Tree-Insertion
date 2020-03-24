#include <iostream>
#include <cstring>

using namespace std;

void strupper(char* str);

int main()
{
  char input[80];
  bool running = true;
  while (running == true){
    cout<<"Do you want to add a single number, read in a series of numbers from a file, print out a representation of the tree, or quit?"<<endl;
    cin.getline(input, sizeof(input));
    strupper(input);
    if (strcmp(input, "ADD") == 0){
      cout<<"Add"<<endl;
    }
    else if (strcmp(input, "READ") == 0){
      cout<<"READ"<<endl;
    }
    else if (strcmp(input, "PRINT") == 0){
      cout<<"Print"<<endl;
    }
    else if (strcmp(input, "QUIT") == 0){
      running = false;
    }
    else{
      cout<<"That's an invalid option"<<endl;
    }
  }
}

void strupper(char* str){
  int len = strlen(str);
  for (int i = 0; i < len; i++){
    str[i] = toupper(str[i]);
  }
}
