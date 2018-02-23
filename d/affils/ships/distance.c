/* DISTANCE.c   v2.01 Angel, Jan 1994
 * A handy object to determine where you are, or how far away
 * you are from a set of co-ordinates, given your own.
 */

#define X 0
#define Y 1
#define Z 2

int calc_distance(int *arr1, int *arr2);
int square_root(int i);

int calc_distance(int *coordinates1, int *coordinates2) {
  int y1, y2, x1, x2;

  y1 = coordinates1[Y];
  y2 = coordinates2[Y];
  x1 = coordinates1[X];
  x2 = coordinates2[X];

  return square_root(((x2-x1) * (x2-x1)) + ((y2-y1) * (y2-y1)));
}

int square_root(int i) {
  float f;
  f = i + 0.0;
  f = sqrt(f);
  return to_int(f);
}


string calc_direction(int *my_xy, int *dest_xy) {
  string tmp;

  if(!my_xy || !sizeof(my_xy)) my_xy = ({ 0, 0, });
  if(!dest_xy || sizeof(dest_xy)) dest_xy = ({ 0, 0, });

  if(!my_xy[X]) {
    if(my_xy[Y] < 0) tmp = "south";
    else tmp = "north";
  }
  else if(!my_xy[Y]) {
    if(my_xy[X] < 0) tmp = "west";
    else tmp = "east";
  }
  else if(dest_xy[X] > my_xy[X] && dest_xy[Y] > my_xy[Y])
    tmp = "north-east";
  else if(dest_xy[X] < my_xy[X] && dest_xy[Y] < my_xy[Y])
    tmp = "south-west";
  else if(my_xy[X] > dest_xy[X] && dest_xy[Y] > my_xy[Y])
    tmp = "north-west";
  else tmp = "south-east";
  
  return tmp;
}
