#include <stdio.h>
#include <string.h>
using namespace std;

int res = 0;

int recursion(const char *s, int l, int r){
    ++res;
    
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main()
{
    int test, tmp;
    char input[1001] = {0, };
    
    scanf("%d", &test);
    while(test--)
    {
        scanf("%s", input);
        
        tmp = isPalindrome(input);
        
        printf("%d %d\n", tmp, res);
        
        res = 0;
    }
    
    return 0;
}
