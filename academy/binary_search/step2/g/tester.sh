

g++ sol.cpp -o sol
g++ random.cpp -o random

for ((i=1; $i <= $1 ; ++i)); do
  ./random $i > input.txt
  ./sol >output.txt 2>error.txt
  echo "Test case #"$i
  cat input.txt
  echo "Output: "
  cat output.txt
  echo "Execution time: "
  cat error.txt
done
