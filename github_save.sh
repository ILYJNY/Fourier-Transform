#!/bin/bash
git init
git add .
echo "Enter the commit(if you want automatically, type \"Auto\")"
read input_commit
if [ ${input_commit} = "Auto" ] ; then
  git commit -m "$(date) Up-to-Date"
else
  git commit -m "${input_comit}"
fi
echo "Enter the git repos(if you want automatically, type \"Auto\""
read input_repos
git remote add origin "${input_repos}"
git push origin +master