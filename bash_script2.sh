touch stat.txt
echo "1. Before fork()\n">>stat.txt
top >> stat.txt
gcc -o fork fork.c
./fork
echo "2. After fork()\n">>stat.txt
top >> stat.txt
