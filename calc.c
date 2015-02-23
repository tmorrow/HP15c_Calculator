/*
	Taylor Morrow
	
	Simulate a HP15c calculator
*/
	#include <stdio.h>
	#include <stdlib.h>

	#define MEM_SIZE 1000
	#define STACK_SIZE 100

	#define G	43					//G function key
	#define F   42					//F function key
	#define DIV 10					//Divide
	#define MUL 20					//Multiply
	#define SUB 30					//Subtraction
	#define RTN 32					//Return
	#define PSE 31 					//Pause
	#define ADD 40					//Addition
	#define STO 44					//Store
	#define RCL	45					//Recall
	#define ENT 36					//Enter


	char memory[MEM_SIZE];			//Holds the program's brain
	double stack[STACK_SIZE];		//Increments or decrements
	double register_set[20];		//Registered value placeholders
	int sp = -1;					//Stack pointer
	int pc = 0;						//Program counter
	int running = 1;				//Running flag
	int cpc;						//Copy of program counter

	void load(); 					//Load each text char into an int
	void run();						//Run the program
	void push(double n);			//Push onto the top of the stack
	double pop();					//Pop the top of the stack
	double top();					//Return the top of the stack

	int main(){
		load();
		run();
		return 0;
	}

	void load(){
		int input;						//Input from the file
		while(scanf("%d", &input) != EOF){
			memory[pc++] = input;
			cpc = pc;
		}
		pc = 0;							//Restart the pc to 0.
	}	

	void run(){
		while(cpc > pc && running){
			int val;					//Value to be evaluted for
			int x, y;					//temp variables to pull sp
			if(memory[pc] < 10){		//Check for double digit pc
				push(memory[pc]);
				pc++;
			}
			else{
				switch(memory[pc++]){
					case DIV: 			//Division (10)
						x = pop(); y = pop();
						val = y / x;
						push(val);
						break;
					case MUL:			//Multiplication (20)
						x = pop(); y = pop();
						val = x * y;
						push(val);
						break;
					case SUB:			//Subtraction (30)
						x = pop(); y = pop();
						val = y - x;
						push(val);
						break;
					case ADD:			//Addtion (40)
						val = pop() + pop();
						push(val);
						break;
					case STO:			//Store (44)
						val = top();
						x = memory[pc];
						register_set[x] = val;
						pc++;
						break;
					case RCL:			//Recall (45)
						x = memory[pc];
						val = register_set[x];
						push(val);
						pc++;
						break;
					case ENT:			//Enter (36)
						x = pop(); y = pop();
						y = y * 10;
						val = x + y;
						push(val);
						break;
					case G:
						switch(memory[pc]){
							case RTN:	//Return (32)
								running = 0;
								break;
						}
						break;
					case F:
						switch(memory[pc++]){
							case PSE:	//Pause (31)
								printf("The result is: %f\n", top());
								break;
						}
						break;
				}//end switch
			}//end else
		}//end while
	}

	void push(double n){
		double temp = n;
		sp++;
		stack[sp] = temp;			
	}

	double pop(){
		double temp;
		temp = stack[sp];
		sp--;
		return temp;
	}

	double top(){
		return stack[sp];
	}
	