#include<stdio.h>
int main(){
    int n, k, bill[100000], b, actual = 0;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d ", &bill[i]);
        actual += bill[i];
    }
    scanf("%d", &b);
    
    actual -= bill[k];
    actual = actual/2;

    if(actual == b){
        printf("Bon Appetit");
    }
    else if(actual<b){
        printf("%d", b - actual);
    }
    return 0;
}