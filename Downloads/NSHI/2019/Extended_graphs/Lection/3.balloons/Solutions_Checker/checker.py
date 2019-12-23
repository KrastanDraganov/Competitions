#!/usr/bin/env python2

from __future__ import print_function
import sys


class Dest(object):
    def __init__(self, to, dist, parent=None):
        self.to = to
        self.dist = dist
        self.parent = parent

    def __lt__(self, other):
        return self.dist < other.dist


def safe_int(s):
    for c in s:
        if not c.isdigit():
            raise ValueError("non-digit %s while parsing %s as safe_int" %
                             (c, s))
    return int(s)


def safe_nlstrip(s):
    if not s:
        raise ValueError("s is empty")
    if s[-1] != '\n':
        raise ValueError("s doesn't end in newline")
    return s[:-1]


class Path(object):
    def __init__(self, graph):
        self.graph = graph
        self.msg = None

    def init_from_input(self, inp):
        try:
            self.dist = safe_int(safe_nlstrip(inp.readline()))
            self.length = safe_int(safe_nlstrip(inp.readline()))
            self.nodes = map(safe_int, safe_nlstrip(inp.readline()).split(' '))
        except:
            self.msg = "Output Format"

    def check(self):
        if self.msg:
            return self.msg

        if len(self.nodes) != self.length:
            return "Wrong number of nodes"

        for n in self.nodes:
            if n < 1 or n > graph.N:
                return "Wrong node in path"

        self.nodes = map(lambda n: n - 1, self.nodes)

        total_path_dist = 0
        for i in xrange(self.length - 1):
            n1 = self.nodes[i]
            n2 = self.nodes[i+1]
            dist = graph.get_dist(n1, n2)
            if dist is None:
                return "No edge between %s and %s" % (n1 + 1, n2 + 1)
            total_path_dist += dist

        K = self.graph.K
        # iterate over border controls
        for i in xrange(self.length):
            # collect last K + 1 (at most) colors
            colors = [self.graph.get_color(self.nodes[j])
                      for j in xrange(max(i - K, 0), i + 1)]
            if len(set(colors)) != len(colors):
                return ("Caught at border %d (#%d)" %
                        (self.nodes[i] + 1, i))

        if total_path_dist != self.dist:
            return "Path distance mismatch"

        return None


class Graph(object):
    def init_from_input(self, inp=sys.stdin):
        [self.N, self.M] = map(int, inp.readline().split())
        [self.C, self.K] = map(int, inp.readline().split())
        [self.start, self.end] = map(int, inp.readline().split())

        self.start -= 1
        self.end -= 1

        self.colors = []
        for i in xrange(self.N):
            self.colors.append(int(inp.readline()))

        self.nl = [[] for i in xrange(self.N)]
        self.edges = {}
        for i in xrange(self.M):
            [a, b, c] = map(int, inp.readline().split())
            a -= 1
            b -= 1

            self.nl[a].append(Dest(b, c))
            self.edges[self._mkpair(a, b)] = c

    def get_color(self, n):
        return self.colors[n]

    def get_dist(self, u, v):
        return self.edges.get(self._mkpair(u, v))

    @staticmethod
    def _mkpair(a, b):
        res = [a, b]
        res.sort()
        return tuple(res)


if __name__ == '__main__':
    inp = sys.argv[1]
    out = sys.argv[2]
    sol = sys.argv[3]


    with open(inp, 'r') as inpf:
        graph = Graph()
        graph.init_from_input(inpf)

    actual_dist = None
    with open(out, 'r') as outf:
        path = Path(graph)
        path.init_from_input(outf)
        msg = path.check()
        if msg:
            print("0")
            print(msg)
            sys.exit(0)

        actual_dist = path.dist

    expected_dist = None
    with open(sol, 'r') as solf:
        path = Path(graph)
        path.init_from_input(solf)
        msg = path.check()
        if msg:
            print("WTF wrong solution: %s" % msg, file=sys.stderr)
            sys.exit(1)

        expected_dist = path.dist

    if expected_dist != actual_dist:
        print("0")
        print("Shorter path exists")
    else:
        print("1")
        print("OK")
