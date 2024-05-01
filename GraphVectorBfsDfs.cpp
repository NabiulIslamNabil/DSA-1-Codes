#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<iterator>

using namespace std;

void printGraph(vector<vector<int>> &graph){
    cout<<"The graph in adjacency matrix: "<<endl;
    for(int i=0; i<graph.size(); i++){
        for(int j=0; j<graph[i].size(); j++){
            cout<<graph[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void displayAdjList(list<int> adj_list[], int v){
    cout<<"The graph in adjacency list: "<<endl;
    for(int i=0; i<v; i++){
        cout<<" Vertex: "<< i+1 << " ---> ";
        list<int> :: iterator it;
        for(it = adj_list[i].begin(); it!= adj_list[i].end(); ++it){
            cout<< *it+1 <<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void addEdge(vector<vector<int>> &graph, list<int> adjList[], int u, int v){
    if((u>0 && v>0) && (u<=graph.size() && v<=graph.size())){
            graph[u-1][v-1] = 1;
            graph[v-1][u-1] = 1;
            adjList[u-1].push_back(v-1);
            adjList[v-1].push_back(u-1);
    }else{
        cout<<"Failed to add edge"<<endl;
    }
}

void BFS(list<int> adjList[], int start, int nodes) {
    vector<int> visited(nodes, 0);
    queue<int> q;

    visited[start-1] = true;
    q.push(start-1);

    cout << "BFS traversal starting from vertex " << start << ": ";
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x + 1 << " ";
        list<int>::iterator it;
        for (it = adjList[x].begin(); it != adjList[x].end(); ++it) {
            int y = *it;
            if (!visited[y]) {
                visited[y] = 1;
                q.push(y);
            }
        }
    }
    cout << endl;
}


void DFS(list<int> adjList[], int start, int nodes){
    stack<int> s;
    vector<int> visited(nodes, 0);
    list<int>::iterator it;

    visited[start-1] = 1;
    s.push(start-1);

    while(!s.empty()){
        int x = s.top();
        s.pop();
        cout<<x+1<<" ";
        for(it = adjList[x].begin(); it!=adjList[x].end(); it++){
            int y = *it;
            if(visited[y] == 0){
                visited[y] = 1;
                s.push(y);
            }
        }
    }
}


int main(){

    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    vector<vector<int>> adjMatrix(n, vector<int>(n,0));
    list<int> adjList[n];

    int edges;
    cout<<"Enter the number of edges: ";
    cin>>edges;

    for(int i=0; i<edges; i++){
        cout<<"Enter two nodes for edges: ";
        int u, v;
        cin>>u;
        cin>>v;
        addEdge(adjMatrix, adjList, u, v);
    }

    printGraph(adjMatrix);

    displayAdjList(adjList, n);

    int start;

    cout<<"BFS starts from: ";
    cin>>start;
    BFS(adjList, start, n);

    cout<<"DFS starts from: ";
    cin>>start;
    DFS(adjList, start, n);
}
