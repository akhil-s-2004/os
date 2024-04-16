#!/bin/bash
echo "Enter filename: "
read filename
echo "Enter word to be searched: "
read word
count=$(grep -c "\<$word\>" "$filename")
words=$(wc -w < "$filename")
echo "Total number of words: $words"
if [ $count != 0 ]
then
        echo "$word is present in the file"
        echo "Number of $word = $count"
else
        echo "$word not present in the file"
fi
