#include "../SegTree.cpp"

#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F&lang=ja"

int main()
{
  int N;
  cin >> N;
  auto tree{RangeMinQuery<int, int>(N)};
  int Q;
  cin >> Q;
  for (auto q{0}; q < Q; ++q)
  {
    int t;
    cin >> t;
    if (t == 0)
    {
      int s, t, x;
      cin >> s >> t >> x;
      tree.update(s, t + 1, x);
    }
    else
    {
      int s, t;
      cin >> s >> t;
      cout << tree.query(s, t + 1) << endl;
    }
  }
}
