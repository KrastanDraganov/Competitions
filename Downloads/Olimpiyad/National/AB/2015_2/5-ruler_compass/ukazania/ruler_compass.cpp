#include <cmath>

// Provided functions.
//
void done(int id);
void define_line(int ida, int idb);
void define_circle(int idc, int idr1, int idr2);
int intersect(int &id1, double &x1, double &y1, int &id2, double &x2, double &y2);
//
// End of provided functions.
//

void go(double tarx, double tary) {
  int id1, id2;
  double x1, y1, x2, y2;
  define_line(0, 1);
  define_circle(0, 0, 1);
  intersect(id1, x1, y1, id2, x2, y2);
  done(3);
}
