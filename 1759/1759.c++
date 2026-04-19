#include <iostream>

#include <string> // .size()

#include <algorithm> // sort()



using namespace std;



int l, c;

char letters[15];



// start - index of next letter to add

// vow & cons - num of vowele & consonents of str



void password(int start, string str, int vow, int cons)

{

    // if satisfies the length

    if(str.size()==l) {

        // print only if conditions are met

        if(vow>=1 && cons>=2) {

            cout << str << endl;

            return;

        }

    }

    

    // add the next letters

    for(int i=start; i<c; i++) {

        if(letters[i]=='a' || letters[i]=='e'||letters[i]=='i'||letters[i]=='o'||letters[i]=='u') {

            // update information and put recursion

            password(i+1, str+letters[i], vow+1, cons);

        }

        else {

            password(i+1, str+letters[i], vow, cons+1);

        }

    }

}



int main(int argc, const char * argv[]) {

    cin >> l >> c;

    for(int i=0; i<c; i++) {

        cin >> letters[i];

    }

    

    sort(letters, letters+c);

    

    password(0, "", 0, 0);

}

