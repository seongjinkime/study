/*This Program demonstrate pointer's operator
 Written by : seongjin.kim
 Date : 2019.09.08
 
 */

#include <iostream>

using namespace std;

int main(void){
    char buf[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char* ptr = buf;
    
    cout << "Ptr increment" << endl;
    for(int i = 0 ; i < 6 ; i++){
        printf("ptr : 0x%p, *ptr : %C\n", ptr, *ptr);
        ptr++;
    }
    
    
    printf("ptr is buf...\n");
    ptr = buf;
    
    printf("ptr : 0x%p, *ptr : %c\n", ptr, *ptr++);
    printf("ptr : 0x%p, *ptr : %c\n", ptr, *(ptr++));
    printf("ptr : 0x%p, *ptr : %c\n", ptr, (*ptr)++);
    //printf("ptr : 0x%p, *ptr : %C\n", ptr, *(ptr+=2));
    ptr -= 1;
    printf("ptr : 0x%p, *ptr : %C\n", ptr, *(ptr+=2));
    printf("ptr : 0x%p, *ptr : %C\n", ptr, *(ptr+=1));
    
    return 0;
}
