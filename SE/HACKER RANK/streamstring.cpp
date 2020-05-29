#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	stringstream s (str);
    vector <int> v;
    int temp,i=0;
    while (s>>temp)
    {
        cout<<temp;
       // v.push_back(temp);
       v.insert(v.begin()+i,temp);
    }
    return v;
    
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}