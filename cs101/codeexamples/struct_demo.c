/* CS101C: code example to demonstrate structures in C.
 * author: Nikhil Hegde */
#include<stdio.h>
#include<string.h>
//below is the definition of a structure. note the keyword struct, curly braces, and semicolon. 
struct student{
	char name[100];
	int branch;
	float cpi;
};

//another struct definition.
struct personalinfo{
	int phone;
	char gender;
	float age;
};

//another struct definition to demonstrate nested structures. 
struct studentv2{
	char name[100];
	int branch;
	float cpi;
	struct personalinfo info;
};

int main(){
	//definition of a variable of type student
	struct student s1;
	//initialization (Writing to) of the fields of the struct student.
	//note the dot notation to access the fields.
	s1.branch=1;
	s1.cpi=2.5;
	//s1.name="Sam"; is this allowed? No. Why? "Sam" is a string constant and its type is char *. 
	//on the lhs we have s1.name, which is an array of characters and its type is char []. type mismatch between lhs and rhs.
	//so, one way to initialize the name field of s1 variable is:
	strcpy(s1.name, "Rama");
	printf("student name:%s student branch:%d student cpi:%f\n",s1.name, s1.branch, s1.cpi);
	//initialize the fields.
	struct personalinfo i1= {12345678,'M',45};
	printf("contact number:%d gender:%c age:%f\n",i1.phone, i1.gender, i1.age);
	//define a variable of type struct studentv2
	struct studentv2 s2;
	//write values into the info field of s2:
	s2.info=i1;
	//write other values into s2's info field. note the dot notation applied twice.
	s2.info.phone = 12345678;
}


