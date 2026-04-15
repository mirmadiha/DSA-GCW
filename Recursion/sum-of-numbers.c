 #include<stdio.h>
 int sumOfNumbers(int n){
    if(n==0){
        return n;
    }
    return n+sumOfNumbers(n-1);
 }
 
 
 int main() {
    int n;

    printf("Enter the value : ");
    scanf("%d", &n);

    printf("The sum of numbers is :");
    printf("%d\n", sumOfNumbers(n));

    return 0;
}