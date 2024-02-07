#include<iostream>
#include<map>
#include<vector>

using namespace std;


bool CheckForSmallercharacter(string &input , char ch , int start , int end ){
    if(start > end)
        return false;

    for (int i = start ; i <= end ; i++){
        if(input[i] < ch)
            return true;
    }

    return false;
}




string RemoveDuplicatewithOrdering(string input , map<char , vector<int>> &char_map , string &ans){

    for (int i = 0 ; i < input.size() ; i++){

        if(char_map.find(input[i]) == char_map.end())
            continue;
        vector<int> &char_repeater = char_map[input[i]];
        if (char_repeater.size() == 1)
            ans.push_back(input[i]);
        
        else {
           // for (int i = 0 ; i < char_repeater.size()-1 ; i++){
                
                int start = char_repeater[0];
                int end = char_repeater[1];
                if(!CheckForSmallercharacter(input , input[i] , start+1 , end-1)){
                    ans.push_back(input[i]);
                    char_map.erase(input[i]);
                }
                else {
                    char_repeater.erase(char_repeater.begin());
                }

         //   }
        }
    }

}




int main(){

    string input = "bcadcdeb";
    string ans;

    map<char , vector<int>> char_map;
    for(int i = 0 ; i < input.size() ; i++){
        char_map[input[i]].push_back(i); 
    }

    RemoveDuplicatewithOrdering(input , char_map , ans);
    cout << ans << endl;
}