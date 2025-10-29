/* CS101: code to demonstrate the use of preprocessor directive #ifdef
 * Author: Nikhil Hegde
 */
#include<stdio.h>

#define CONSTEXPR
int main(){
#ifdef CONSTEXPR
	printf("Hello World\n");
#endif
}
