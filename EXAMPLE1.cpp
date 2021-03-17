#include <iostream>
using namespace std;

int main() {
    int  a = 45;
    int h = 6;
    string b = to_string(a);
    cout << "数字整型转成数字string型: "<< b << endl;     /* 45 */
    cout << "数字整型转成数字char型: " << char(h + '0') << endl;  /* char型6  '0'的ascii值是48加上6=54是'6'的ascii值 */
    
    string s = "98"; 
    int a2 = stoi(s.c_str());
    cout << "数字string型转成数字整型: "<< a2 << endl;   /* 98 */
    
    char af = '4';
    cout << "数字char型转成数字整型: " << af - '0' << endl;    /* 4 */
    cout << "数字char型转成ascii值: " << int(af) << endl;   /* 52 */
    
    
    char a3 = 'r';
    int b3 = a3 - NULL;  /* 114-0  */
    int b4 = int(a3);
    int b5 = a3 - 0;  
    char c3 = char(b3);  /* ascii值范围内 */
    cout << "字母字符型转成整型: "<< b3 << endl;   /* 114  */
    cout << "字母字符型转成整型: "<< b4 << endl;   /* 114  */
    cout << "字母字符型转成整型: "<< b5 << endl;    /* 114 */
    cout << "字母整型转成字符型: "<< c3 << endl;   /* r  */
    
    return 0;
}