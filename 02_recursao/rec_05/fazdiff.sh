gcc rec_05.c -o teste

echo "TESTE 1:"
./teste <input/test_1.txt >output/out_1
diff output/out_1 output/test_1.txt --color -u

echo "TESTE 2:"
./teste <input/test_2.txt >output/out_2
diff output/out_2 output/test_2.txt --color -u

echo "TESTE 3:"
./teste <input/test_3.txt >output/out_3
diff output/out_3 output/test_3.txt --color -u

echo "TESTE 4:"
./teste <input/test_4.txt >output/out_4
diff output/out_4 output/test_4.txt --color -u
