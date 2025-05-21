#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <shlobj.h>
#include "pixels.h"
#include "preprocess.h"

using namespace std;

void clearScreen();

int main()
{
    Preprocess pre;
    Pixels pix;
    vector<string> folder_name;
    while(true)
    {
        int choice;
        cout << "Create New Pixels File For Press [1] :- " << endl;
        cout << "Read   The Pixels File For Press [2] :- " << endl;
        cout << "Clear Screen           For Press [3] :- " << endl;
        cout << "Exit For Press [0] :- " << endl;
        cout << "Choice :- ";
        cin >> choice;
        if (choice==1) pre.create_pixels_txt(folder_name);
        else if(choice==2) pix.read_pixels();
        else if(choice==3) clearScreen();
        else break;
    }
    return 0;
}
void clearScreen()
{
    system("cls");
}