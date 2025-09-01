#pragma once
#include <vector>

namespace trace {
struct UFDS {
  std::vector<int> p, r;
  explicit UFDS(int n=0): p(n), r(n,0) { for (int i=0;i<n;++i) p[i]=i; }
  int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
  void unite(int a,int b){
    a=find(a); b=find(b);
    if (a==b) return;
    if (r[a]<r[b]) std::swap(a,b);
    p[b]=a; if (r[a]==r[b]) ++r[a];
  }
};
} // namespace trace
