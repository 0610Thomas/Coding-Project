#include <stdio.h>
#include <stdlib.h>

typedef struct vector3d
{
    float x, y, z;
} vector3d;

float dotProduct(vector3d v1, vector3d v2) {

        float answer = 0.0;

        answer += v1.x * v2.x;
        answer += v1.y * v2.y;
        answer += v1.z * v2.z;

        return answer;
}


vector3d crossProduct(vector3d v1, vector3d v2) {

        vector3d ans = {0, 0, 0};
        ans.x = v1.y * v2.z - v2.y * v1.z;
        ans.y = -1*(v1.x * v2.z - v2.x * v1.z);
        ans.z = v1.x * v2.y - v2.x * v1.y;
        return ans;
}
int main() {

        vector3d array1 = {1,2,3};
        vector3d array2 = {4,5};
        vector3d array3 = {4,5,6};
        printf("this is a dot product: %9.5f\n", dotProduct(array1, array3));

        vector3d an = crossProduct(array1, array3);
        printf("Cross: %f\n%f\n%f\n", an.x, an.y, an.z);


        /*
        printf("Second test:\nDot product: %9.5f\n", dotProduct(array1, array2));

        vector3d a = crossProduct(array1, array2);
        printf("Cross: %f\n%f\n%f\n", a.x, a.y, a.z);
        */
        return 0;
}



