#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N,M;

vector<pair<double, pair<int,int> > > E;
vector<pair<int,int> > coord;
vector<pair<int,int> > old;

int arr[1050];

double findDist(int x1,int y1,int x2, int y2){
    long double d1 = (x1 - x2)*(x1-x2);
    long double d2 = (y1 - y2)*(y1-y2);

    double dist = sqrt(d1+d2);

    return dist;
}

int find(int idx){
    if(arr[idx] == idx) return idx;

    return arr[idx] = find(arr[idx]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if ( a == b) return;

    arr[a] = b;
}

bool isSame(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        int from, to;
        cin >> from >> to;
        coord.push_back(make_pair(from,to));
    }
    for(int i=0; i<N; i++){
        arr[i] = i;
    }
    for(int i=0; i<M; i++){
        int from,to;
        cin >> from >> to;
        if(!isSame(from,to))
            merge(from-1,to-1);
    }
    
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            double dist = findDist(coord[i].first,coord[i].second, coord[j].first,coord[j].second);
            E.push_back(make_pair(dist, make_pair(i,j)));
        }
    }

    sort(E.begin(),E.end());

    double ans = 0.0;

    for(int i=0; i<E.size(); i++){
        if(!isSame(E[i].second.first,E[i].second.second)){
            merge(E[i].second.first,E[i].second.second);
            ans += E[i].first;
        }
    }
    cout<< fixed;
    cout.precision(2);
    cout << ans << '\n';

}
// #include<iostream>
// #include<vector>
// #include<cmath>
// #include<algorithm>
 
// #define endl "\n"
// #define MAX 1010
// using namespace std;
 
// int N, M;
// int Parent[MAX];
// double Answer;
// vector<pair<int, int> > Coord;
// vector<pair<int, int> > Connect;
// vector<pair<double, pair<int, int> > > Edge;
 
// void Input()
// {
//     cin >> N >> M;
//     for (int i = 1; i <= N; i++) Parent[i] = i;
//     for (int i = 0; i < N; i++)
//     {
//         int a, b; cin >> a >> b;
//         Coord.push_back(make_pair(a, b));
//     }
//     for (int i = 0; i < M; i++)
//     {
//         int a, b; cin >> a >> b;
//         Connect.push_back(make_pair(a, b));
//     }
// }
 
// int Find_Parent(int A)
// {
//     if (A == Parent[A]) return A;
//     return Parent[A] = Find_Parent(Parent[A]);
// }
 
// bool Same_Parent(int A, int B)
// {
//     A = Find_Parent(A);
//     B = Find_Parent(B);
//     if (A == B) return true;
//     return false;
// }
 
// void Union(int A, int B)
// {
//     A = Find_Parent(A);
//     B = Find_Parent(B);
//     Parent[B] = A;
// }
 
// double Find_Distance(int x, int y, int xx, int yy)
// {
//     double dx = pow(x - xx, 2);
//     double dy = pow(y - yy, 2);
//     double Dist = sqrt(dx + dy);
 
//     return Dist;
// }
 
// void Solution()
// {
//     for (int i = 0; i < M; i++)
//     {
//         int N1 = Connect[i].first;
//         int N2 = Connect[i].second;
 
//         if (Same_Parent(N1, N2) == false) Union(N1, N2);
//     }
//     for (int i = 0; i < N - 1; i++)
//     {
//         int x = Coord[i].first;
//         int y = Coord[i].second;
//         for (int j = i + 1; j < N; j++)
//         {
//             int xx = Coord[j].first;
//             int yy = Coord[j].second;
 
//             double Dist = Find_Distance(x, y, xx, yy);
//             Edge.push_back(make_pair(Dist, make_pair(i + 1, j + 1)));
//         }
//     }
//     sort(Edge.begin(), Edge.end());
//     for (int i = 0; i < Edge.size(); i++)
//     {
//         int N1 = Edge[i].second.first;
//         int N2 = Edge[i].second.second;
//         double Dist = Edge[i].first;
 
//         if (Same_Parent(N1, N2) == false)
//         {
//             Union(N1, N2);
//             Answer = Answer + Dist;
//         }
//     }
//     cout << Answer << endl;
// }
 
// void Solve()
// {
//     Input();
//     Solution();
// }
 
// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cout << fixed;
//     cout.precision(2);
 
//     //freopen("Input.txt", "r", stdin);
//     Solve();
 
//     return 0;
// }


