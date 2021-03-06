#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

// ----- ReadGraph -----
// Referring to ymatsux-san's source code: https://atcoder.jp/contests/abc138/submissions/7016619

struct Edge
{
  int src, dst, id;
  // ll cost;
  Edge() {}
  Edge(int src, int dst, int id) : src{src}, dst{dst}, id{id} {}
  // Edge(int src, int dst, ll cost) : src{src}, dst{dst}, cost{cost} {}

  void added_edge(vector<vector<Edge>> &V)
  {
    V[src].push_back(*this);
  }

  void added_rev(vector<vector<Edge>> &V)
  {
    V[dst].push_back(rev());
  }

  Edge rev()
  {
    Edge edge{*this};
    swap(edge.src, edge.dst);
    return edge;
  }
};

tuple<vector<vector<Edge>>, vector<Edge>> ReadGraphWithEdges(int N, int M, bool is_undirected = true, bool is_one_indexed = true)
{
  vector<vector<Edge>> V(N);
  vector<Edge> E(M);
  for (auto i = 0; i < M; ++i)
  {
    int v, w;
    cin >> v >> w;
    if (is_one_indexed)
    {
      --v;
      --w;
    }
    Edge edge{v, w, i};
    edge.added_edge(V);
    if (is_undirected)
    {
      edge.added_rev(V);
    }
    E.push_back(edge);
  }
  return make_tuple(V, E);
}

vector<vector<Edge>> ReadGraph(int N, int M, bool is_undirected = true, bool is_one_indexed = true)
{
  return get<0>(ReadGraphWithEdges(N, M, is_undirected, is_one_indexed));
}

tuple<vector<vector<Edge>>, vector<Edge>> ReadTreeWithEdges(int N)
{
  return ReadGraphWithEdges(N, N - 1);
}

vector<vector<Edge>> ReadTree(int N)
{
  return ReadGraph(N, N - 1);
}
