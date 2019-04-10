#!/bin/bash

GCC="g++ -fpermissive"
AR="ar crv"

rm -f *.o *.a
$GCC -c lib.cpp
