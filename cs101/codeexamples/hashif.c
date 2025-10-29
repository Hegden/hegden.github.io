/* CS101: code to demonstrate the use of preprocessor directive #if
 * Author: Nikhil Hegde
 */
#include<stdio.h>
#define CONSTEXPR -1 
#define CONSTEXPR2 200
int main(){
//one use of #if. A #if needs to have a matching #endif. Any code in between gets compiled only if the identifier specified with #if is non-zero.
#if CONSTEXPR
	printf("Hello World\n");
#endif

	//another use of #if. here instead of an identifier, we have a condition.
#if CONSTEXPR2 == 201
	printf("Hello World Again\n");
#endif
}

/* TODO:
 * 1) comment the line #define CONSTEXPR 1 and type blah in from of printf("Hello World\n");. Recompile. Does the compilation go through?
 * 2) Now uncomment the previously commented line. Recompile. Does the compilation fo through? 
 * 3) Change 201 to 200. Recompile and rerun. What do you see?
 * Also discussed in class:
 * what is meant by conditional compilation?
 * when conditional compilation us used? e.g. if you want to include in one piece of code two versions of an algorithm implementation: one for Intel machines and one for ARM machines. */
