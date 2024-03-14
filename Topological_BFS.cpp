#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &adj , int V){

    vector<int> indegree(V);

    for(int i = 0 ; i < V ; i++){
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0 ;  i < V ; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> result;
    while(!q.empty()){

        int node = q.front();
        q.pop();
        result.push_back(node);

        // decrease indegree of adjacent nodes as the 
        // current node is in topological order

        for(auto it : adj[node]){
            indegree[it]--;
        

            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    if(result.size() != V){

        cout << "Graph contains cycle!" << endl;
        return {};

    }

    return result;

}

int main(){

    // Number of nodes
    int n = 4;
 
    // Edges
    vector<vector<int>> edges = { { 0, 1 }, { 1, 2 }, { 3, 1 }, { 3, 2 } };
 
    // Graph represented as an adjacency list
    vector<vector<int> > adj(n);
 
    // Constructing adjacency list
    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }

    cout << "topological sorting of the graph" << endl;

    vector<int> result = topologicalSort(adj , n );

    // Displaying result
    for(auto i : result){
        cout << i << " " ;
    }

    return 0;

}