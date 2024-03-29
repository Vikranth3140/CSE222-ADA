#include <bits/stdc++.h>
#include <stack>

void topological_sort(int node,stack<int> &st, vector<int> &visited,vector<int> adj[]){
    visited[node]=1;
    for(auto i: adj[node]){
        if(visited[i]==0){
            topological_sort(i,st,visited,adj);
        }
    }
    st.push(node);
    return;
}

void findCutNodes(int node,vector<int> &start,vector<int> &end,vector<int> &cut_nodes,vector<int> adj[]){
    start[node]=1;
    for(auto i: adj[node]){
        if(start[i]==0){
            findCutNodes(i,start,end,cut_nodes,adj);
        }
        else if(start[i]==1 && end[i]==0){
            cut_nodes.push_back(i);
        }
    }
    end[node]=1;

    return;
}

int main(){
    vector<int> visited_topo(n,0);
    vector<int> adj[n];
    stack<int> st;

    // Assume nodes from 0 to n-1
    for(int i=0;i<=n-1;i++){
        if(visited_topo[i]==0){
            topological_sort(i,st,visited_topo,adj);
        }
    }

    // Stack now has topologically sorted vertices.
    vector<int> start(n,0);
    vector<int> end(n,0);
    vector<int> cut_nodes;

    while(!st.empty()){
        int node=st.top();
        st.pop();
        if (start[node]==0){
            findCutNodes(node,start,end,cut,adj);
        }
    }

    // Cut_nodes stroes answer.
    return 0;
}