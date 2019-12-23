#!/bin/bash

NAME=ruler_compass

/usr/bin/g++ -DEVAL -static -O2 -o $NAME contestant_grader.cpp $NAME.cpp

