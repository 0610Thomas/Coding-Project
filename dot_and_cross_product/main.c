#include <stdio.h>

float dotProduct(float *firstVector, float flength, float *secondVector, float slength) {

        float answer = 0.0;
        int sf = flength; // sizeof(firstVector);
        int ss = slength; //sizeof(secondVector); //Had firstVector instead of secondVector

        //Problem: both sf and ss return the max size of a float array, or 8 as a result of the sizeof method.
        // Solution: one way is to have the length fixed.
        printf("%i sf %i ss\n", sf, ss);

	//checks if the size of both vectors is the same, if not, returns 0
        if(sf != ss){ 
	//a zero vector is a legitimate answer that is not the same as No solution
	// So, print that there is no solution
                printf(“No solution\n”;)
                return 0.0;

        } 
        //returns dot product
        for(int i = 0; i < 3; i++) {
        answer += firstVector[i] * secondVector[i];
        }
        return answer;

}

float *crossProduct(float *firstVector, float flength, float *secondVector, float slength) {

        int sf = flength; // sizeof(firstVector);
        int ss = slength; //sizeof(secondVector);

        float answer[3];
        if(sf != ss && sf != 3){
                printf("No solution\n");
                float *an = answer;
                return an;
        }
        answer[0] = firstVector[2]*secondVector[3] - secondVector[2]*firstVector[3];
        answer[1] = -(firstVector[1]*secondVector[3] - secondVector[1]*firstVector[3]);
        answer[2] = firstVector[1]*secondVector[2] - secondVector[1]*firstVector[2];

        float *ans = answer;
        return ans;
}
int main() {

        float array1[] = {1,2,3};
        float array2[] = {4,5};
	float array3[] = {4,5,6};
        printf("this is a dot product: %9.5f\n", dotProduct(array1, 3, array2, 2));

        float *c = crossProduct(array1, 3, array2, 2);
        for(int i = 0; i < 3; i++) {
        printf("%9.5f\n", c[i]);
        }
        
        printf("\nSecond test:\n Dot product: %9.5f\n", dotProduct(array1, 3, array3, 3));

        float *b = crossProduct(array1, 3, array3, 3);
        for(int i = 0; i < 3; i++) {
                printf("%9.5f\n", b[i]);
        }


        return 0;
}



