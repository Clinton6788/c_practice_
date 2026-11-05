#include <stdio.h>

int main(void){
	int nums[5] = {1,2,3,4,5};
	int *ptr = nums;

	for(int i = 0; i <=4; i++){
		printf("Index val: %d\n", nums[i]);
	}

	// Print using pointer arithmetic
	int loop = 0;
	while(loop <=4){
		printf("Pointer Arithmetic: %d\n", *(ptr + loop));
		loop++;
	}

	// Change third value to 100 using pointer
	*(ptr + 2) = 100;

	printf("-----New array Values-----");
	for(int i = 0; i <=4; i++){
		printf("%d\n", nums[i]);
	}

	printf("%zu\n", sizeof(nums));
	printf("%zu\n", sizeof(nums[0]));

}
