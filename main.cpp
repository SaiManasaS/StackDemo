/* Copyright (C) 2020 Sai Manasa S
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Description: This is a program used to demo CPP class, C structure
 *              and the stack data structure operations
 *
 * Revision History:
 * Initial version: Oct 11th, 2020
 * Fixed runtime error (pop() still has a bug: Oct 12th, 2020
 */

#include <iostream>
#define NULL 0

using namespace std;

typedef struct node
{
	int value;
	node* next_node;
};

int cstruct_stacksize(node *startnode)
{
	int c = 0;
	while(startnode->next_node != NULL)
	{
		c++;
		startnode++;
	}
	return c;
}

/*****************************************************/
// Function:     cstruct_stackpush()
// Description:  This function demos the stack push()
//               operation
// Inputs:       int inpushval
// Return value: None
/*****************************************************/
node* cstruct_stackpush(node* startnode, int inpushval)
{
	int c = 0;
	node* current_node = startnode;
	node* ret_start_node = startnode;

	// Create the first node
	if(current_node == NULL)
	{
		//cout << "\nFirst node" << endl;
		current_node = new node;
		current_node->value = inpushval;
		current_node->next_node = NULL;
		ret_start_node = current_node;
	}
	else
	{
		// Go to the next node
		while(current_node->next_node != NULL) //while(current_node->next_node)
		{
			current_node = current_node->next_node;
		}
		
		//cout << "\nNot First node" << endl;

		current_node->next_node = new node;
		current_node = current_node->next_node;
		current_node->value = inpushval;
		current_node->next_node = NULL;
	}
	cout << "\n\ncurrent_node->value: "   << current_node->value;
	cout << "\ncurrent_node->next_node: " << current_node->next_node;
	return ret_start_node;
}

void cstruct_stackdisp(node* start_node)
{
	node* current_node = start_node;
	cout << "\nInside cstruct_stackdisp()" << endl;

	/*
	cout << "current_node->value" << current_node->value;
	cout << "current_node->next_node" << current_node->next_node;
	*/

	while(current_node)
	{ 
		cout << "\nNode value: " << current_node->value << " ";
		current_node = current_node->next_node;
	}
}

/*****************************************************/
// Function:     cstruct_stackpop()
// Description:  This function demos the stack pop
//               operation
// Inputs:       None
// Return value: int 
/*****************************************************/
int cstruct_stackpop(node* startnode)
{
	node* current_node = startnode;
	node* prev_node = NULL;
	int ret_val = -1;

	if(current_node != NULL)
	{
		cout << "\n current_node->value" << current_node->value << endl;
		cout << "\n current_node->next_node" << current_node->next_node << endl;

		while(current_node->next_node != NULL)
	    {
		    prev_node = current_node;
		    current_node = current_node->next_node;
	    }

	    ret_val = current_node->value;
		current_node = NULL;
	    delete(current_node);

	    if(prev_node != NULL)
	    {
			prev_node->next_node = NULL;
	    }
	}
	else
	{
		cout << "Stack is empty! Cannot pop!" << endl;
	}
	
	return ret_val;
}

/*****************************************************/
// Function:     cstruct_demostack()
// Description:  This function demos the various ways
//               of assignment to string type variables
// Inputs:       in_t1 and in_t2 of type class_ticket
// Return value: None
/*****************************************************/
void cstruct_demostack()
{
	node* stack_bottom = NULL, * curr_node = NULL;
	node* ret_start_node = NULL;

	ret_start_node = cstruct_stackpush(ret_start_node, 10);
	ret_start_node = cstruct_stackpush(ret_start_node, 19);
	ret_start_node = cstruct_stackpush(ret_start_node, 28);
	ret_start_node = cstruct_stackpush(ret_start_node, 37);
	ret_start_node = cstruct_stackpush(ret_start_node, 46);
	cout << "\nret_start_node->value: " << ret_start_node->value;
	
	//curr_node = ret_start_node;
	//cout << "ret_start_node->next_node->value: " << ret_start_node->next_node->value ;

	//curr_node = ret_start_node;

	cstruct_stackdisp(ret_start_node);
	cout << "\n cstruct_stackpop(): " << cstruct_stackpop(ret_start_node) << endl;
	cout << "\n cstruct_stackpop(): " << cstruct_stackpop(ret_start_node) << endl;
	cout << "\n cstruct_stackpop(): " << cstruct_stackpop(ret_start_node) << endl;
	cout << "\n cstruct_stackpop(): " << cstruct_stackpop(ret_start_node) << endl;
	cout << "\n cstruct_stackpop(): " << cstruct_stackpop(ret_start_node) << endl;
	cout << "\n cstruct_stackpop(): " << cstruct_stackpop(ret_start_node) << endl;
	cout << "\n cstruct_stackpop(): " << cstruct_stackpop(ret_start_node) << endl;
}

/*****************************************************/
// Function:     cppclass_demostack()
// Description:  This function demos the various ways
//               of assignment to string type variables
// Inputs:       in_t1 and in_t2 of type class_ticket
// Return value: None
/*****************************************************/
void cppclass_demostack()
{

}

/*****************************************************/
// Function:     main()
// Description:  This is the main() function for entry
//               into program execution
// Inputs:       None
// Return value: None
/*****************************************************/
void main()
{
	cstruct_demostack();
	while(1);
}
