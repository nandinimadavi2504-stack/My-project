#include<bits/stdc++.h>
using namespace std;

void printWord(const string &s, int i) {
    if(i== s.size() ) return;
    cout <<s[i] << "\n";
    printWord(s,i+1);
}
int main(){
    string word = "WORKATTECH" ;
    printWord(word,0);

    return 0;

}

