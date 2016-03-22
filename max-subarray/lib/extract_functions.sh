#!/bin/bash

cat src/main.cpp | sed -e '/^int.*main.*(.*)/, /^}$/d' > src/functions.cpp
