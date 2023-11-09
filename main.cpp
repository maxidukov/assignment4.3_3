#include <iostream>
#include <algorithm>

void count_sort(int*, int, int, int);

int main() {
  int aa[3][45] = {
     {19,14,22,22,17,22,13,21,20,24,18,10,17,16,17,20,22,11,20,16,14,13,10,22,18,14,16,24,19,17},
     {16,17,14,20,22,20,17,22,16,19,23,24,20,22,21,18,14,16,17,21,10,11,19,23,11,11,17,17,11,21,17,11,17,16,12,11,16,22,23,16},
     {21,15,19,18,23,12,18,18,19,23,12,20,15,22,21,18,19,20,12,16,20,14,17,13,10,23,19,14,10,22,19,12,24,23,22,15,13,22,18,18,11,23,24,17,10},
  };  //CLUMSY, MAKESHIFT C-STYLE JAGGED 2D ARRAY
  int asizes[3] = {30,40,45};
  int min = 10;
  int max = 24;
  //int a[] = {3,2,1};
  for(int j{};j<3;j++){
     std::cout<<"Исходный массив: ";
     for(int i{};i<asizes[j];i++){
        std::cout<<aa[j][i]<<" ";
     }
     std::cout << "\n";
     count_sort(aa[j],asizes[j],max,min);
     std::cout<<"Отсортированный массив: ";
     for(int i{};i<asizes[j];i++){
        std::cout<<aa[j][i]<<" ";
     }
     std::cout << "\n\n";
  }
}

void count_sort(int* a, int size, int max, int min = 0){
  //int mx = *std::max_element(a, a+size);
  int* counts = new int[max-min+1]();
  for(int i{};i<size;i++){
     counts[a[i]-min] += 1;
  }
  int c{};
  int i{};
  while(i<size){
    while(counts[c]){
       a[i++] = c + min;
       counts[c]--;
    }
    c++;
  }
  delete [] counts;
}

