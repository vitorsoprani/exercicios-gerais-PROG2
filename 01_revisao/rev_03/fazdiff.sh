gcc rev_03.c -o teste -lm

echo "TESTE 1:"
./teste < input/test_1 > output/out_1
diff output/out_1 output/test_1 --color -u

echo "TESTE 2:"
./teste < input/test_2 > output/out_2
diff output/out_2 output/test_2 --color -u

echo "TESTE 3:"
./teste < input/test_3 > output/out_3
diff output/out_3 output/test_3 --color -u

echo "TESTE 4:"
./teste < input/test_4 > output/out_4
diff output/out_4 output/test_4 --color -u

echo "TESTE 5:"
./teste < input/test_5 > output/out_5
diff output/out_5 output/test_5 --color -u

echo "TESTE 6:"
./teste < input/test_6 > output/out_6
diff output/out_6 output/test_6 --color -u

echo "TESTE 7:"
./teste < input/test_7 > output/out_7
diff output/out_7 output/test_7 --color -u

echo "TESTE 8:"
./teste < input/test_8 > output/out_8
diff output/out_8 output/test_8 --color -u

echo "TESTE 9:"
./teste < input/test_9 > output/out_9
diff output/out_9 output/test_9 --color -u

echo "TESTE 10:"
./teste < input/test_10 > output/out_10
diff output/out_10 output/test_10 --color -u

rm teste