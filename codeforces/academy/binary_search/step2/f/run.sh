g++ brute.cpp -o brute -DONLINE_JUDGE
g++ random.cpp -o random

for ((i=1; ; ++i)); do
  ./random $i > random_input.txt
  ./brute <random_input.txt > brute_output.txt 
  echo "Test: "
  cat random_input.txt
  echo "Output: "
  cat brute_output.txt
done
