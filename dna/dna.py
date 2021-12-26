import csv
import sys

def main():
     # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py CSV_FILE TXT_FILE")
    
    with open(sys.argv[2], 'r') as file:
        lines = file.read()
    
    dna = []
    match = False

    with open(sys.argv[1], 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            names = row.pop('name')
            for k, v in row.items():
                v = int(v)
                dna.append(v)
            if dna == compute(row, lines):
                match = True
                print(names)
            dna = []
        
        if match == False:
            print(f"No match")
            
    
# Computing part: How many times DNA sequences appear after each other
def compute(strs, dna_sequence):
    counter = 0
    longest = []
    for k, v in strs.items():
        strs = k        
        while strs in dna_sequence:
            counter += 1
            strs = strs + k
        longest.append(counter)
        counter = 0  
    return longest


if __name__ == "__main__":
    main()
