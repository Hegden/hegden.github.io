/* CS101C: code example to demonstrate passing of structure variables in C.
 * author: Nikhil Hegde */
#include<stdio.h>
#include<string.h>
//below is the definition of a structure. note the keyword struct, curly braces, and semicolon. 
struct student{
	char name[96]; //note that the size of a struct is the sum of the sizes of individual numbers rounded off to nearest multiple of 4. 
	int branch;
	float cpi;
};

//below function modifies the cpi field of a struct student variable. This function is an example of call-by-reference.  
void cpimodifier(struct student* s){
	(*s).cpi=5.0; //note that we can use s->cpi=5.0 as well
	return;
}

int main(){
	//below is an example of an array of structure: students is an array of struct student of size 2.
	struct student students[2];

	//below code accepts user input and writes them into the fields of struct student array elements. You can uncomment this code and enter input from terminal.
	/*printf("Enter student details (name, branch, cpi)\n");
	for(int i=0;i<2;i++){
		//note. you can also write this line as: scanf("%s",&students[i].name); However, you get a warning.
		//The reason is that the type of students[i].name is "char [96]". When you say &students[i].name, you are
		//trying to get the address and so the address must be stored in a pointer variable of type char (*)[96].
		//However, %s in scanf expects a "char *" argument. 
		//If you pass the argument as students[i].name, then because array name is synonymous with the address of the first element of the array, no warning is seen.
		//we satisfy 
		scanf("%s",students[i].name);  
		scanf("%d",&students[i].branch);
		scanf("%f",&students[i].cpi);
	}*/
	//below code writes to the cpi field of the struct student variable (first element of the array) 
	students[0].cpi=10.0;
	printf("gpa of student[0] (before calling gpamodifier): %f\n",students[0].cpi);

	//print the size of the struct student. Uncomment this line to see the size.
	//printf("size of struct student: %zu\n",sizeof(struct student));
	
	//call the function cpimodifier and pass the first element of the array students. The first element is of type struct student. We need to pass the address of this.
	//hence, we pass &students[0]
	cpimodifier(&students[0]);

	//print the modified cpi.
	printf("gpa of student[0] after: %f\n",students[0].cpi);

}


