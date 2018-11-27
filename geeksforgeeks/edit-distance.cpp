#include <bits/stdc++.h>
#define INF 99999
using namespace std;

int n_cases, size_0, size_1;
string str_0, str_1;

class EditDistance{
  public:
    string str_0, str_1;
    int size_0, size_1;
    int** mem;

    EditDistance(string str_0, string str_1, int size_0, int size_1);
    int costDoNothing(int i, int j);
    int costInsert(int i, int j);
    int costRemove(int i, int j);
    int costReplace(int i, int j);
    int solve();
    void printMem();
};

EditDistance::EditDistance(string str_0, string str_1, int size_0, int size_1){
  this->str_0 = str_0;
  this->str_1 = str_1;
  this->size_0 = size_0;
  this->size_1 = size_1;
};

int EditDistance::costDoNothing(int i, int j){
  if(str_0[i] == str_1[j])
    return 0;
  return INF;
};

int EditDistance::costInsert(int i, int j){
  if(str_0[i] == str_1[j])
    return INF;
  return 1;
};

int EditDistance::costRemove(int i, int j){
  return costInsert(i, j);
};

int EditDistance::costReplace(int i, int j){
  return costInsert(i, j);
};

int EditDistance::solve(){
  // int mem[size_0+1][size_1+1];
  mem = new int*[size_0+1];

  for(int i=size_0; i>=0; i--){
    mem[i] = new int[size_1+1];

    for(int j=size_1; j>=0; j--){

      if(i == size_0 && j == size_1)
        mem[i][j] = 0;

      else if(i == size_0)
        mem[i][j] = size_1 - j;

      else if(j == size_1)
        mem[i][j] = size_0 - i;

      else{
        mem[i][j] = min({
          costDoNothing(i, j) + mem[i+1][j+1],
          costInsert(i, j) + mem[i][j+1],
          costRemove(i, j) + mem[i+1][j],
          costReplace(i, j) + mem[i+1][j+1]
        });
      }
    }
  }

  return mem[0][0];
};

void EditDistance::printMem(){
  for(int i=0; i<=size_0; i++){
    for(int j=0; j<=size_1; j++){
      printf("%02d ", mem[i][j]);
    }
    printf("\n");
  }
};

int main(){
  scanf("%d\n", &n_cases);

  while(n_cases--){
    scanf("%d %d\n", &size_0, &size_1);
    getline(cin, str_0, ' ');
    getline(cin, str_1);

    EditDistance ed(str_0, str_1, size_0, size_1);
    printf("%d\n", ed.solve());
    // ed.printMem();
  }

  return 0;
}