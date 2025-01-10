#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "u_template.h"

int double_area(struct triangle_t tr){

int s = tr.pts[0].x * tr.pts[1].y * 1 
    + tr.pts[0].y * 1 * tr.pts[2].x 
    + 1 * tr.pts[1].x * tr.pts[2].y
    - tr.pts[0].x * 1 * tr.pts[2].y
    - tr.pts[0].y * tr.pts[1].x * 1
    - 1 * tr.pts[1].y *tr.pts[2].x ; 
    
    return abs(s);
}

int main() {
    struct triangle_t tr;
    int s = 0;
    int res;
    res = scanf("%d%d%d%d%d%d", &tr.pts[0].x, &tr.pts[0].y,  //1
                                &tr.pts[1].x, &tr.pts[1].y,  //1
                                &tr.pts[2].x, &tr.pts[2].y );//1
    assert(res == 6);
    //-3 -10 8 8 6 -2 
    s = double_area(tr);

    printf("%d", s);
    return 0;
} 
