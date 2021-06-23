#!/bin/bash
gcc -g -D$1 main.c list.c list_operate.c -o list
