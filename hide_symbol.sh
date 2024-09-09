#!/bin/sh

i=0

echo "lets hide symbol from $1"
rm -f *.o *.obj *.c.obj

files=$(ar t "$1")

ar xv "$1"

for f in $files; do
  if [ -f "$f" ]; then
    echo "Hide symbol in function $f"
    strip -d -S -x "$f"

    extension="${f##*.}"

    new_name="private_sklock$i.$extension"
    mv "$f" "$new_name"
    i=$((i+1))
  else
    echo "File $f not found."
  fi
done

rm -f "$1"
echo "generating new library $1..."
ar crs "$1" private_sklock*.*
rm -f *.o *.obj *.c.obj
