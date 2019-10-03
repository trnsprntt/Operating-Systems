#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1 = 0;
	scanf("%d", &n1);

	//Create a new array of n1 ints
	int* a1 = malloc(n1*sizeof(int)); /* Fill in*/
	for (int i = 0; i < n1; ++i)
	{
		printf("%d ", a1[i]);
	}
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i] = 100;
		printf("%d ", a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);
	//Dynamically change the array to size n2
	free(a1);
	a1 = malloc(n2*sizeof(int));/* Fill in*/

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
	printf("\n");

	//Done with array now

	return 0;
}
