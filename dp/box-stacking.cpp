// https://practice.geeksforgeeks.org/problems/box-stacking/1
#include <bits/stdc++.h>
using namespace std;

struct Box{
  int d, w, h;
};

void augmentBoxes(const Box* S, int n, Box *D){
  // keep d >= w

  int d = 0;
  for(int s=0; s<n; s++){
    D[d].d = max(S[s].d, S[s].w);
    D[d].w = min(S[s].d, S[s].w);
    D[d].h = S[s].h;
    d++;

    D[d].d = max(S[s].d, S[s].h);
    D[d].w = min(S[s].d, S[s].h);
    D[d].h = S[s].w;
    d++;

    D[d].d = max(S[s].h, S[s].w);
    D[d].w = min(S[s].h, S[s].w);
    D[d].h = S[s].d;
    d++;
  }
};

bool compBox(Box A, Box B){
  return (A.d * A.w > B.d * B.w);
};

int maxHeightSubseq(const Box* B, int n){
  // Variation of LIS
  int T[n];
  int ori = -1;

  for(int x=0; x<n; x++){
    T[x] = B[x].h;
    for(int y=0; y<x; y++)
      if(
        B[y].d > B[x].d &&
        B[y].w > B[x].w
      )
        T[x] = max(T[x], B[x].h + T[y]);

    ori = max(ori, T[x]);
  }

  return ori;
};

// geeksforgeeks submit
int maxHeight(int height[], int width[], int length[], int n){
  Box B[n];
  for(int i=0; i<n; i++){
    B[i].h = height[i];
    B[i].w = width[i];
    B[i].d = length[i];
  }

  Box A[3*n]; // Augmented boxes
  augmentBoxes(B, n, A);

  sort(A, A + 3*n, compBox);

  return maxHeightSubseq(A, 3*n);
}

int main(){
  int t, n;
  scanf("%d\n", &t);

  while(t--){
    scanf("%d\n", &n);

    Box B[n];
    for(int i=0; i<n; i++)
      scanf("%d %d %d", &B[i].d, &B[i].w, &B[i].h);

    Box A[3*n]; // Augmented boxes
    augmentBoxes(B, n, A);

    sort(A, A + 3*n, compBox);

    //debug
    // for(int i=0; i<3*n; i++)
    //   printf("[%d %d %d]", A[i].d, A[i].w, A[i].h);
    // printf("\n");

    printf("%d\n", maxHeightSubseq(A, 3*n));
  }
}