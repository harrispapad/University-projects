import sys

with open(sys.argv[1], 'r') as f:
    size = int(f.readline().strip())  # Convert size to an integer
    numbers = f.readline()
    seq = [int(num) for num in numbers.split()]

total_count = 0

for i in range(size):
    total_count += seq[i]

k = 1
j = 1
sub_seq = seq[1]
min = 1000000

while(k != size):
    diff = abs(total_count - 2*sub_seq)
    if (diff < min):
        min = diff

    if (k == j):
        if(k == (size - 1)): break
        j += 1
        sub_seq += seq[j]

    elif (j >= (size - 1) or sub_seq >= (total_count - sub_seq)):
           sub_seq -= seq[k]
           k += 1

    else:
           j += 1
           sub_seq += seq[j]

print(min)
