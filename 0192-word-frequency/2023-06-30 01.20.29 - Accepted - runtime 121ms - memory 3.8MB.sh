# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s [:blank:] '\n' | tr -d [:punct:] | sort | uniq -c | sort -nr -k 1 | awk '{print $2, $1}'
