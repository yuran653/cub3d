#!/bin/bash

BINARY="./cub3d"

COUNTER=0

while true; do

  let COUNTER=COUNTER+1
  echo "Iteration $COUNTER"

  # Run binary and capture exit code
  $BINARY
  RC=$?

  # Check for segfault
  if [ $RC -eq 139 ]; then
    echo "Segmentation fault occurred - stopping loop" 
    break
  fi

  sleep 1

done