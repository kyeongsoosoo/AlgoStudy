#include <iostream>

using namespace std;

int in[100001];
int idx[100001];
int post[100001];

void getPre(int in_start, int in_end, int post_start, int post_end){
    if(in_end < in_start) return;
    if(post_end < post_start) return;

    int root_idx = post[post_end];

    cout << root_idx << " ";

    if(in_end  == in_start) return;
    if(post_end  == post_start) return;

    int in_root = idx[root_idx];

    int left_size = in_root - in_start;
    int rightSize = in_end - in_root;

    getPre(in_start, in_root-1, post_start, post_start + left_size -1);
    getPre(in_root+1, in_end, post_start +left_size, post_end -1);
}


int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> in[i];
        idx[in[i]] = i;
    }
    for(int i=0; i<N; i++){
        cin >> post[i];
    }
    getPre(0, N-1, 0, N-1);
}