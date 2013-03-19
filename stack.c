#include"stack.h"

void init( stack *s, int stack_size  ) {
	s->array_as_stack=(int *)malloc( sizeof(int) * stack_size );

	s->stack_of_pointers=(int **)malloc( sizeof(int *) * stack_size );


	s->stack_index=s->stack_pointers_index=0;
}

/*********************************************************************/
void push( stack *s ,int stack_size , int val ){
	if( s->stack_index < stack_size ){
		s->array_as_stack[s->stack_index]=val;

		if( s->stack_index==0 ){

			s->stack_of_pointers[s->stack_pointers_index]= (s->array_as_stack) + s->stack_index ;

		}
		else if ( **( s->stack_of_pointers + s->stack_pointers_index ) >= val ){
			/*if the current val that we push is lesser than where the 
			 * top of stack_of_pointers is pointing, so update it 
			 */
			

			s->stack_of_pointers[s->stack_pointers_index+1]= (s->array_as_stack) + s->stack_index ;
			(s->stack_pointers_index)++ ;
			/*NOTE : no need to check on if the stack of array_of_pointers
			 * is overflowing, coz we are here after checking if original
			 * stack is overflowing or not.
			 */

		}

		(s->stack_index)++;

	}
	else{
		printf("Stack Overflowing !!\n");
	}


}


/*********************************************************************/
void print_stack( stack s ){
	int last=s.stack_index;

	printf("\n [ ");
	int i=0;
	for( ; i<last ; i++ )
		printf(" %d ", s.array_as_stack[i] );

	printf("] \n ");


}

/*********************************************************************/
void print_array_of_stack( stack s ){
	int last=s.stack_pointers_index+1;

	printf("\n [ ");
	int i=0;
	for( ; i<last ; i++ )
		printf(" %d ", *(s.stack_of_pointers[i])  );

	printf("] \n ");


}
/*********************************************************************/
int min( stack s){

	if( s.stack_pointers_index > -1  )
		return **( s.stack_of_pointers + s.stack_pointers_index );

	printf("**Stack Underflowing !! \n");
	//return -2343242;

}
/*********************************************************************/

int pop( stack *s , int stack_size ){
	if( s->stack_index > 0 ){
		--(s->stack_index );

		int val_to_be_popped = *(s->array_as_stack +  s->stack_index );

		if( val_to_be_popped == **( s->stack_of_pointers + s->stack_pointers_index ) )
			--(s->stack_pointers_index);

		return val_to_be_popped ;
	}
	else
		printf("Stack Underflowing !! \n");


}
/*********************************************************************/

void print_index( stack s ){
	printf("$$ stack index & pointer index : %d %d \n", s.stack_index , s.stack_pointers_index );

}
