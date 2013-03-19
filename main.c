#include"stack.h"

#define STACK_SIZE 4

int main(){
	stack s;

	init( &s , STACK_SIZE );

	print_index( s );
	push( &s , STACK_SIZE ,14);
	print_index( s );
	push( &s, STACK_SIZE ,-9);
	print_index( s );
	push( &s , STACK_SIZE ,-9);
	push( &s , STACK_SIZE ,-9);
	push( &s , STACK_SIZE ,-9);

	print_stack(s);
	print_array_of_stack(s);
	printf("Min val : %d \n", min( s ) );

	printf(" Val popped,stack_index, ptr_index : %d %d %d\n" , pop( &s , STACK_SIZE ) , s.stack_index , s.stack_pointers_index );
	print_index( s );


	print_stack(s);
	print_array_of_stack(s);
	printf("Min val : %d \n", min( s ) );
	printf(" Val popped,stack_index, ptr_index : %d %d %d\n" , pop( &s , STACK_SIZE ) , s.stack_index , s.stack_pointers_index );
	print_index( s );


	print_stack(s);
	print_array_of_stack(s);
	printf("Min val : %d \n", min( s ) );
	printf(" Val popped,stack_index, ptr_index : %d %d %d\n" , pop( &s , STACK_SIZE ) , s.stack_index , s.stack_pointers_index );


	print_stack(s);
	print_array_of_stack(s);
	printf("Min val : %d \n", min( s ) );



	/*
	printf(" %d " , pop( &s ) );
	printf(" %d " , min( s ) );
	*/

return 0 ;

}
