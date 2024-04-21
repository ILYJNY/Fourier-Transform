#!/bin/bash
git init
git add .
echo "Enter the commit(if you want automatically, type \"Auto\")"
read input_commit
if [ ${input_commit} = "Auto" ] ; then
  git commit -m "$(date) Up-to-Date"
else
  git commit -m "${input_commit}"
fi
git remote add FT "https://github.com/ILYJNY/Fourier-Transform.git"
git push FT +master
pause