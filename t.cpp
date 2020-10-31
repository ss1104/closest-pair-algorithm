#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
double distt(int x1,int y1,int x2,int y2) // Find the distance between 2 points 
{
   x1=(double)x1,x2=(double)x2;
   y1=(double)y1,y2=(double)y2;
   return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
double base(int l,int r,vector<pair<int,int>> &v) // Base case
{
   double ans=20000000.00;
   for(int i=l;i<=r;i++)
   {
      for(int j=i+1;j<=r;j++)
        ans=min(ans,distt(v[i].first,v[i].second,v[j].first,v[j].second));
   }
   return ans;
}
double border_dist(vector<pair<int,int>> &border,double dis) // solve for the coordinates in 'Border' vector.
{
    int n=border.size();
    double d = 20000000.00;
    for(int i = 0;i<n;i++)
    {
       for(int j=i+1;j<n && (double)border[j].first-(double)border[i].first<=dis;j++)
          d=min(d,distt(border[i].second,border[i].first,border[j].second,border[j].first));
    }
    return d;
}
double solve(int l,int r,vector<pair<int,int>> &v,vector<pair<int,int>> &v1) // Driver function 
{
   int n = v.size();
   if(l<r)
   {
      int m = (l+r)/2;
      if(r-l<=2) return base(l,r,v);
      double leftmin = solve(l,m,v,v1);
      double rightmin = solve(m+1,r,v,v1);
      double mindist = min(leftmin,rightmin);
      vector<pair<int,int>> border;
      for(int i=0;i<n;i++)
      {
         if(fabs((double)v1[i].second-(double)v[m].first)<=mindist) 
            border.push_back({v1[i].first,v1[i].second});
      }
      double d = border_dist(border,mindist);
      return min(d,mindist);
   }
   return 2.00;
}
int main()
{
   fast();
   int t=1;
   cin>>t;
   while(t--)
   {
      int n;
      cin>>n;
      vector<pair<int,int>> v(n),v1(n);
      for(int i=0;i<n;i++) v[i].first = rand();
      for(int i=0;i<n;i++) v[i].second = rand();
      for(int i=0;i<n;i++) v1[i].first=v[i].second;
      for(int i=0;i<n;i++) v1[i].second=v[i].first;
      sort(v.begin(),v.end());
      sort(v1.begin(),v1.end());
      cout<<setprecision(15)<<solve(0,n-1,v,v1)<<endl;
   }
}