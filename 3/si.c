#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int * create_array(int size){
    int res;
    int * array = calloc(size, sizeof(int));
    assert(array);

    for(int i=0; i < size; i++){
        res=scanf("%d", &array[i]);
        assert(res == 1);        
    }
    return array;
}

void print_array(int *inp, unsigned int size){
    for (int i = 0; i < size; i++)
        printf("%d ", inp[i]);    
}
int moveright(int *arr, int key, int last);
void inssort(int *arr, int len) {
  int i;
  for (i = 0; i < len; ++i) {
    int key, pos;
    key = arr[i];
    pos = moveright(arr, key, i);
    arr[pos] = key;
  }
}
int moveright(int *arr, int key, int last) {

    while (last > 0 && arr[last - 1] > key)
    {
        arr[last] = arr[last - 1];
        last--;
    }
  return last;
}
int main(){
    int res;
    unsigned size = 0;
    res = scanf("%u", &size);
    if (size == 0)
    {
        printf("0");
        return 0;
    }
    int *inp = create_array(size);
    inssort(inp, size);
    print_array(inp, size);    
    free(inp);
}