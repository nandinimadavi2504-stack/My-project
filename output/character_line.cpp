#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string word = "WORKATTECH" ;
    for(int i = 0;i < word.size();i += 2){
        cout << word[i]<< word[i + 1] << endl;

    }
    return 0;
}