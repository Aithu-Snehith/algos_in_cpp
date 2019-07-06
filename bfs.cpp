// run as "g++ -std=c++11 bfs.cpp"

#include<bits/stdc++.h>
using namespace std;

vector<bool> node_visited;
vector<vector <int> > graph;

void edge(int a, int b)
{
  graph[a].push_back(b);
  graph[b].push_back(a);
}

void bfs(int source)
{
  queue<int> q;

  q.push(source);
  node_visited[source] = true;

  while(!q.empty())
  {
    int f = q.front();

    q.pop();
    cout << f << ' ';

    for(auto i = graph[f].begin(); i != graph[f].end(); i++)
    {
      if(!node_visited[*i])
      {
        q.push(*i);
        node_visited[*i] = true;
      }
    }
  }
}

int main()
{
  int vertices = 9, edges = 8;

  node_visited.assign(vertices, false);
  graph.assign(vertices, vector<int>());

  edge(2,3);
  edge(3,7);
  edge(1,3);
  edge(3,6);
  edge(1,5);
  edge(5,4);
  edge(0,5);
  edge(5,8);

  bfs(0);
  cout << '\n';
}
