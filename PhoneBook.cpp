#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

struct Trie{

    int *collection;
    Trie * next_node;
    bool delimiter[26];
  
    Trie(){
        collection = new int[26];
        for (int i = 0 ; i < 26 ; i++){
            collection[i] = 0;
            delimiter[i] = false;
        }
        next_node = nullptr;

    }

};


void insert (Trie **node , string name){
    int i = 0;
    Trie *itr = *node;
    for (; i < name.size()-1 ; i++){

        if(itr->collection[name[i]-'a'] == 1){
            if(itr->next_node){
                itr = itr->next_node;
            }                
            else {
                itr->next_node = new Trie();
                itr = itr->next_node;
            }
        }
        else {
                std::cout << "inserting charcter - : " << name[i] << " at position :" << name[i] - 'a'<<  endl;
                itr->collection[name[i]- 'a'] == 1;
                if (itr->next_node){
                    itr = itr->next_node;
                }
                else {
                    itr->next_node = new Trie();
                    itr = itr->next_node;
                }
            }
        }

        std::cout << "inserting charcter -" << name[i] << " at position- " << name[i] - 'a'<<  endl;
        std::cout << "marking this charcter -" << name[i] << " as end" << endl;
        (*node)->collection[name[i]-'a'] = 1;
        (*node)->delimiter[name[i]-'a'] = true;
    }


void PrintTrie(Trie *node ){

while(node){


    for (int i = 0 ; i < 26 ; i++){
        if(node->collection[i] == 1)
        std::cout << i <<" " <<node->collection[i] << endl;
    }
    node = node->next_node;

}

}





bool Search(Trie *node , string name ){

    if (!node){
        std::cout << "returning false because of null head of trie" << endl;    
        return false;
    }
    int i = 0 ;
    for (; i < name.size()-1 ; i++){
        
        if (!node){
            std::cout << "returning false because coming next level node is null" << endl;    
            return false;
        }
        if(node->collection[name[i]-'a'] == 1){
            std::cout << "character : " << name[i] << " is matching" << endl;
            node = node->next_node;
        } 
        else{
            std::cout << "returning false because charcter : - "<< name[i] << " does not match" << endl;
            return false;
        }
    }

    std::cout << "checking for last charcter :- " << name[i] << endl;
    if (node->collection[name[i]-'a'] == 1 && node->delimiter[name[i] - 'a'] == true){
        std::cout << "match has been found" << endl;
        return true;
    }
    
    std::cout << "last charcter match not found" << endl;
    return false;
}

int main() {

Trie *head = new Trie();
//Trie main_head = &head ;
string s1 = "abhinav";
//string s2 = "tarun";
insert(&head , s1);
//insert(head , s2);

PrintTrie(head);


// if (Search(head , s1))
//     cout << s1 << "is present " << endl;
// else 
//     cout << s1 << "is not present " << endl;

}