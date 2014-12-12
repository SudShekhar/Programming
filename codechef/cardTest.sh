python cardtest.py > in
g++ sagarCard.cpp -o ref
./ref < in > o1
g++ cardinal.cpp -o me
./me < in > o2
diff o1 o2 > results
