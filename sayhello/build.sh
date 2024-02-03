#!/bin/sh

protoc-c --c_out=. hello_world.proto
gcc -Wall -Wextra -std=c17 -pedantic -lprotobuf-c -o sayhello sayhello.c hello_world.pb-c.c
