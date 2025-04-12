#!/bin/bash

output=$(./KMP 0 "Lorem ipsum" tests/test_input.txt)

diff -w out.txt tests/test_expected.txt

if [ $? -eq 0 ]; then
  echo "Test uspešen"
  exit 0
else
  echo "Test neuspešen"
  exit 1
fi
