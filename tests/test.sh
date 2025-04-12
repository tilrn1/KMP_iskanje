#!/bin/bash

output=$(./Vaja2.exe 0 "Lorem ipsum" ../test.txt)

diff -w out.txt tests/test_expected.txt

if [ $? -eq 0 ]; then
  echo "Test uspešen"
  exit 0
else
  echo "Test neuspešen"
  exit 1
fi
