#include <iostream>
using namespace std;

int T, n;

int calc_shorted_path(int n){
  if(n == 1)
    return 0;
  else if((n % 3) != 0)
    return calc_shorted_path(n - 1) + 1;
  else
    return calc_shorted_path(n / 3) + 1;
}

int main(){
  cin >> T;
  for(int i=0; i<T; i++){
    cin >> n;

    cout << calc_shorted_path(n) << endl;
  }
  return 0;
}

//1:0
//2:1
//3:1
//4:2
//5:3
//6:2
//7:3
//8:4
//9:2
//10:3
//11:4
//12:3
