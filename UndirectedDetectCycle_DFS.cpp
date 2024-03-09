#include<iostream>
#include<vector>
using namespace std;

bool isCyclicUtil(int node , vector<bool> &visited , vector<int> adj[] , int parent){

    visited[node] = true;

    for(auto adj_node : adj[node]){

        if(!visited[adj_node]){
            if(isCyclicUtil(adj_node , visited , adj , node))
                return true;
        }
        else if(parent != adj_node)
            return true;
    }

    return false;
}


bool isCycle(int V , vector<int> adj[]){

    vector<bool> visited(V , false);
    for(int i = 0 ; i < V ; i++){
        if(!visited[i])
            if(isCyclicUtil(i , visited , adj, -1))
                return true;

    }

    return false;
}



int main(){


}