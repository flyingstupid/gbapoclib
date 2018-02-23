/* RELATIVE BEARING
 * Returns the result of a comparison between this object, and another obejct
 * in terms of 'degrees, mark elevation'. Degree measurements are in a clock
 * wise direction; i.e. front, right, back, left. Elevation is in an anti-
 * clock wise direction; i.e. front, top, back, below.
 */

#define R_TO_D		57.29577951
#define X           0
#define Y           1
#define Z           2



mixed *relative_bearing(int *coordinates1, int coordinates2);
int calc_direction(int *coordinates1, int *coordinates2);
int calc_elevation(int *coordinates1, int *coordinates2);

int x1, y1, z1, x2, y2, z2;


mixed *relative_bearing(int *coordinates1, int *coordinates2) {
  int direction, elevation;
  direction = calc_direction(coordinates1, coordinates2);
  elevation = calc_elevation(coordinates1, coordinates2);
  return ({ direction, elevation, });
}

int calc_direction(int *coordinates1, int *coordinates2) {
  float result;

  x1 = coordinates1[X];
  y1 = coordinates1[Y];
  x2 = coordinates2[X];
  y2 = coordinates2[Y];

  if(x2>x1 && y2>y1)
    result = atan(to_float((x2-x1)/(y2-y1)));
  else if(x2>x1 && y2<y1)
    result = atan(to_float((y2-y1)/(x2-x1)) + 90/R_TO_D);
  else if(x2<x1 && y2<y1)
    result = atan(to_float((x1-x2)/(y1-y2)) + 180/R_TO_D);
  else 
   result = atan(to_float((y2-y1)/(x1-x2)) + 270/R_TO_D);
  result = result * R_TO_D;
  return to_int(result);
}

int calc_elevation(int *coordinates1, int *coordinates2) {
  float result;

  z1 = coordinates1[Z];
  y1 = coordinates1[Y];
  z2 = coordinates2[Z];
  y2 = coordinates2[Y];

  if(z2>z1 && y2>y1)
    result = atan(to_float((y2-y1)/(z2-z1)));
  else if(z1>z2 && y2>y1)
    result = atan(to_float((z1-z2)/(y2-y1)) + 90/R_TO_D);
  else if(z1>z2 && y1>y2)
    result = atan(to_float((y1-y2)/(z1-z2)) + 180/R_TO_D);
  else
    result = atan(to_float((z2-z1)/(y1-y2)) + 270/R_TO_D);
  result = result * R_TO_D;
  return to_int(result);
}
