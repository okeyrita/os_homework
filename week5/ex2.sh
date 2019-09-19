#!/bin/bash
for ((i=0;i<9;i++)); do
  in=$(tail -1 counter)
  expr 1 + $in >> counter
done