#define _GLIBCXX_USE_CXX11_ABI 0

#include <iostream>
#include <string>

using namespace std;
 
int main () {
  int dec = 1;

    while (dec == 1) {
      string ans;
      int pn, gc, tn;
      cout << "Do you want to start a new recording? (start/stop): ";
      getline (cin, ans);
      if (ans == "start"){
        cout << "Enter person number (1-10) "; 
        getline (cin, pn);
        cout << "Enter gesture class (1-4) "; 
        getline (cin, gc);
        cout << "Enter try number (1-10) "; 
        getline (cin, tn);
      }else if (ans == "stop"){
        cout << "Cool!.\n";
        dec=0;
      }else {
        cout << "Enter 'start' or 'stop' (case sensitive)" << ".\n";
      }
    }