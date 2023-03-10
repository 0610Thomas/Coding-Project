
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct vector3d
{
    float x, y, z;
        //limitation is that vector will always be 3d
} vector3d;


vector3d projection(vector3d fvector, vector3d svector) {

        float v1n = sqrt(pow(fvector.x, 2) + pow(fvector.y, 2) + pow(fvector.z, 2));
        float v2n = sqrt(pow(svector.x, 2) + pow(svector.y, 2) + pow(svector.z, 2));
        float v2d = pow(v2n, 2);

        float ans = ((v1n * v2n) / v2d);

        vector3d an = svector;
        an.x *= ans;
        an.y *= ans;
        an.z *= ans;

        return an;

}

vector3d perpendicular(vector3d fvector, vector3d svector) {

        vector3d an = projection(fvector, svector);
        vector3d ans = fvector;
        ans.x -= an.x;
        ans.y -= an.y;
        ans.z -= an.z;

        return ans;
}


int main() {

        vector3d v1 = {1,2,3};
        vector3d v2 = {4,5,6};
        vector3d v3 = {1,1,1};

        vector3d a = projection(v1, v2);
        printf("this is a projection: %f\n%f\n%f\n", a.x, a.y, a.z);

        vector3d an = perpendicular(v1, v2);
        printf("Perp: %f\n%f\n%f\n", an.x, an.y, an.z);


        vector3d ans = projection(v1, v3);
        printf("Second test:\nProjection: %f\n%f\n%f\n", ans.x, ans.y, ans.z);

        vector3d answ = perpendicular(v1, v3);
        printf("Perp: %f\n%f\n%f\n", answ.x, answ.y, answ.z);

        return 0;
}
