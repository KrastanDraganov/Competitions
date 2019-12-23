// Solution that generates integers and approximates
// answer with division.
//

#include <utility>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

// Provided functions.
//
int getSteps();
void done(int id);
void define_line(int ida, int idb);
void define_circle(int idc, int idr1, int idr2);
int intersect(int &id1, double &X1, double &Y1, int &id2, double &X2, double &Y2);
//
// End of provided functions.
//

const double eps = 1e-7;

double dist(std::pair<double, double> a, std::pair<double, double> b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
              (a.second - b.second) * (a.second - b.second));
}

vector< std::pair<double, double> > points;

int id1, id2;
double X1, Y1, X2, Y2;

int handleIntersect() {
  int num = intersect(id1, X1, Y1, id2, X2, Y2);
  if (num == 1) {
    points.push_back(std::make_pair(X1, Y1));
  } else if (num == 2) {
    if (id1 == points.size()) {
      points.push_back(std::make_pair(X1, Y1));
      points.push_back(std::make_pair(X2, Y2));
    } else {
      points.push_back(std::make_pair(X2, Y2));
      points.push_back(std::make_pair(X1, Y1));
    }
  }
  return num;
}

int pow2[32];
int npow2[32];

inline int bitcount(int v) {
  return __builtin_popcount(v);
}

// Generate number on X axis. Use map for speed-up?
//
int genInt(int v) {
  int togen = 0;
  if (v == 0) {
    return 0;
  }
  int b = bitcount(v);
  int k = 0;
  while ((1 << k) < v) {
    ++k;
  }
  if (v == (1 << k)) {
    return pow2[k];
  }
  int l;
  if ((b + 1) / 2 <= 1 + (k - b + 1) / 2) {
    // Sum up parts.
    //
    l = 0;
    int lb = -1;
    for (int i = 0; i < k; ++i) {
      if (v & (1 << i)) {
        if (lb == -1) {
          lb = i;
          continue;
        }
        define_line(0, 1);
        define_circle(l, pow2[i], npow2[lb]);
        handleIntersect();
        lb = -1;
        // I'm generating 2 more points that can be added to map.
        //
        if (X1 > X2) {
          l = id1;
        } else {
          l = id2;
        }
      }
    }
    if (lb != -1) {
      define_line(0, 1);
      define_circle(l, pow2[lb], 0);
      handleIntersect();
      if (X1 > X2) {
        l = id1;
      } else {
        l = id2;
      }
    }
  } else {
    l = pow2[k];
    define_line(0, 1);
    define_circle(pow2[k], 0, 1);
    handleIntersect();
    ++togen;
    if (X1 < X2) {
      l = id1;
    } else {
      l = id2;
    }
    int lb = -1;
    for (int i = 0; i < k; ++i) {
      if (!(v & (1 << i))) {
        if (lb == -1) {
          lb = i;
          continue;
        }
        define_line(0, 1);
        define_circle(l, npow2[lb], pow2[i]);
        handleIntersect();
        lb = -1;
        ++togen;
        // Add points to map here as well!
        //
        if (X1 < X2) {
          l = id1;
        } else {
          l = id2;
        }
      }
    }
    if (lb != -1) {
      define_line(0, 1);
      define_circle(l, pow2[lb], 0);
      handleIntersect();
      if (X1 < X2) {
        l = id1;
      } else {
        l = id2;
      }
    }
  }
  return l;
}

int up;

int moveUp(int a) {
  int ia;
  define_line(0, up);
  define_circle(0, 0, a);
  handleIntersect();
  if (Y1 > Y2) {
    ia = id1;
  } else {
    ia = id2;
  }
  return ia;
}

void printPoint(const char *s, int k) {
  printf("%s %d %lf %lf\n", s, k, points[k].first, points[k].second);
}

// Generates a / b. This has higher precision than usual.
//
int divideLength(int a, int b) {
  if (dist(points[a], points[0]) < eps) {
    return 0;
  }
  int ia = moveUp(a);
  int ib = b;
  define_circle(ia, ia, 1);
  define_line(ia, ib);
  handleIntersect();
  int e;
  if (X1 > X2) {
    e = id1;
  } else {
    e = id2;
  }
  define_circle(1, ia, 1);
  define_circle(e, ia, 1);
  handleIntersect();
  int t;
  if (dist(points[id1], points[ia]) > dist(points[id2], points[ia])) {
    t = id1;
  } else {
    t = id2;
  }
  define_line(1, t);
  define_line(0, up);
  handleIntersect();
  return id1;
}

void go(double tarx, double tary) {
  pair<double, double> tar(tarx, tary);
  points.push_back(std::make_pair(0, 0));
  points.push_back(std::make_pair(1, 0));

  define_line(0, 1);
  define_circle(0, 0, 1);
  handleIntersect();
  if (X1 < X2) {
    npow2[0] = id1;
    pow2[0] = id2;
  } else {
    npow2[0] = id2;
    pow2[0] = id1;
  }
  for (int i = 1; i <= 14; ++i) {
    define_line(0, 1);
    define_circle(0, pow2[i - 1], npow2[i - 1]);
    handleIntersect();
    if (X1 < X2) {
      npow2[i] = id1;
      pow2[i] = id2;
    } else {
      npow2[i] = id2;
      pow2[i] = id1;
    }
  }

  // Now generate up.
  //
  define_circle(npow2[1], npow2[1], pow2[1]);
  define_circle(pow2[1], npow2[1], pow2[1]);
  handleIntersect();
  if (Y1 > Y2) {
    up = id1;
  } else {
    up = id2;
  }

  // No smart division tricks for now. Closer to worst case.
  // tarx = a + b/c
  int a, b, c;
  a = (int) (tarx + eps);
  double rest = tarx - a;
  c = (1 << 14);  // No need to gen twice!
  b = (int) (rest * c + eps);
  int ia = genInt(a);
  int ib = genInt(b);
  int ic = genInt(c);
  int ibc = divideLength(ib, ic);
  int p;
  if (ibc != 0) {
    // Please don't define circles of radius 0.
    //
    define_line(0, 1);
    define_circle(ia, 0, ibc);
    handleIntersect();
    if (X1 > X2) {
      p = id1;
    } else {
      p = id2;
    }
  } else {
    p = ia;
  }

  a = (int) (tary + eps);
  rest = tary - a;
  b = (int) (rest * c + eps);
  ia = genInt(a);
  ib = genInt(b);
  ibc = divideLength(ib, ic);
  int q;
  if (ibc != 0) {
    define_line(0, 1);
    define_circle(ia, 0, ibc);
    handleIntersect();
    if (X1 > X2) {
      q = id1;
    } else {
      q = id2;
    }
  } else {
    q = ia;
  }
  if (q == 0) {
    done(p);
  }

  int u;
  if (dist(points[p], points[0]) > eps) {
    define_circle(p, 0, up);
    define_circle(up, 0, p);
    handleIntersect();
    if (Y1 > Y2) {
      u = id1;
    } else {
      u = id2;
    }
  } else {
    u = up;
  }
  define_line(p, u);
  define_circle(p, 0, q);
  handleIntersect();
  if (Y1 > Y2) {
    done(id1);
  } else {
    done(id2);
  }
  return;
}
