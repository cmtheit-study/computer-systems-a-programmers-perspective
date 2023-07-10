#!/bin/bash

for ((i = 60; i <= 97; ++i)) do
  mkdir -p $i
  echo '#include "../show_bytes.h"

int main() {

}
  ' > $i/main.c
done