#!/bin/bash

BINARY="/path/to/binary"

COUNTER=0

while true; do

  let COUNTER=COUNTER+1
  echo "Iteration $COUNTER"

  # Run binary and get exit code
  $BINARY
  RC=$?

  # Check for segfault
  if [ $RC -eq 139 ]; then
    echo "Segmenation fault occurred - stopping loop" 
    break

  # Check for any failure exit code
  elif [ $RC -ne 0 ]; then
    echo "Binary failed with code $RC - stopping loop"
    break

  fi

  sleep 1

done