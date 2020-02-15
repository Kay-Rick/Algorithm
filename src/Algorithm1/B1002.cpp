#include<stack>
#include<cstring>
#include<iostream>
using namespace std;

void print(int n);
/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Date: 2020-02-15 16:47:01
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2020-02-15 17:00:59
 * @Description: PATB1002 (PAT已经不支持gets()函数)
 */

int main(void)
{
    int sum = 0;
    char str[110];
    stack<int> s;
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        sum += str[i] - '0';
    }
    while (sum != 0)
    {
        s.push(sum % 10);
        sum /= 10;
    }

    while (!s.empty() && s.size() > 1)
    {
        print(s.top());
        printf(" ");
        s.pop();
    }
    print(s.top());
    return 0;
}


void print(int n){
    switch (n)
    {
    case 0:
        printf("ling");
        break;
    case 1:
        printf("yi");
        break;
    case 2:
        printf("er");
        break;
    case 3:
        printf("san");
        break;   
    case 4:
        printf("si");
        break; 
    case 5:
        printf("wu");
        break; 
    case 6:
        printf("liu");
        break; 
    case 7:
        printf("qi");
        break; 
    case 8:
        printf("ba");
        break; 
    case 9:
        printf("jiu");
        break;  
    default:
        break;
    }
}