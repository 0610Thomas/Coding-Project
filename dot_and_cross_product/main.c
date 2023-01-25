#include <stdio.h>


float dotProduct(float *firstVector, float *secondVector) {

        float answer = 0;
        float sf = sizeof(firstVector);
        float ss = sizeof(firstVector);
        if(sf != ss){
                return 0;
        }

        for(int i = 0; i < 3; i++) {
                answer += firstVector[i] * secondVector[i];
        }

        return answer;

}

float *crossProduct(float *firstVector, float *secondVector) {

        float sf = sizeof(firstVector);
        float ss = sizeof(secondVector);
        if(sf != ss && sf != 3){
                return 0;
        }

        float answer[3];
        answer[0] = firstVector[2]*secondVector[3] - secondVector[2]*firstVector[3];
        answer[1] = -(firstVector[1]*secondVector[3] - secondVector[1]*firstVector[3]);
        answer[2] = firstVector[1]*secondVector[2] - secondVector[1]*firstVector[2];

        float *ans = answer;
        return ans;
}
int main() {

        float array1[] = {1,2,3};
        float array2[] = {4,5,6};
        printf("%9.5f\n", dotProduct(array1, array2));

        float *c = crossProduct(array1, array2);
        for(int i = 0; i < 3; i++) {
                printf("%9.5f\n", c[i]);
        }

        return 0;
}
